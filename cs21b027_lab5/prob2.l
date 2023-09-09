%{
#include "y.tab.h"
int inValid = 1; // Assume it's invalid unless proven otherwise
%}

%option noyywrap

DATE [0][1-9]|[12][0-9]|3[01]
MONTH Jan|Feb|Mar|Apr|May|Jun|Jul|Aug|Sep|Oct|Nov|Dec
YEAR [0-9][0-9][0-9][0-9]

%%

{DATE}"-"{MONTH}"-"{YEAR}   { inValid = 0; return PROPER; }
[^;\n]+     { if (inValid) return OTHER; else return yytext[0]; }
[ \t\n]+          { /* Ignore whitespace and tabs */ }
";"               { inValid = 1; return SEMICOLON; }

%%