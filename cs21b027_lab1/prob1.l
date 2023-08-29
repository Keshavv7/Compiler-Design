%{
#include <stdio.h>
%}

%option noyywrap

%%

	/* Match patterns */
^.*111.*$ {
    int found00 = 0;  // Flag to check if "00" is found
    int i;
    for (i = 0; i < yyleng - 1; i++) {
        if (yytext[i] == '0' && yytext[i + 1] == '0') {
            found00 = 1;
            break;
        }
    }
    
    if (!found00) {
        printf("ACCEPT\n");
    } else {
        printf("REJECT\n");
    }
}

[0|1]* {
    printf("REJECT\n");
}

%%

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

