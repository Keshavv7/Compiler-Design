%{
#include "y.tab.h"
int inValid = 1; // Assume it's invalid unless proven otherwise
%}

%option noyywrap

ID ([_a-zA-Z][_a-zA-Z0-9]*)
NUMBER -?([0-9]+|([0-9]*\.[0-9]+)([eE][-+]?[0-9]+)?)


%%

[ \t]+          /* Ignore whitespace and tabs */
{ID}                         { return ID; }
"++"                         { return INC; }
"--"                         { return DEC; }
"="                          { return ASSIGN; }
"+"                          { return PLUS; }
"-"                          { return MINUS; }
"*"                          { return MUL; }
"/"                          { return DIV; }
"("                          { return LPAREN; }
")"                          { return RPAREN; }
{NUMBER}                     { return NUM; }
";"                          { return SEMICOLON; }
"\n"                         { return EOL; }
.                            { return yytext[0]; }


%%
