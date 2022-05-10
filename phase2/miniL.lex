   /* cs152-miniL phase1 */
   
%{   
   /* write your C code here for definitions of variables and including headers */
#include "y.tab.h"
int currLine = 1, currPos = 1;
%}

   /* some common rules */
DIGIT       [0-9]
COMMENT		[##].* 
DIGIT_ERROR ({DIGIT}|[_])
LETTER_UNDER [a-zA-Z_]
ALL         [a-zA-Z0-9]
IDENTITY    {LETTER_UNDER}*{ALL}* 

%%
   /* specific lexer rules in regex */
{COMMENT}               {currLine++; currPos = 1;}
[ \t]+                  {currPos += yyleng;}
"\n"                    {currLine++; currPos = 1;}

   /* Reserved words */
"function"                {printf("FUNCTION\n"); currPos += yyleng; return FUNCTION;}
"beginparams"             {printf("BEGIN_PARAMS\n"); currPos += yyleng; return BEGIN_PARAMS;}
"endparams"               {printf("END_PARAMS\n"); currPos += yyleng; return END_PARAMS;}
"beginlocals"             {printf("BEGIN_LOCALS\n"); currPos += yyleng; return BEGIN_LOCALS;}
"endlocals"               {printf("END_LOCALS\n"); currPos += yyleng; return END_LOCALS;}
"beginbody"               {printf("BEGIN_BODY\n"); currPos += yyleng; return BEGIN_BODY;}
"endbody"                 {printf("END_BODY\n"); currPos += yyleng; return END_BODY;}
"integer"                 {printf("INTEGER\n"); currPos += yyleng; return INTEGER;}
"array"                   {printf("ARRAY\n"); currPos += yyleng; return ARRAY;}
"enum"                    {printf("ENUM\n"); currPos += yyleng; }return ENUM;
"of"                      {printf("OF\n"); currPos += yyleng; return OF;}
"if"                      {printf("IF\n"); currPos += yyleng; return IF;}
"then"                    {printf("THEN\n"); currPos += yyleng; return THEN;}
"endif"                   {printf("ENDIF\n"); currPos += yyleng; return ENDIF;}
"else"                    {printf("ELSE\n"); currPos += yyleng; return ELSE;}
"for"                     {printf("FOR\n"); currPos += yyleng; return FOR;}
"while"                   {printf("WHILE\n"); currPos += yyleng; return WHILE;}
"do"                      {printf("DO\n"); currPos += yyleng; return DO;}
"beginloop"               {printf("BEGINLOOP\n"); currPos += yyleng; return BEGINLOOP;}
"endloop"                 {printf("ENDLOOP\n"); currPos += yyleng; return ENDLOOP;}
"continue"                {printf("CONTINUE\n"); currPos += yyleng; return CONTINUE;}
"read"                    {printf("READ\n"); currPos += yyleng; return READ;}
"write"                   {printf("WRITE\n"); currPos += yyleng; return WRITE;}
"and"                     {printf("AND\n"); currPos += yyleng; return AND;}
"or"                      {printf("OR\n"); currPos += yyleng; return OR;}
"not"                     {printf("NOT\n"); currPos += yyleng; return NOT;}
"true"                    {printf("TRUE\n"); currPos += yyleng; return TRUE;}
"false"                   {printf("FALSE\n"); currPos += yyleng; return FALSE;}
"return"                  {printf("RETURN\n"); currPos += yyleng; return RETURN;}

   /* Arithmetic Operators */
"-"                     {printf("SUB\n"); currPos += yyleng; return SUB;}
"+"                     {printf("ADD\n"); currPos += yyleng; return ADD;}
"*"                     {printf("MULT\n"); currPos += yyleng; return MULT;}
"/"                     {printf("DIV\n"); currPos += yyleng; return DIV;}
"%"                     {printf("MOD\n"); currPos += yyleng; return MOD;}

   /* Comparison Operators */
"=="                    {printf("EQ\n"); currPos += yyleng; return EQ;}
"<>"                    {printf("NEQ\n"); currPos += yyleng; return NEQ;}
"<"                     {printf("LT\n"); currPos += yyleng; return LT;}
">"                     {printf("GT\n"); currPos += yyleng; return GT;}
"<="                    {printf("LTE\n"); currPos += yyleng; return LTE;}
">="                    {printf("GTE\n"); currPos += yyleng; return GTE;}

   /* Other Special Symbols */
";"                     {printf("SEMICOLON\n"); currPos += yyleng; return SEMICOLON;}
":"                     {printf("COLON\n"); currPos += yyleng; return COLON;}
","                     {printf("COMMA\n"); currPos += yyleng; return COMMA;}
"("                     {printf("L_PAREN\n"); currPos += yyleng; return L_PAREN;}
")"                     {printf("R_PAREN\n"); currPos += yyleng; return R_PAREN;}
"["                     {printf("L_SQUARE_BRACKET\n"); currPos += yyleng; return L_SQUARE_BRACKET;}
"]"                     {printf("R_SQUARE_BRACKET\n"); currPos += yyleng; return R_SQUARE_BRACKET;}
":="                    {printf("ASSIGN\n"); currPos += yyleng; return FUNCTION;}

(\.{DIGIT}+)|({DIGIT}+(\.{DIGIT}*)?([eE][+-]?[0-9]+)?)         {currPos += yyleng; yylval.nVal = atoi(yytext); return NUMBER}

   /* Errors in Lexicon Parsing */
{DIGIT_ERROR}{IDENTITY}                                        {printf("Error at line %d, column %d: identifier \"%s\" must begin with a letter\n", currLine, currPos - 1, yytext); exit(0);}
{IDENTITY}*[_]                                                 {printf("Error at line %d, column %d: identifier \"%s\" cannot end with an underscore\n", currLine, currPos - 1, yytext); exit(0);}
 
   /* NOTE: For some reason, the error parsing needs to be placed before the identity line of code is active, probably needs to parse through erroneous cases before identifying correct ones ig */
{IDENTITY}                                                     {currPos += yyleng; yylval.iVal = yytext; return IDENT}
.                                                              {printf("Error at line %d, column %d: unrecognized symbol \"%s\"\n", currLine, currPos - 1, yytext); exit(0);}

%%
	/* C functions used in lexer */

int main(int argc, char ** argv)
{
   if(argc >= 2)
   {
      yyin = fopen(argv[1], "r");
      if(yyin == NULL)
      {
         yyin = stdin;
      }
   }
   else
   {
      yyin = stdin;
   }
   
   yylex();
}
