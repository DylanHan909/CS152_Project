    /* cs152-miniL phase2 */
%{
 #define YY_NO_UNPUT
 #include <stdio.h>
 #include <stdlib.h>
 #include <map>
 #include <set>
 #include <string.h>
 #include <iostream>
 #include <sstream>
 #include <algorithm>
 using namespace std;

 int tempCount = 0;
 int labelCount = 0;
 string newTemp();
 string newLabel();

 map<string, string> tempVars;
 map<string, int> arrSize;
 bool mainFunc = false;

 set<string> funcs;
 set<string> reserved = {"FUNCTION", "BEGIN_PARAMS", "END_PARAMS", "BEGIN_LOCALS", "END_LOCALS", "BEGIN_BODY", "END_BODY", "INTEGER",
    "ARRAY", "OF", "IF", "THEN", "ENDIF", "ELSE", "WHILE", "DO", "FOREACH", "IN", "BEGINLOOP", "ENDLOOP", "CONTINUE", "READ", "WRITE", "AND", "OR", 
    "NOT", "TRUE", "FALSE", "RETURN", "SUB", "ADD", "MULT", "DIV", "MOD", "EQ", "NEQ", "LT", "GT", "LTE", "GTE", "L_PAREN", "R_PAREN", "L_SQUARE_BRACKET",
    "R_SQUARE_BRACKET", "COLON", "SEMICOLON", "COMMA", "ASSIGN", "function", "Ident", "beginparams", "endparams", "beginlocals", "endlocals", "integer", 
    "beginbody", "endbody", "beginloop", "endloop", "if", "endif", "foreach", "continue", "while", "else", "read", "do", "write"};
 void yyerror(const char *msg);
 extern int currLine;
 extern int currPos;
 extern FILE * yyin;
 extern char* yytext;
 int yylex();
%}

%union{
  char * iVal;
  int nVal;

  struct S{
    char * code;
  } statement;

  struct E{
    char * place;
    char * code;
    bool isArr;
  } expression;
}

%error-verbose
%locations

%type <expression> Ident IDENTIFIER_LOOP FUNC_IDENTIFIER
%type <expression> FUNCTIONS FUNCTION_LOOP DECLARATION DECLARATION_LOOP VAR VAR_LOOP
%type <expression> EXPRESSION EXPRESSION_LOOP MULTIPLICATIVE_EXPR TERM BOOL-EXPR RELATION-EXPR RELATION-AND-EXPR  COMP
%type <statement> STATEMENT STATEMENT_LOOP ELSE_BRANCH

/* %start program */
%start PROGRAM
%token FUNCTION BEGIN_PARAMS END_PARAMS BEGIN_LOCALS END_LOCALS BEGIN_BODY END_BODY INTEGER ARRAY ENUM OF IF THEN ENDIF ELSE FOR WHILE DO BEGINLOOP ENDLOOP CONTINUE READ WRITE AND OR NOT TRUE FALSE RETURN
%token SUB "-" ADD "+" MULT "*" DIV "/" MOD "%"
%token EQ "=" NEQ "!=" LT "<" GT ">" LTE "<=" GTE ">="
%token <iVal> IDENT
%token <nVal> NUMBER
%token SEMICOLON ";" COLON ":" COMMA "," L_PAREN "(" R_PAREN ")" L_SQUARE_BRACKET "[" R_SQUARE_BRACKET "]" ASSIGN ":="
%left OR AND
%left EQ NEQ LT GT LTE GTE
//Precedence Update
%left ADD SUB
%left MULT DIV MOD
%left L_SQUARE_BRACKET R_SQUARE_BRACKET
%left L_PAREN R_PAREN 
%left ASSIGN

%nonassoc UMINUS
%right NOT

