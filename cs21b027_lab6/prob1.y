%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int line = 1;
int yylex();
void yyerror(const char* s);
extern char* yytext;
extern FILE* yyin;
%}

%token INC DEC ASSIGN PLUS MINUS MUL DIV LPAREN RPAREN ID NUM SEMICOLON EOL


%%

input: stmt input 
    | stmt 
    | error SEMICOLON { printf("Line %d: INVALID\n", line); line++; } EOL input
    | error SEMICOLON { printf("Line %d: INVALID\n", line); line++; }
    | error EOL { printf("Line %d: INVALID\n", line); line++; } input
    ;

stmt: assign_stmt SEMICOLON EOL { printf("Line %d: VALID: Assignment Statement\n", line); line++;}
        | pre_expr SEMICOLON EOL { printf("Line %d: VALID: Pre-Operation\n", line); line++;}
        | post_expr SEMICOLON EOL { printf("Line %d: VALID: Post-Operation\n", line); line++;}
        | assign_stmt SEMICOLON { printf("Line %d: VALID: Assignment Statement\n", line); line++;}
        | pre_expr SEMICOLON { printf("Line %d: VALID: Pre-Operation\n", line); line++;}
        | post_expr SEMICOLON { printf("Line %d: VALID: Post-Operation\n", line); line++;}
        | assign_stmt EOL { printf("Line %d: INVALID: No semicolon\n", line); line++; }
        | pre_expr EOL { printf("Line %d: INVALID: No semicolon\n", line); line++; }
        | post_expr EOL { printf("Line %d: INVALID: No semicolon\n", line); line++; }
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

factor: MINUS LPAREN expr RPAREN
    | LPAREN expr RPAREN
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