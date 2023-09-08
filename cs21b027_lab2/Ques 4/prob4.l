%{
#include <stdio.h>
%}

%%
"http://"|"https://"|"ftp://"|"mailto:"|"file://" {
    printf("Scheme: %s\n", yytext);
}

[A-Za-z0-9._%+-]+:[A-Za-z0-9._%+-]+@ {
    printf("Username and Password: %s\n", yytext);
}

[0-9A-Za-z.-]+ {
    printf("Host: %s\n", yytext);
}

":"[0-9]+ {
    printf("Port: %s\n", yytext);
}

"/"[A-Za-z0-9_/.-]* {
    printf("Path: %s\n", yytext);
}

"?"[A-Za-z0-9_=&]* {
    printf("Query Parameters: %s\n", yytext);
}

"#"[A-Za-z0-9_-]* {
    printf("Fragment: %s\n", yytext);
}

. {
    printf("Invalid: %s\n", yytext);
}
%%

int main() {
    yylex();
    return 0;
}

