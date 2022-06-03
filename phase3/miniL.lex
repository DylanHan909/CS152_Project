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
"function"                {currPos += yyleng; return FUNCTION;}
"beginparams"             {currPos += yyleng; return BEGIN_PARAMS;}
"endparams"               {currPos += yyleng; return END_PARAMS;}
"beginlocals"             {currPos += yyleng; return BEGIN_LOCALS;}
"endlocals"               {currPos += yyleng; return END_LOCALS;}
"beginbody"               {currPos += yyleng; return BEGIN_BODY;}
"endbody"                 {currPos += yyleng; return END_BODY;}
"integer"                 {currPos += yyleng; return INTEGER;}
"array"                   {currPos += yyleng; return ARRAY;}
"enum"                    {currPos += yyleng; }return ENUM;
"of"                      {currPos += yyleng; return OF;}
"if"                      {currPos += yyleng; return IF;}
"then"                    {currPos += yyleng; return THEN;}
"endif"                   {currPos += yyleng; return ENDIF;}
"else"                    {currPos += yyleng; return ELSE;}
"for"                     {currPos += yyleng; return FOR;}
"while"                   {currPos += yyleng; return WHILE;}
"do"                      {currPos += yyleng; return DO;}
"beginloop"               {currPos += yyleng; return BEGINLOOP;}
"endloop"                 {currPos += yyleng; return ENDLOOP;}
"continue"                {currPos += yyleng; return CONTINUE;}
"read"                    {currPos += yyleng; return READ;}
"write"                   {currPos += yyleng; return WRITE;}
"and"                     {currPos += yyleng; return AND;}
"or"                      {currPos += yyleng; return OR;}
"not"                     {currPos += yyleng; return NOT;}
"true"                    {currPos += yyleng; return TRUE;}
"false"                   {currPos += yyleng; return FALSE;}
"return"                  {currPos += yyleng; return RETURN;}

   /* Arithmetic Operators */
"-"                     {currPos += yyleng; return SUB;}
"+"                     {currPos += yyleng; return ADD;}
"*"                     {currPos += yyleng; return MULT;}
"/"                     {currPos += yyleng; return DIV;}
"%"                     {currPos += yyleng; return MOD;}

   /* Comparison Operators */
"=="                    {currPos += yyleng; return EQ;}
"<>"                    {currPos += yyleng; return NEQ;}
"<"                     {currPos += yyleng; return LT;}
">"                     {currPos += yyleng; return GT;}
"<="                    {currPos += yyleng; return LTE;}
">="                    {currPos += yyleng; return GTE;}

   /* Other Special Symbols */
";"                     {currPos += yyleng; return SEMICOLON;}
":"                     {currPos += yyleng; return COLON;}
","                     {currPos += yyleng; return COMMA;}
"("                     {currPos += yyleng; return L_PAREN;}
")"                     {currPos += yyleng; return R_PAREN;}
"["                     {currPos += yyleng; return L_SQUARE_BRACKET;}
"]"                     {currPos += yyleng; return R_SQUARE_BRACKET;}
":="                    {currPos += yyleng; return ASSIGN;}

(\.{DIGIT}+)|({DIGIT}+(\.{DIGIT}*)?([eE][+-]?[0-9]+)?)         {currPos += yyleng; yylval.nVal = atoi(yytext); return NUMBER;}

   /* Errors in Lexicon Parsing */
{DIGIT_ERROR}{IDENTITY}                                        {printf("Error at line %d, column %d: identifier \"%s\" must begin with a letter\n", currLine, currPos - 1, yytext); exit(0);}
{IDENTITY}*[_]                                                 {printf("Error at line %d, column %d: identifier \"%s\" cannot end with an underscore\n", currLine, currPos - 1, yytext); exit(0);}
 
   /* NOTE: For some reason, the error parsing needs to be placed before the identity line of code is active, probably needs to parse through erroneous cases before identifying correct ones ig */
{IDENTITY}                                                     {currPos += yyleng; yylval.iVal = yytext; return IDENT;}
.                                                              {printf("Error at line %d, column %d: unrecognized symbol \"%s\"\n", currLine, currPos - 1, yytext); exit(0);}

%%
	/* C functions used in lexer */
int yyparse();
int yylex();

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
   
   //yylex();
   yyparse();
}
