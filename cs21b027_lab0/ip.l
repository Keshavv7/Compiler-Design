%{
	 // c declarations 
	 int count = 0;
	 void myprint(char*, char*);
%}

DIGIT [0-9]
LETTER [A-Za-z]

%%
"int"									{myprint("keyword",yytext);}
"=" 									{myprint("operator",yytext);}
{DIGIT}+ 							{ myprint("intconst", yytext); count++;}
{LETTER}+({DIGIT}|{LETTER})*	{ myprint("indentifier", yytext); }

. ;

%%

int main()
{
	 yylex();
	 printf("\n number of intconst in my program  %d",count);
	 return 0;
}

void myprint(char* token, char* lexeme){

	printf("\n %s %s\n", token, lexeme);

}
