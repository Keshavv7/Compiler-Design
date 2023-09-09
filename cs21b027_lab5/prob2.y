%{
#include <stdio.h>
int yylex();
void yyerror(const char* s);
extern FILE* yyin;
%}

%token PROPER OTHER SEMICOLON 

%%

input: date SEMICOLON input | rest SEMICOLON input | date | rest | /* Empty */

rest: OTHER   { printf("INVALID DATE\n"); yyerrok; }

date: PROPER { printf("CORRECT DATE\n"); }
            ;

%%

void yyerror(const char* s) {
    //fprintf(stderr, "Error: %s\n", s);
    fprintf(stderr, "INVALID\n");
}

int main(int argc, char** argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s input_file\n", argv[0]);
        return 1;
    }
    
    yyin = fopen(argv[1], "r");
    if (!yyin) {
        fprintf(stderr, "Error opening the input file.\n");
        return 1;
    }
    yyparse();
    fclose(yyin);
    return 0;
}
