%option noyywrap

%{
#include <stdio.h>
#include <stdlib.h>
#include "y.tab.h"
%}

DIGIT [0-9]
ALPHABET [a-zA-Z_]
EQ [=]

%%
{ALPHABET}+({DIGIT}|{ALPHABET})* { strcpy(yylval.lexeme, yytext); return VAR; }
"++" { return PREPOSTADD; }
"--" { return PREPOSTSUB; }
"+" { return ADD; }
"\-" { return SUB; }
"*" { return MUL; }
"/" { return DIV; }
{EQ} { return EQ; }
{DIGIT}+("."{DIGIT}+)? { yylval.dval = atoi(yytext); return NUMBER; }
[ \t\n] ; /* handle whitespaces and new lines */
"\(" { return LPAREN; }
"\)" { return RPAREN; }
";" { return SEMICOLON; }
<<EOF>> { return EOF; }
. { return yytext[0]; }
%%`
