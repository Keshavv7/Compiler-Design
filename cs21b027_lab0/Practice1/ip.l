%{
	 // c declarations 
	 int count1 = 0;
	 int count2 = 0;
	 void myprint(char*, char*);
%}

OCT [0-7]
DEC [0-9]
LETTER [A-Fa-f]

%%
"int"									{myprint("keyword",yytext);}
"=" 									{myprint("operator",yytext);}
{OCT}+ 									{ myprint("octal", yytext); count1++;}
({DEC}|{LETTER})*							{ myprint("hexadecimal", yytext); count2++;}

. ;

%%

int main()
{
	 yylex();
	 printf("\n number of Octal nums in my program  %d",count1);
	 printf("\n number of Hexadecimal nums in my program  %d",count2);
	 return 0;
}

int yywrap() {
    return 1;
}


void myprint(char* token, char* lexeme){

	printf("\n %s %s\n", token, lexeme);

}
