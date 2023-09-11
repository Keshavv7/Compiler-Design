%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int yylex();
void yyerror(const char* s);
extern char* yytext;
extern FILE* yyin;
%}

%token INC DEC ASSIGN PLUS MINUS MUL DIV LPAREN RPAREN ID NUM SEMICOLON


%%

input: stmt SEMICOLON input | stmt SEMICOLON | error SEMICOLON { printf("INVALID\n"); } input | error SEMICOLON { printf("INVALID\n"); }
    ;

stmt: assign_stmt { printf("VALID: Proper Assignment Statement\n"); }
        | pre_expr { printf("VALID: Proper Pre-Operation\n"); }
        | post_expr { printf("VALID: Proper Post-Operation\n"); }
        ;

assign_stmt: ID ASSIGN expr
            ;

pre_expr: INC ID
        | DEC ID
        ;

post_expr: ID INC
        | ID DEC
        ;

expr: expr PLUS term
    | expr MINUS term
    | term
    ;

term: term MUL factor
    | term DIV factor
    | factor
    ;

factor: LPAREN expr RPAREN
    | ID
    | NUM
    | pre_expr
    | post_expr
    ;


%%

void yyerror(const char* s) {
    //printf("INVALID: %s\n", s);
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