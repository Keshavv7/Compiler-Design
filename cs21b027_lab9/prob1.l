%option noyywrap
%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "y.tab.h"
int i=0;
%}

digit [0-9]
number {digit}+
letter [a-z_A-Z]
variable {letter}({digit}|{letter})*
%%


"++" {//printf("%s",yytext);
strcpy(yylval.lexeme, yytext);return DOUBLEPLUS;}
"--" {//printf("%s",yytext);
strcpy(yylval.lexeme, yytext);return DOUBLEMINUS;}
"==" {//printf("%s",yytext);
strcpy(yylval.lexeme, yytext);return DOUBLEEQUAL;}
"!=" {//printf("%s",yytext);
strcpy(yylval.lexeme, yytext);return NOTEQUAL;}
"!"  {//printf("%s",yytext);
strcpy(yylval.lexeme, yytext);return NOT;}
"&&" {//printf("%s",yytext);
strcpy(yylval.lexeme, yytext);return AND;}
"||" {//printf("%s",yytext);
strcpy(yylval.lexeme, yytext);return OR;}
"<=" {//printf("%s",yytext);
strcpy(yylval.lexeme, yytext);return LESSTHANOREQUALTO;}
">=" {//printf("%s",yytext);
strcpy(yylval.lexeme, yytext);return GREATERTHANOREQUALTO;}
"<" {//printf("%s",yytext);
strcpy(yylval.lexeme, yytext);return LESSTHAN;}
">" {//printf("%s",yytext);
strcpy(yylval.lexeme, yytext);
return GREATERTHAN;}
"=" {//printf("%s",yytext);
return EQUALS;}
{number}"."{number} {//printf("%s",yytext);
return FLOAT;}
{number} {//printf("%s",yytext);
yylval.dval=atoi(yytext);return POSNUMBER;}
"if" {//printf("%s",yytext);
return IF;}
"switch" {//printf("%s",yytext);
return SWITCH;}
"while" {//printf("%s",yytext);
return WHILE;}
"else" {//printf("%s",yytext);
return ELSE;}
"true" {//printf("%s",yytext);
strcpy(yylval.lexeme, yytext);return BOOLTRUE;}
"false" {//printf("%s",yytext);
strcpy(yylval.lexeme, yytext);return BOOLFALSE;}
{variable} {//printf("%s",yytext);
strcpy(yylval.lexeme, yytext);return VARIABLE;}
"+" {//printf("%s",yytext);
return PLUS;}
"-" {//printf("%s",yytext);
return MINUS;}
"*" {//printf("%s",yytext);
return MUL;}
"/" {//printf("%s",yytext);
return DIV;}
"^" {//printf("%s",yytext);
return POW;}
";" {//printf("%s",yytext);
return SEP;}
"(" {//printf("%s",yytext);
return OPENB;}
")" {//printf("%s",yytext);
return CLOSEB;}
"{" {//printf("%s",yytext);
return OPENCB;}
"}" {//printf("%s",yytext);
return CLOSECB;}
" "|"\n" {//printf("%s",yytext);
}
. {//printf("%s",yytext);return yytext[0]; 
}

%%