%% 
  /* write your rules here */
  //Program
  PROGRAM: FUNCTION_LOOP 
      {
        printf("%s", $1.code);
      } 
  ;
  //Function
  FUNCTION_LOOP: FUNCTIONS FUNCTION_LOOP 
      {
        string temp;
        temp.append($1.code);
        temp.append($2.code);
        //The strdup() and strndup() functions are used to duplicate a string. 
        $$.code = strdup(temp.c_str());
      } 
      | %empty
      {
        if (!mainFunc) {
          printf("** Line %d, position %d: No Main Function Found.\n", currLine, currPos);
        }
        $$.code = strdup("");
        $$.place = strdup("");
      } 
  ;
  FUNC_IDENTIFIER: Ident 
      {
        if (funcs.find($1.place) != funcs.end()) {
          printf("This function name is already declared: %s .\n", $1.place);
        } 
        else {
          funcs.insert($1.place);
        }
        $$.place = strdup($1.place);
        $$.code = strdup("");
    }
  ;
  FUNCTIONS: FUNCTION FUNC_IDENTIFIER SEMICOLON BEGIN_PARAMS DECLARATION_LOOP END_PARAMS BEGIN_LOCALS DECLARATION_LOOP END_LOCALS BEGIN_BODY STATEMENT_LOOP END_BODY 
      {
        string temp = "func ";
        
        temp.append($2.place);
        temp.append("\n");
        string s = $2.place;
        if (s == "main") {
          mainFunc = true;
        }
        temp.append($5.code);
        string decs = $5.code;
        int decNum = 0;
        while (decs.find(".") != string::npos) {
          int pos = decs.find(".");
          decs.replace(pos, 1, "=");
          string part = ", $" + to_string(decNum) + "\n";
          decNum++;
          decs.replace(decs.find("\n", pos), 1, part);
        }
        temp.append(decs);

        temp.append($8.code);
        string statements = $11.code;
        if (statements.find("continue") != string::npos) {
          printf("** Line %d, position %d: This continue statement is not inside a loop: {%s}\n", currLine, currPos, $2.place);
        }
        temp.append(statements);
        temp.append("endfunc\n\n");
        printf("%s", temp.c_str());
      }
  ;
  //Identifier
  IDENTIFIER_LOOP: Ident 
      {
        $$.place = $1.place;
        $$.code = strdup("");
      } 
      | 
      Ident COMMA IDENTIFIER_LOOP 
      {
        string temp;
        temp.append($1.place);
        temp.append("/");
        temp.append($3.place);
        $$.place = strdup(temp.c_str());
        $$.code = strdup("");
      }
      ;
  Ident: IDENT 
      {
        $$.place = strdup($1);
        $$.code = strdup("");
      }
  DECLARATION: IDENTIFIER_LOOP COLON ARRAY L_SQUARE_BRACKET NUMBER R_SQUARE_BRACKET OF INTEGER 
      {
        int lPtr = 0;
        int rPtr = 0;
        string placeCpy = $1.place; 
        string temp;
        bool doneParse = false;
        while(!doneParse) {
          rPtr = placeCpy.find("/", lPtr); //Check if anything else was found after | to check for multiple identifiers
          temp.append(".[] "); //For our min file
          if (rPtr == string::npos) { //If nothing was found pretty much
            string ident = placeCpy.substr(lPtr, rPtr); //Set substring to what we find eventually for left and right
            if (funcs.find(ident) != funcs.end()) {
              printf("** Line %d, position %d: This function is used before it's definition: {%s}\n", currLine, currPos, ident.c_str());
            }
            if (tempVars.find(ident) != tempVars.end()) {   //Basically if the function inside the table is equal to the current one
                printf("** Line %d, position %d: This identifier is previously declared: {%s}\n", currLine, currPos, ident.c_str());
                
            } 
            if (reserved.find(ident) != reserved.end()) { //If the identity name we get from string parsing is not equal to ????
                printf("** Line %d, position %d: This identifier's name is a reserved word: {%s}\n", currLine, currPos, ident.c_str());
                
            }
            else {
              if ($5 <= 0) { //Checking if our number inside our array is 0 or less
                   printf("** Line %d, position %d: This array's size is less than or equal to 0: {%s}\n", currLine, currPos, ident.c_str());
                   
              }
              tempVars[ident] = ident;  //If something was find, put in our new identifier declaration into variable declaration table
              arrSize[ident] = $5; //Store our arrsize into our arrSize multiplicative
            }
            temp += ident + ", " + to_string($5) + "\n"; //Conform to output rules for declaration, ARRAY DECLARATION
            doneParse = true; //We're done if its an array so we dip
          } 
          else { //our string does have multiple identifiers 
            string ident = placeCpy.substr(lPtr, rPtr-lPtr); //set our substring to the very left, and to whee the last identifier is stored
            if (funcs.find(ident) != funcs.end()) {
              printf("** Line %d, position %d: This function is used before it's definition: {%s}\n", currLine, currPos, ident.c_str());
            }
            if (tempVars.find(ident) != tempVars.end()) {
                 printf("** Line %d, position %d: This identifier is previously declared: {%s}\n", currLine, currPos, ident.c_str());
              
            } 
            if (reserved.find(ident) != reserved.end()) { //same error handling as above
                 printf("** Line %d, position %d: This identifier's name is a reserved word: {%s}\n", currLine, currPos, ident.c_str());
              
            }
            
            else {
              if ($5 <= 0) {
                   printf("** Line %d, position %d: This array's size is less than or equal to 0: {%s}\n", currLine, currPos, ident.c_str());
                   
              }
              tempVars[ident] = ident;
              arrSize[ident] = $5;
            }
            temp += ", " + to_string($5) + "\n";
          }
        }
          
        $$.code = strdup(temp.c_str());
        $$.place = strdup("");
      } 
      | IDENTIFIER_LOOP COLON INTEGER 
      {
        int lPtr = 0;
        int rPtr = 0;
        string placeCpy = $1.place; 
        string temp;
        bool doneParse = false;
        while (!doneParse) {
          rPtr = placeCpy.find("/", lPtr);
          temp.append(". ");
          if (rPtr == string::npos) {
           string ident = placeCpy.substr(lPtr, rPtr);
           if (funcs.find(ident) != funcs.end()) {
              printf("** Line %d, position %d: This function is used before it's definition: {%s}\n", currLine, currPos, ident.c_str());
            }
           if (tempVars.find(ident) != tempVars.end()) {
                printf("** Line %d, position %d: This identifier is previously declared: {%s}\n", currLine, currPos, ident.c_str());
                
            } 
            if (reserved.find(ident) != reserved.end()) {
                printf("** Line %d, position %d: This identifier's name is a reserved word: {%s}\n", currLine, currPos, ident.c_str());
                
            }
            else {
              tempVars[ident] = ident;
              arrSize[ident] = 1;
            }
            temp.append(ident);
            doneParse = true;
          } 
          else { 
           string ident = placeCpy.substr(lPtr, rPtr-lPtr);
            if (funcs.find(ident) != funcs.end()) {
              printf("** Line %d, position %d: This function is used before it's definition: {%s}\n", currLine, currPos, ident.c_str());
            }
            if (tempVars.find(ident) != tempVars.end()) {
                printf("** Line %d, position %d: This identifier is previously declared: {%s}\n", currLine, currPos, ident.c_str());
                
            } 
            if (reserved.find(ident) != reserved.end()) {
                printf("** Line %d, position %d: This identifier's name is a reserved word: {%s}\n", currLine, currPos, ident.c_str());
                
            }
            else {
              tempVars[ident] = ident;
              arrSize[ident] = 1;
            }
            temp.append(ident);
            lPtr = rPtr + 1;
          }
          temp.append("\n");
        }
        $$.code = strdup(temp.c_str());
        $$.place = strdup("");
      } 
      | IDENTIFIER_LOOP COLON ENUM L_PAREN IDENTIFIER_LOOP R_PAREN
      {
        string temp;
        string placeContainer = $5.place; //https://stackoverflow.com/questions/1195675/convert-a-char-to-stdstring
        string build = "";
        for (int i = 0; i < placeContainer.size(); ++i) {
            if (placeContainer.at(i) == '/') {
                temp += ". " + build  +"\n";
                tempVars[build] = build;
                arrSize[build] = 1;
                build = "";
            }
            else if (placeContainer.size()-1 == i) {
                string temp2(1, char(placeContainer.at(i)));
                build.append(temp2);
                temp += ". " + build + "\n";
                tempVars[build] = build;
                arrSize[build] = 1;
                build = "";
            }
            else {
                //Phttps://stackoverflow.com/questions/34462964/converting-int-to-string-of-its-ascii
                string temp2(1, char(placeContainer.at(i)));
                build.append(temp2);
            }
        }
        $$.place = strdup("");
        $$.code = strdup(temp.c_str());
      } 
      | error 
      {
        yyerror("invalid declaration"); yyerrok; yyclearin; 
      } //https://www.gnu.org/software/bison/manual/html_node/Error-Recovery.html
  ;
  DECLARATION_LOOP: DECLARATION SEMICOLON DECLARATION_LOOP 
      {
        string temp;
        temp.append($1.code);
        temp.append($3.code);
        $$.code = strdup(temp.c_str());
        $$.place = strdup("");
      } 
      | %empty
      {
        $$.code = strdup("");
        $$.place = strdup("");
      } 
      ;
  //Statement
  STATEMENT:  VAR ASSIGN EXPRESSION 
              { 
                string temp;
                temp.append($1.code);
                temp.append($3.code);

                if ($1.isArr) {
                  temp += "[]= ";
                }
                else if ($3.isArr) {
                  temp += "= ";
                }
                else {
                  temp += "= ";
                }
                temp.append($1.place);
                temp.append(", ");
                temp.append($3.place);
                temp += "\n";
                $$.code = strdup(temp.c_str());
                
              } 
              |
              IF BOOL-EXPR THEN STATEMENT_LOOP ELSE_BRANCH ENDIF
              {
                string ifLabel = newLabel();
                string elseLabel = newLabel();
                string temp;
                
                temp.append($2.code);
                temp += "?:= " + ifLabel + ", " + $2.place + "\n";
                temp += ":= " + elseLabel + "\n";
                temp += ": " + ifLabel + "\n";
                temp.append($4.code);
                temp += ": " + elseLabel + "\n";
                temp.append($5.code);

                $$.code = strdup(temp.c_str());
              } 
              |
              WHILE BOOL-EXPR BEGINLOOP STATEMENT_LOOP ENDLOOP 
              { 
                string whileLabel = newLabel();
                string inWhileLabel = newLabel();
                string exitLabel = newLabel();
                string codeCpy = $4.code;
                string temp;
                temp += ": " + whileLabel + "\n"; 
                temp.append($2.code); 
                temp += "?:= " + inWhileLabel + ", " + $2.place + "\n"; 
                temp += ":= " + exitLabel + "\n"; 
                temp += ": " + inWhileLabel + "\n"; 
                while(codeCpy.find("continue") != string::npos) {
                  codeCpy.replace(codeCpy.find("continue"), 8, ":= " + whileLabel);
                }
                temp.append(codeCpy); 
                temp += ":= " + whileLabel + "\n"; 
                temp += ": " + exitLabel + "\n";
                $$.code = strdup(temp.c_str());
              } 
              |
              DO BEGINLOOP STATEMENT_LOOP ENDLOOP WHILE BOOL-EXPR 
              {
                string temp;
                string loopLabel = newLabel();
                string dwLabel = newLabel();
                string statement = $3.code;
                string dest;
                dest.append(":= ");
                dest.append(dwLabel);

                while(statement.find("continue") != string::npos) {
                  statement.replace(statement.find("continue"), 8, dest);
                }

                temp.append(": ");
                temp.append(loopLabel);
                temp.append("\n");
                temp.append(statement);
                temp.append(": ");
                temp.append(dwLabel);
                temp.append("\n");
                temp.append($6.code);
                temp.append("?:= ");
                temp.append(loopLabel);
                temp.append(", ");
                temp.append($6.place);
                temp.append("\n");
                $$.code = strdup(temp.c_str());
              } 
              |
              READ VAR_LOOP 
              {
                string temp;
                temp.append($2.code);

                string placeContainer = $2.place; //https://stackoverflow.com/questions/1195675/convert-a-char-to-stdstring
                string build = "";
                for (int i = 0; i < placeContainer.size(); ++i) {
                    if (placeContainer.at(i) == '/') {
                      if (build.find(',') != string::npos) {
                        if (tempVars.find(build.substr(0, build.find(","))) == tempVars.end()){
                          printf("** Line %d, position %d: This variable is used before it's definition: {%s}\n", currLine, currPos, build.c_str());
                        }
                        temp += ".[]< " + build.substr(0, build.find(",")) + ", " + build.substr(build.find(",")+1) + "\n";
                      }
                      else {
                        if (tempVars.find(build) == tempVars.end()){ 
                          printf("** Line %d, position %d: This variable is used before it's definition: {%s}\n", currLine, currPos, build.c_str());
                        }
                      temp += ".< " + build + "\n"; 
                      }
                        build = "";
                    }
                    else if (placeContainer.size()-1 == i) {
                        string temp2(1, char(placeContainer.at(i)));
                        build.append(temp2);
                        if (build.find(',') != string::npos) {
                          if (tempVars.find(build.substr(0, build.find(","))) == tempVars.end()){
                            printf("** Line %d, position %d: This variable is used before it's definition: {%s}\n", currLine, currPos, build.c_str());
                          }
                          temp += ".[]< " + build.substr(0, build.find(",")) + ", " + build.substr(build.find(",")+1) + "\n";
                          }
                          else {
                            if (tempVars.find(build) == tempVars.end()){ 
                              printf("** Line %d, position %d: This variable is used before it's definition: {%s}\n", currLine, currPos, build.c_str());
                            }
                          temp += ".< " + build + "\n";
                        }
                        build = "";
                    }
                    else {
                        //https://stackoverflow.com/questions/34462964/converting-int-to-string-of-its-ascii
                        string temp2(1, char(placeContainer.at(i)));
                        build.append(temp2);
                    }
                }

                $$.code = strdup(temp.c_str());
              } 
              |
              WRITE VAR_LOOP 
              {
                string temp;
                temp.append($2.code);
                string placeContainer = $2.place; //https://stackoverflow.com/questions/1195675/convert-a-char-to-stdstring
                string build = "";
                for (int i = 0; i < placeContainer.size(); ++i) {
                    if (placeContainer.at(i) == '/') {
                      if (build.find(',') != string::npos) {
                        if (tempVars.find(build.substr(0, build.find(","))) == tempVars.end()){
                          printf("** Line %d, position %d: This variable is used before it's definition: {%s}\n", currLine, currPos, build.c_str());
                        }
                        temp += ".[]> " + build.substr(0, build.find(",")) + ", " + build.substr(build.find(",")+1) + "\n";
                      }
                      else {
                        if (tempVars.find(build) == tempVars.end()){ 
                          printf("** Line %d, position %d: This variable is used before it's definition: {%s}\n", currLine, currPos, build.c_str());
                        }
                      temp += ".> " + build + "\n"; 
                      }
                        build = "";
                    }
                    else if (placeContainer.size()-1 == i) {
                        string temp2(1, char(placeContainer.at(i)));
                        build.append(temp2);
                        if (build.find(',') != string::npos) {
                          if (tempVars.find(build.substr(0, build.find(","))) == tempVars.end()){
                           printf("** Line %d, position %d: This variable is used before it's definition: {%s}\n", currLine, currPos, build.c_str());
                          }
                          temp += ".[]> " + build.substr(0, build.find(",")) + ", " + build.substr(build.find(",")+1) + "\n";
                          }
                          else {
                            if (tempVars.find(build) == tempVars.end()){ 
                              printf("** Line %d, position %d: This variable is used before it's definition: {%s}\n", currLine, currPos, build.c_str());
                            }
                            temp += ".> " + build + "\n"; 
                        }
                        build = "";
                    }
                    else {
                        //https://stackoverflow.com/questions/34462964/converting-int-to-string-of-its-ascii
                        string temp2(1, char(placeContainer.at(i)));
                        build.append(temp2);
                    }
                }
                $$.code = strdup(temp.c_str());
              } 
              |
              CONTINUE 
              {
                $$.code = strdup("continue\n");
              } 
              |
              RETURN EXPRESSION  
              {
                string temp;
                temp.append($2.code);
                temp += "ret " + string($2.place) + "\n";
                $$.code = strdup(temp.c_str());
              } 
              |
              error {
                yyerror("invalid statement"); yyerrok; yyclearin; 
              }
  ;//done(5/10 removed endIF)
  ELSE_BRANCH: ELSE STATEMENT_LOOP 
      {
        string temp;
        temp.append($2.code);
        $$.code = strdup(temp.c_str());
      } 
      | %empty
      {
        $$.code = strdup("");
      } 
  ;
  STATEMENT_LOOP: STATEMENT SEMICOLON STATEMENT_LOOP 
      {
        string temp;
        temp.append($1.code);
        temp.append($3.code);
        $$.code = strdup(temp.c_str());
      } 
      | STATEMENT SEMICOLON 
      {
        string temp;
        temp.append($1.code);
        $$.code = strdup(temp.c_str());
      } 
  ;
  //Bool-Expr done(5/10 changed RELATION-AND-EXPR TO BOOL-EXPR)
  BOOL-EXPR: RELATION-AND-EXPR 
      {
        $$.place = $1.place;
        $$.code = $1.code;
      } 
      | 
      RELATION-AND-EXPR OR BOOL-EXPR 
      {
        string tempRes = newTemp();
        string temp;
        temp.append($1.code);
        temp.append($3.code);
        temp += ". " + tempRes + "\n";
        temp += "|| " + tempRes + ", " + $1.place + ", " + $3.place + "\n";
        $$.place = strdup(tempRes.c_str());
        $$.code = strdup(temp.c_str());
      } 
  ;
  //Relation-And-Expr done(5/10 changed RELATION-EXPR TO RELATION-AND-EXPR)
  RELATION-AND-EXPR: RELATION-EXPR 
      {
        $$.place = $1.place;
        $$.code = $1.code;
      } 
      | 
      RELATION-EXPR AND RELATION-AND-EXPR 
      {
        string tempRes = newTemp();
        string temp;
        temp.append($1.code);
        temp.append($3.code);
        temp += ". " + tempRes + "\n";
        temp += "&& " + tempRes + ", " + $1.place + ", " + $3.place + "\n";
        $$.place = strdup(tempRes.c_str());
        $$.code = strdup(temp.c_str());
      } 
  ;
  //Relation-Expr
  //1: make new grammar for all nots
  //(2): add all grammar to one and remove relation_expr_body
  RELATION-EXPR: EXPRESSION COMP EXPRESSION 
      {
        string tempRes = newTemp();
        string temp;
        temp.append($1.code);
        temp.append($3.code);
        temp += ". " + tempRes + "\n";
        temp += string($2.place) + " " + tempRes + ", " + $1.place + ", " + $3.place + "\n";
        $$.place = strdup(tempRes.c_str());
        $$.code = strdup(temp.c_str());
      } 
      |
      NOT EXPRESSION COMP EXPRESSION 
      {
        string tempRes = newTemp();
        string temp;
        temp.append($2.code);
        temp.append($4.code);
        temp += ". " + tempRes + "\n";
        temp += string($3.place) + " " + tempRes + ", " + $2.place + ", " + $4.place + "\n";
        temp += "! " + tempRes + ", " + tempRes;
        $$.place = strdup(tempRes.c_str());
        $$.code = strdup(temp.c_str());
      }
      |
      NOT TRUE
      {
        $$.place = strdup("0");
        $$.code = strdup("");
        $$.isArr = false;
      }
      |
      NOT FALSE
      {
        $$.place = strdup("1");
        $$.code = strdup("");
        $$.isArr = false;
      }
      |
      TRUE 
      {
        $$.place = strdup("1");
        $$.code = strdup("");
        $$.isArr = false;
      } 
      |
      FALSE 
      {
        $$.place = strdup("0");
        $$.code = strdup("");
        $$.isArr = false;
      } 
      |
      L_PAREN BOOL-EXPR R_PAREN 
      {
        $$.code = $2.code;
        $$.place = $2.place;
      } 
      |
      NOT L_PAREN BOOL-EXPR R_PAREN
      {
        string tempRes = newTemp();
        string temp;
        temp.append($3.code);
        temp += ". " + tempRes + "\n";
        temp += "! " + tempRes + ", " + $3.place + "\n";
        $$.place = strdup(tempRes.c_str());
        $$.code = strdup(temp.c_str());
      }
  ;
  //Comp
  COMP: EQ 
      {
        $$.place = strdup("==");
        $$.code = strdup("");
        $$.isArr = false;
      } 
      | 
      NEQ 
      {
        $$.place = strdup("<>");
        $$.code = strdup("");
        $$.isArr = false;
      } 
      | 
      LT 
      {
        $$.place = strdup("<");
        $$.code = strdup("");
        $$.isArr = false;
      } 
      | 
      GT 
      {
        $$.place = strdup(">");
        $$.code = strdup("");
        $$.isArr = false;
      } 
      | 
      LTE 
      {
        $$.place = strdup("<=");
        $$.code = strdup("");
        $$.isArr = false;
      } 
      | 
      GTE 
      {
        $$.place = strdup(">=");
        $$.code = strdup("");
        $$.isArr = false;
      } 
  ;
  //Expression DONE(5/10 changed MULT_EXPR to EXPRE)
  EXPRESSION: MULTIPLICATIVE_EXPR 
      {
        $$.place = $1.place;
        $$.code = $1.code;
      } 
      | 
      MULTIPLICATIVE_EXPR ADD EXPRESSION 
      {
        string tempRes = newTemp();
        string temp;
        temp.append($1.code);
        temp.append($3.code);
        temp += ". " + tempRes + "\n";
        temp += "+ " + tempRes + ", " + $1.place + ", " + $3.place + "\n";
        $$.place = strdup(tempRes.c_str());
        $$.code = strdup(temp.c_str());
      } 
      | 
      MULTIPLICATIVE_EXPR SUB EXPRESSION 
      {
        string tempRes = newTemp();
        string temp;
        temp.append($1.code);
        temp.append($3.code);
        temp += ". " + tempRes + "\n";
        temp += "- " + tempRes + ", " + $1.place + ", " + $3.place + "\n";
        $$.place = strdup(tempRes.c_str());
        $$.code = strdup(temp.c_str());
      } 
  ;
  EXPRESSION_LOOP: EXPRESSION 
      {
        $$.place = $1.place;
        $$.code = $1.code;
      } 
      | 
      EXPRESSION COMMA EXPRESSION_LOOP 
      {
        string temp;
        temp += string($1.place) + "/" + string($3.place);
        string expression;
        expression.append($1.code);
        expression.append($3.code);
        $$.place = strdup(temp.c_str());
        $$.code = strdup(expression.c_str());
      } 
      | %empty
      {
        $$.place = strdup("");
        $$.code = strdup("");

      } 
  ;
  //MULTIPLICATIVE_EXPR DONE(5/10 changed TERM TO )
  MULTIPLICATIVE_EXPR: TERM 
      {
        $$.place = $1.place;
        $$.code = $1.code;
      } 
      | 
      TERM MULT MULTIPLICATIVE_EXPR 
      {
        string tempRes = newTemp();
        string temp;
        temp.append($1.code);
        temp.append($3.code);
        temp += ". " + tempRes + "\n";
        temp += "* " + tempRes + ", " + $1.place + ", " + $3.place + "\n";
        $$.place = strdup(tempRes.c_str());
        $$.code = strdup(temp.c_str());
      } 
      | 
      TERM DIV MULTIPLICATIVE_EXPR 
      {
        string tempRes = newTemp();
        string temp;
        temp.append($1.code);
        temp.append($3.code);
        temp += ". " + tempRes + "\n";
        temp += "/ " + tempRes + ", " + $1.place + ", " + $3.place + "\n";
        $$.place = strdup(tempRes.c_str());
        $$.code = strdup(temp.c_str());
      } 
      | 
      TERM MOD MULTIPLICATIVE_EXPR
      {
        string tempRes = newTemp();
        string temp;
        temp.append($1.code);
        temp.append($3.code);
        temp += ". " + tempRes + "\n";
        temp += "% " + tempRes + ", " + $1.place + ", " + $3.place + "\n";
        $$.place = strdup(tempRes.c_str());
        $$.code = strdup(temp.c_str());
      } 
  ;
  //Term
  TERM: VAR 
      {
        string placeCpy = $1.place;
        string temp;
        string tempRes = newTemp(); 
        temp.append($1.code);
        temp += ". " + tempRes + "\n"; 
        if (placeCpy.find(",") != string::npos) { 

          if (tempVars.find(placeCpy.substr(0, placeCpy.find(","))) == tempVars.end()){ 
              printf("** Line %d, position %d: This variable is used before it's definition: {%s}\n", currLine, currPos, $1.place);
          } 
          temp += "=[] " + tempRes + ", ";
          temp += placeCpy.substr(0, placeCpy.find(","));
          temp += placeCpy.substr(placeCpy.find(",")) + "\n";
        } 
        else {
          if (tempVars.find(placeCpy) == tempVars.end()) {
              printf("** Line %d, position %d: This variable is used before it's definition: {%s}\n", currLine, currPos, $1.place);
          }
          temp += "= " + tempRes + ", " + $1.place + "\n";
        }
        $$.place = strdup(tempRes.c_str());
        $$.code = strdup(temp.c_str());
      }
      | 
      NUMBER 
      {
        string tempRes = newTemp();
        string temp;
        temp += ". " + tempRes + "\n";
        temp += "= " + tempRes + ", " + to_string($1) + "\n";
        $$.place = strdup(tempRes.c_str());
        $$.code = strdup(temp.c_str());
        
      } 
      | 
      L_PAREN EXPRESSION R_PAREN 
      {
        $$.place = $2.place;
        $$.code = $2.code;
      } 
      |
      SUB VAR %prec UMINUS 
      {
        string placeCpy = $2.place;
        if (placeCpy.find(",") != string::npos) { 
          if (tempVars.find(placeCpy.substr(0, placeCpy.find(","))) == tempVars.end()){ 
              printf("** Line %d, position %d: This variable is used before it's definition: {%s}\n", currLine, currPos, $2.place);
          } 
        } 
        else { 
          if (tempVars.find(placeCpy) == tempVars.end()) { 
              printf("** Line %d, position %d: This variable is used before it's definition: {%s}\n", currLine, currPos, $2.place);
          }
        }
        string tempRes = newTemp();
        string temp;
        temp += ". " + tempRes + "\n";
        temp += "- " + tempRes + ", 0, " + $2.place + "\n"; 
        $$.place = strdup(string(tempRes).c_str());
        $$.code = strdup(temp.c_str());
      } 
      | 
      SUB NUMBER %prec UMINUS 
      {
        string tempRes = newTemp();
        string temp;
        temp += ". " + tempRes + "\n";
        temp += "- " + tempRes + ", 0, " + to_string($2) + "\n";
        $$.place = strdup(tempRes.c_str());
        $$.code = strdup(temp.c_str());
      } 
      | 
      SUB L_PAREN EXPRESSION R_PAREN %prec UMINUS 
      {
        string tempRes = newTemp();
        string temp;
        temp.append($3.code);
        temp += ". " + tempRes + "\n";
        temp += "- " + tempRes + ", 0, " + $3.place;
        $$.place = strdup(tempRes.c_str());
        $$.code = strdup(temp.c_str());
      } 
      |
      Ident L_PAREN EXPRESSION_LOOP R_PAREN 
      {
        if(funcs.find(string($1.place)) == funcs.end()){ 
          printf("** Line %d, position %d: This function is used before it's definition: {%s}\n", currLine, currPos, $1.place);
        }
        string temp;
        string tempRes = newTemp();

        temp.append($3.code);
        
        string placeContainer = $3.place; //https://stackoverflow.com/questions/1195675/convert-a-char-to-stdstring
        string build = "";
        for (int i = 0; i < placeContainer.size(); ++i) {
            if (placeContainer.at(i) == '/') {
                temp += "param " + build  +"\n";
                build = "";
            }
            else if (placeContainer.size()-1 == i) {
                string temp2(1, char(placeContainer.at(i)));
                build.append(temp2);
                temp += "param " + build + "\n";
                build = "";
            }
            else {
                //Proc2 https://stackoverflow.com/questions/34462964/converting-int-to-string-of-its-ascii
                string temp2(1, char(placeContainer.at(i)));
                build.append(temp2);
            }
          }
          temp += ". " + tempRes + "\n"; 
          temp += "call " + string($1.place) + ", " + tempRes + "\n";




        $$.place = strdup(tempRes.c_str());
        $$.code = strdup(temp.c_str());
      } 
  ;
  //Var
  VAR_LOOP: VAR 
      {
        $$.place = strdup($1.place);
        $$.code = strdup($1.code);
      } 
      | 
      VAR COMMA VAR_LOOP 
      {
        string temp;
        temp += string($1.place) + "/" + string($3.place);
        string codeTemp;
        codeTemp.append($1.code);
        codeTemp.append($3.code);
        $$.place = strdup(temp.c_str());
        $$.code = strdup(codeTemp.c_str());
      } 
  ;
  VAR:  Ident 
      {
        $$.place = $1.place;
        $$.code = strdup("");
      } 
      | Ident L_SQUARE_BRACKET EXPRESSION R_SQUARE_BRACKET 
      {
        string temp;
        string placeTemp;
        temp.append($3.code);
        placeTemp.append($1.place);
        placeTemp.append(",");
        placeTemp.append($3.place);
        $$.place = strdup(placeTemp.c_str()); 
        $$.code = strdup(temp.c_str());
        $$.isArr = true;
      };
%% 


void yyerror(const char *msg) {
   printf("** Line %d, position %d: %s\n", currLine, currPos, msg);
}

string newTemp() {
  string t = "t" + to_string(tempCount);
  tempCount++;
  return t;
}

string newLabel() {
  string l = "L" + to_string(labelCount);
  labelCount++;
  return l;
}