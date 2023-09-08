%{
#include <stdio.h>

char beforeZ;
int prior = 0;
int later = 0;
int z_crossed = 0;
char afterZ;
int invalid = 0;

%}

%%


[abcd] {
    if (z_crossed == 0) {
        beforeZ = yytext[0];
        prior++;
    } else {
    	afterZ = yytext[0];
        later++;
    } 
}

[z] {
	if (z_crossed==1){
	   invalid = 1;
	}
	else{
	   z_crossed = 1;
	}
}

[^abcdz\n] {
    invalid = 1;
}

\n {
    if (invalid==1){
    	printf("reject\n");
    }else{
	    if (prior>=2 && later>=2 && z_crossed==1 && beforeZ==afterZ) {
		printf("accept\n");
	    } else {
		printf("reject\n");
	    }
    }
    prior = 0;
    later = 0;
    z_crossed = 0;
    invalid = 0;
}

%%

int main() {
    yylex();
    return 0;
}

