%{
#include <stdio.h>

int xCount = 0;
int yCount = 0;
int invalid = 0;

%}
/*
%option noyywrap
%option prefix="prob2"
*/
%%


[xyz] {
    if (yytext[0] == 'x') {
        xCount++;
    } else if (yytext[0] == 'y') {
        yCount++;
    } 
}

[^xyz\n] {
    invalid = 1;
}

\n {
    if (invalid==1){
    	printf("reject\n");
    }else{
	    if (xCount % 2 == yCount % 3) {
		printf("accept\n");
	    } else {
		printf("reject\n");
	    }
    }
    xCount = 0;
    yCount = 0;
}

%%
/*
int main() {
    prob2lex();
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

