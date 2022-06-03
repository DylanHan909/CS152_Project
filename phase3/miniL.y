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
 #include <string>
 #include <cstring>
 
 using namespace std;

 int tempCount = 0;
 int labelCount = 0;
 extern char* yytext;
 std::map<std::string, std::string> tempVars;
 std::map<std::string, int> arrSize;
 bool mainFunc = false;
 std::set<std::string> funcs;
 std::set<std::string> reserved = {"FUNCTION", "BEGIN_PARAMS", "END_PARAMS", "BEGIN_LOCALS", "END_LOCALS", "BEGIN_BODY", "END_BODY", "INTEGER",
    "ARRAY", "OF", "IF", "THEN", "ENDIF", "ELSE", "WHILE", "DO", "FOREACH", "IN", "BEGINLOOP", "ENDLOOP", "CONTINUE", "READ", "WRITE", "AND", "OR", 
    "NOT", "TRUE", "FALSE", "RETURN", "SUB", "ADD", "MULT", "DIV", "MOD", "EQ", "NEQ", "LT", "GT", "LTE", "GTE", "L_PAREN", "R_PAREN", "L_SQUARE_BRACKET",
    "R_SQUARE_BRACKET", "COLON", "SEMICOLON", "COMMA", "ASSIGN", "function", "Ident", "beginparams", "endparams", "beginlocals", "endlocals", "integer", 
    "beginbody", "endbody", "beginloop", "endloop", "if", "endif", "foreach", "continue", "while", "else", "read", "do", "write"};
 int yylex();
 std::string newTemp();
 std::string newLabel();

 void yyerror(const char *msg);
 extern int currLine;
 extern int currPos;
 extern FILE * yyin;
%}

%union{
  char * iVal;
  int nVal;

  struct S{
    char* code;
  } statement;

  struct E{
    char* place;
    char* code;
    bool isArr;
  } expression;
}

%error-verbose
%locations

%type <expression> Ident IDENTIFIER_LOOP
%type <expression> FUNCTIONS FUNCTION_LOOP DECLARATION DECLARATION_LOOP VAR VAR_LOOP
%type <expression> EXPRESSION EXPRESSION_LOOP MULTIPLICATIVE_EXPR TERM BOOL-EXPR RELATION-EXPR RELATION-AND-EXPR RELATION_EXPR_BODY COMP
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
%left L_PAREN R_PAREN L_SQUARE_BRACKET R_SQUARE_BRACKET
%left ASSIGN

%nonassoc UMINUS
%right NOT

