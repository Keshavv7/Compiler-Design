%{
#include <stdio.h>

int xCount = 0;
int yCount = 0;
int invalid = 0;

%}

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

int main() {
    yylex();
    return 0;
}

