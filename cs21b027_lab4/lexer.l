%{
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef enum {
    PLUS,
    MULTIPLY,
    IDENTIFIER,
    INTEGER,
    FLOAT,
    LEFT,
    RIGHT,
    OTHER,
    END_OF_INPUT
} TokenType;


typedef struct {
    TokenType type;
    char *value;
} Token;

Token current_token; // Global variable to store the current token

bool E();
bool EPrime();
bool T();
bool TPrime();
bool F();


int yylex();

Token getToken() {
    Token token;

    int token_type = yylex();
    if (token_type == PLUS) {
        token.type = PLUS;
        token.value = "+";
    } else if (token_type == MULTIPLY) {
        token.type = MULTIPLY;
        token.value = "*";
    } else if (token_type == LEFT) {
        token.type = LEFT;
        token.value = "(";
    } else if (token_type == RIGHT) {
        token.type = RIGHT;
        token.value = ")";
    } else if (token_type == IDENTIFIER) {
        token.type = IDENTIFIER;
        token.value = strdup(yytext);
    } else if (token_type == INTEGER) {
        token.type = INTEGER;
        token.value = strdup(yytext);
    } else if (token_type == FLOAT) {
        token.type = FLOAT;
        token.value = strdup(yytext);
    } else if (token_type == OTHER) {
        token.type = OTHER;
        token.value = strdup(yytext);
    } else {
        token.type = END_OF_INPUT;
        token.value = "";
    }
    return token;
}

// Recursive Descent Grammar Implementation
// Start

bool E() {
    if (T() && EPrime()) {
        return true;
    }
    return false;
}

bool EPrime() {
    if (current_token.type == PLUS) {
        current_token = getToken();
        if (T() && EPrime()) {
            return true;
        }
        return false;
    }
    return true; // Epsilon
}

bool T() {
    if (F() && TPrime()) {
        return true;
    }
    return false;
}

bool TPrime() {
    if (current_token.type == MULTIPLY) {
        current_token = getToken();
        if (F() && TPrime()) {
            return true;
        }
        return false;
    }
    return true; // Epsilon
}

bool F() {
    if (current_token.type == IDENTIFIER || current_token.type == INTEGER || current_token.type == FLOAT) {
        current_token = getToken();
        return true;
    }
    else if (current_token.type == LEFT){
        current_token = getToken();
        if (E() && current_token.type == RIGHT) {
            current_token = getToken();
            return true;
        }
    }
    return false;
}

// Recursive Descent Grammar Implementation
// End

int main(int argc, char* argv[]) {
    
    if (argc!=2){
		printf("Usage: %s <input_file>\n", argv[0]);
		return 1;
	}
    FILE* inputFile = fopen(argv[1], "r");
    if (inputFile == NULL) {
        printf("Error opening input file.\n");
	return 1;
    }

    yyin = inputFile;
    
    char line[256]; // Setting max input size to 256
    int line_number = 1; // Current input being processed

    while (fgets(line, sizeof(line), inputFile) != NULL) {
        if (line[strlen(line) - 1] == '\n') {
            line[strlen(line) - 1] = '\0';
        }
        printf("Input %d: %s -> ", line_number, line);

        yy_scan_string(line); // Set input to the current line
        current_token = getToken(); // Initialize the lookahead token

        if (E() && current_token.type == END_OF_INPUT) {
            printf("SUCCESS\n\n");
        } else {
            printf("FAIL\n\n");
        }

        line_number++;
    }
    
    fclose(inputFile);

    return 0;
}

%}

%option noyywrap

%%
\+              { return PLUS; }
\*              { return MULTIPLY; }
[_a-zA-Z][_a-zA-Z0-9]*               { return IDENTIFIER; }
[0-9]+          { return INTEGER; }
[0-9]\.[0-9]+   { return FLOAT; }
\(              { return LEFT; }
\)              { return RIGHT; }
[ \t]+           { /* Ignore whitespace */ }
.               { return OTHER; }
<<EOF>>         { return END_OF_INPUT; }
%%








