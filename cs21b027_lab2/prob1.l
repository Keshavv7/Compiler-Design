%{
#include <stdio.h>
#include <string.h>

struct SymbolNode{
	char token[100];
	char lexeme[100];
	char type[50];
	int size;
	int line;
};

struct SymbolNode symTable[1000];
int nodeCount = 0;

void displayToken(const char *token, const char *lexeme) {
	printf("Token: %s\tLexeme: %s\n", token, lexeme);
}

void addToSymbolTable(char* token, char* lexeme, char* type, int size, int line_no){
	strcpy(symTable[nodeCount].token, token);
	strcpy(symTable[nodeCount].lexeme, lexeme);
	strcpy(symTable[nodeCount].type, type);
	symTable[nodeCount].size = size;
	symTable[nodeCount].line = line_no;
	nodeCount++;
}


int line_no = 1;
%}

%option noyywrap
%option yylineno

DIGIT	[0-9]
LETTER	[_a-zA-Z]
IDENTIFIER	{LETTER}({LETTER}|{DIGIT})*
INTEGER	{DIGIT}+
FLOAT	{DIGIT}+"."{DIGIT}+
CHAR	\'([^\\\N]|(\\.))*\'
STRING	\"([^\\\N]|(\\.))*\"
INCLUDE	^"#include"[ ]*<.+\.h>
COMMENTS	(/\*([^*]|[\r\n]|(\*+([^*/]|[\r\n])))*\*+/)|(//.*)


%%
{INTEGER}   {
                addToSymbolTable("INTCONST", yytext, "int", sizeof(int), line_no);
                printf("INTEGER: %s\n", yytext);
            }
            
{FLOAT}     {
                addToSymbolTable("FLOATCONST", yytext, "float", sizeof(float), line_no);
                printf("FLOAT: %s\n", yytext);
            }
            
{CHAR}      {
                addToSymbolTable("CHARCONST", yytext, "char", sizeof(char), line_no);
                printf("CHAR: %s\n", yytext);
            }
            
{STRING}    {
                addToSymbolTable("STRCONST", yytext, "string", sizeof(char) * strlen(yytext), line_no);
                printf("STRING: %s\n", yytext);
            }
            
            
"int"|"float"|"char"|"void"|"return"|"if"|"else"|"while"|"for" {
                addToSymbolTable("KEYWORD", yytext, "n/a", sizeof(yytext), line_no);
                printf("KEYWORD: %s\n", yytext);
            }
            
{IDENTIFIER} {
                addToSymbolTable("VARIABLE", yytext, "identifier", sizeof(yytext), line_no);
                printf("IDENTIFIER: %s\n", yytext);
            }

{INCLUDE}   {
		addToSymbolTable("HEADER", yytext, "header", sizeof(yytext), line_no);
		printf("HEADER: %s\n", yytext);
	     }

            
([-+*/=<>()[\].;{},]) {
                printf("OPERATOR/DELIMITER: %c\n", yytext[0]);
            }
            
[\n]+	    {
		line_no++;
		printf("\nLine %d: \n", line_no); 
	    }
	    
[ \t]+	;

.           {
                printf("Invalid token: %s\n", yytext);
            }
%%


int main(int argc, char* argv[]){
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
    	
    	printf("Line 1: \n");

    	yylex();

    	fclose(inputFile);

    	// Write symbol table to a file
    	FILE* symbolTableFile = fopen("symbol_table.txt", "w");
    	for (int i = 0; i < nodeCount; i++) {
		fprintf(symbolTableFile, "Line: %d, Token: %s, Lexeme: %s, Type: %s, Size: %d\n", symTable[i].line, symTable[i].token, symTable[i].lexeme, symTable[i].type, symTable[i].size);
    	}
    	fclose(symbolTableFile);

    	return 0;
}

