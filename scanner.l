%{

#include <stdio.h> 
int nint = 0; 
int pint = 0;  
%} 

digit [0-9]

%% 
{digit}+(\.{digit}+)?([Ee][+-]?{digit}+)? {printf("%s %d",yytext, yyleng); pint++;}

.* ;
%% 
int main(int argc, char *argv[]) 
{ 
	if (argc != 2) {
		 printf("\nUsgae: <exefile> <inputfile>");
		 exit(0);
	}
	yyin = fopen(argv[1], "r");
	yylex(); 
	printf("Number of positive intergers: %d\n", pint);
	printf("Number of negative intergers: %d\n\n", nint);
	return 0; 
} 
