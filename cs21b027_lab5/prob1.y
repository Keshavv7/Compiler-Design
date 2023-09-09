%{
#include <stdio.h>
int yylex();
void yyerror(const char* s);
extern FILE* yyin;
%}

%token OTHER COMPLEX1 COMPLEX2 IMAGINARY REAL SEMICOLON 

%%

input: complex_expr SEMICOLON input | complex_expr | incorrect_expr SEMICOLON input | incorrect_expr |/* Empty */

incorrect_expr: OTHER { printf("INVALID: Not a Number\n"); yyerrok; }

complex_expr: COMPLEX1 { printf("VALID: Proper Complex\n"); }
            | COMPLEX2 { printf("VALID: Proper Complex\n"); }
            | IMAGINARY { printf("VALID: Imaginary\n"); }
            | REAL { printf("VALID: Real\n"); }
            ;

%%


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
