%{
#include "y.tab.h"
int inValid = 1; // Assume it's invalid unless proven otherwise
%}

%option noyywrap

NUMBER ([0-9]+|([0-9]*\.[0-9]+)([eE][-+]?[0-9]+)?)

%%

[ \t\n]+          /* Ignore whitespace and tabs */
{NUMBER}("+"|"-")"i"{NUMBER} { inValid = 0; return COMPLEX1; }
{NUMBER}("+"|"-"){NUMBER}"i" { inValid = 0; return COMPLEX2; }
("i"{NUMBER}|{NUMBER}"i")    { inValid = 0; return IMAGINARY; }
{NUMBER}                     { inValid = 0; return REAL; }
[^;\n]+                      { if (inValid) return OTHER; else return yytext[0]; }
";"                          { inValid = 1; return SEMICOLON; }

%%

