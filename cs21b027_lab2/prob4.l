%{
#include <stdio.h>
%}

%option noyywrap
//%option prefix="prob4"

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

/*

int main() {
    prob4lex();
    return 0;
}
*/

int main(int argc, char** argv) {
    if (argc!=2){
    	fprintf(stderr, "Usage: %s input_file\n", argv[0]);
    	return 1;
    }
    FILE* inputFile = fopen(argv[1], "r");
    if (!inputFile) {
        fprintf(stderr, "Error opening the input file.\n");
        return 1;
    }
    
    yyin = inputFile;
    yylex();
    
    fclose(inputFile);
    return 0;
}