%% 
  /* write your rules here */
  //Program
  PROGRAM: FUNCTION_LOOP {printf("PROGRAM -> FUNCTION_LOOP\n");} | {printf("PROGRAM -> ε\n");} 
  ;
  //Function
  FUNCTION_LOOP: FUNCTIONS FUNCTION_LOOP {printf("FUNCTION_LOOP -> FUNCTIONS FUNCTION_LOOP\n");} | {printf("FUNCTION_LOOP -> ε\n");} 
  ;
  FUNCTIONS: FUNCTION IDENT SEMICOLON BEGIN_PARAMS DECLARATION_LOOP END_PARAMS BEGIN_LOCALS DECLARATION_LOOP END_LOCALS BEGIN_BODY STATEMENT_LOOP END_BODY 
      {
        //std::string temp = "func";
        /*
        temp.append($2.place);
        temp.append("\n");
        std::string s = $2.place;
        if (s == "main") {
          mainFunc = true;
        }
        temp.append($5.code);
        */

        //std::cout << "``BRUHHH" << $2.place;
        /* func fibonacci

        */
        /*
          function fibonacci;
          beginparams
            k : integer;
          endparams
          beginlocals
          endlocals
          beginbody
            if (k <= 1) then return 1; endif;
            return fibonacci(k - 1) + fibonacci(k - 2);
          endbody
        */

        //string s = $5;
        cout << "BRUHHH" ;
        printf("%s\n", $2.place);
      }
  ;
  //Identifier
  IDENTIFIER_LOOP: Ident {printf("IDENTIFIER_LOOP -> IDENT\n");} | Ident COMMA IDENTIFIER_LOOP {printf("IDENTIFIER_LOOP -> IDENT COMMA IDENTIFIER_LOOP\n");}
  ;
  Ident: IDENT {printf("Ident -> IDENT %s\n", $1);}
  //Declaration
  DECLARATION: IDENTIFIER_LOOP COLON ARRAY L_SQUARE_BRACKET NUMBER R_SQUARE_BRACKET OF INTEGER {printf("DECLARATION -> IDENTIFIER_LOOP COLON ARRAY L_SQUARE_BRACKET NUMBER R_SQUARE_BRACKET OF INTEGER\n");} | IDENTIFIER_LOOP COLON INTEGER {printf("DECLARATION -> IDENTIFIER_LOOP COLON INTEGER\n");} | IDENTIFIER_LOOP COLON ENUM L_PAREN IDENTIFIER_LOOP R_PAREN {printf("DECLARATION -> IDENTIFIER_LOOP COLON ENUM L_PAREN IDENTIFIER_LOOP R_PAREN\n");} | error {yyerror("invalid declaration"); yyerrok; yyclearin; } //https://www.gnu.org/software/bison/manual/html_node/Error-Recovery.html
  ;
  DECLARATION_LOOP: DECLARATION SEMICOLON DECLARATION_LOOP {printf("DECLARATION_LOOP -> DECLARATION SEMICOLON DECLARATION_LOOP\n");} | {printf("DECLARATION_LOOP -> ε\n");} 
  ;
  //Statement
  STATEMENT:  VAR ASSIGN EXPRESSION {printf("STATEMENT -> VAR ASSIGN EXPRESSION\n");} |
              IF BOOL-EXPR THEN STATEMENT_LOOP ELSE_BRANCH ENDIF {printf("STATEMENT -> IF BOOL-EXPR THEN STATEMENT_LOOP ELSE_BRANCH ENDIF\n");} |
              WHILE BOOL-EXPR BEGINLOOP STATEMENT_LOOP ENDLOOP {printf("STATEMENT -> WHILE BOOL-EXPR BEGINLOOP STATEMENT_LOOP ENDLOOP\n");} |
              DO BEGINLOOP STATEMENT_LOOP ENDLOOP WHILE BOOL-EXPR {printf("\n");} |
              READ VAR_LOOP {printf("STATEMENT -> READ VAR_LOOP\n");} |
              WRITE VAR_LOOP {printf("STATEMENT -> WRITE VAR_LOOP\n");} |
              CONTINUE {printf("STATEMENT -> CONTINUE\n");} |
              RETURN EXPRESSION  {printf("STATEMENT -> RETURN EXPRESSION\n");} |
              error {yyerror("invalid statement"); yyerrok; yyclearin; }
  ;//done(5/10 removed endIF
  ELSE_BRANCH: ELSE STATEMENT_LOOP {printf("ELSE_BRANCH -> ELSE STATEMENT_LOOP\n");} | {printf("ELSE_BRANCH -> ε\n");} 
  ;
  STATEMENT_LOOP: STATEMENT SEMICOLON STATEMENT_LOOP {printf("STATEMENT_LOOP -> STATEMENT SEMICOLON STATEMENT_LOOP\n");} | STATEMENT SEMICOLON {printf("STATEMENT_LOOP -> STATEMENT SEMICOLON\n");} 
  ;
  //Bool-Expr done(5/10 changed RELATION-AND-EXPR TO BOOL-EXPR)
  BOOL-EXPR: RELATION-AND-EXPR {printf("BOOL-EXPR -> RELATION-AND-EXPR\n");} | RELATION-AND-EXPR OR BOOL-EXPR {printf("BOOL-EXPR -> RELATION-AND-EXPR OR BOOL-EXPR\n");} 
  ;
  //Relation-And-Expr done(5/10 changed RELATION-EXPR TO RELATION-AND-EXPR)
  RELATION-AND-EXPR: RELATION-EXPR {printf("RELATION-AND-EXPR -> RELATION-EXPR\n");} | RELATION-EXPR AND RELATION-AND-EXPR {printf("RELATION-AND-EXPR -> RELATION-EXPR AND RELATION-AND-EXPR\n");} 
  ;
  //Relation-Expr
  RELATION-EXPR: NOT RELATION_EXPR_BODY {printf("RELATION-EXPR -> NOT RELATION_EXPR_BODY\n");} | RELATION_EXPR_BODY {printf("RELATION-EXPR -> RELATION_EXPR_BODY\n");} 
  ;
  RELATION_EXPR_BODY: EXPRESSION COMP EXPRESSION {printf("RELATION_EXPR_BODY -> EXPRESSION COMP EXPRESSION\n");} |
                      TRUE {printf("RELATION_EXPR_BODY -> TRUE\n");} |
                      FALSE {printf("RELATION_EXPR_BODY -> FALSE\n");} |
                      L_PAREN BOOL-EXPR R_PAREN {printf("RELATION_EXPR_BODY -> L_PARN BOOL-EXPR R_PAREN\n");} 
  ;
  //Comp
  COMP: EQ {printf("COMP -> EQ\n");} | NEQ {printf("COMP -> NEQ\n");} | LT {printf("COMP -> LT\n");} | GT {printf("COMP -> GT\n");} | LTE {printf("COMP -> LTE\n");} | GTE {printf("COMP -> GTE\n");} 
  ;
  //Expression DONE(5/10 changed MULT_EXPR to EXPRE)
  EXPRESSION: MULTIPLICATIVE_EXPR {printf("EXPRESSION -> MULTIPLICATIVE_EXPR\n");} | MULTIPLICATIVE_EXPR ADD EXPRESSION {printf("EXPRESSION -> MULTIPLICATIVE_EXPR ADD EXPRESSION\n");} | MULTIPLICATIVE_EXPR SUB EXPRESSION {printf("EXPRESSION -> MULTIPLICATIVE_EXPR SUB EXPRESSION\n");} 
  ;
  EXPRESSION_LOOP: EXPRESSION {printf("EXPRESSION_LOOP -> EXPRESSION\n");} | EXPRESSION COMMA EXPRESSION_LOOP {printf("EXPRESSION_LOOP -> EXPRESSION COMMA EXPRESSION_LOOP\n");} | {printf("EXPRESSION_LOOP -> ε\n");} 
  ;
  //MULTIPLICATIVE_EXPR DONE(5/10 changed TERM TO )
  MULTIPLICATIVE_EXPR: TERM {printf("MULTIPLICATIVE_EXPR -> TERM\n");} | TERM MULT MULTIPLICATIVE_EXPR {printf("MULTIPLICATIVE_EXPR -> TERM MULT MULTIPLICATIVE_EXPR\n");} | TERM DIV MULTIPLICATIVE_EXPR {printf("MULTIPLICATIVE_EXPR -> TERM DIV MULTIPLICATIVE_EXPR\n");} | TERM MOD MULTIPLICATIVE_EXPR {printf("MULTIPLICATIVE_EXPR -> TERM MOD MULTIPLICATIVE_EXPR\n");} 
  ;
  //Term
  TERM: VAR {printf("TERM -> VAR\n");}| NUMBER {printf("TERM -> NUMBER %d\n", $1);} | L_PAREN EXPRESSION R_PAREN {printf("TERM -> L_PAREN EXPRESSION R_PAREN\n");} |
        SUB VAR %prec UMINUS {printf("TERM -> SUB VAR %PREC UMINUS\n");} | SUB NUMBER %prec UMINUS {printf("TERM -> SUB NUMBER %PREC UMINUS %d\n", $2);} | SUB L_PAREN EXPRESSION R_PAREN %prec UMINUS {printf("TERM -> SUB L_PAREN EXPRESSION R_PAREN %PREC UMINUS\n");} |
        Ident L_PAREN EXPRESSION_LOOP R_PAREN {printf("TERM -> IDENT L_PAREN EXPRESSION_LOOP R_PAREN\n");} 
  ;
  //Var
  VAR_LOOP: VAR {printf("VAR_LOOP -> VAR\n");} | VAR COMMA VAR_LOOP {printf("VAR_LOOP -> VAR COMMA VAR_LOOP\n");} 
  ;
  VAR:  Ident {printf("VAR -> IDENT\n");} | Ident L_SQUARE_BRACKET EXPRESSION R_SQUARE_BRACKET {printf("VAR -> IDENT L_SQUARE_BRACKET EXPRESSION R_SQUARE_BRACKET\n");} 
  ;
%% 


void yyerror(const char *msg) {
   printf("** Line %d, position %d: %s\n", currLine, currPos, msg);
}

std::string newTemp() {
  string t = "__temp__" + to_string(tempCount);
  tempCount++;
  return t;
}

std::string newLabel() {
  string l = "__label__" + to_string(labelCount);
  labelCount++;
  return l;
}