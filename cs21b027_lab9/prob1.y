%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define N 1000
int yylex();
int yyerror(char *);
int eflag=0;
extern FILE * yyin;


struct node{
	char string[25];
	int dval;
	char lexval[25];
	char tok[20];
	//struct node* left;
	//struct node* right;	
};

//void postorder(struct node*);
//void inorder(struct node*);
int count=0;
struct node* gentemp();
void genlabel();


int l=0;

//For stack implementation to keep track of L0, L1...:
int toptrue = -1;
int topfalse = -1;
int topendofif = -1;
int topstartofwhile = -1;
int topifwhilefalse = -1;

int iftrue[N]; //if boolexpr is true then we go to L addr of the top elem of this
int iffalse[N]; //if boolexpr is false then we go to L addr of the top elem of this
int endofif[N]; //if boolexpr is false and we have an else stmt in it then we go to iffasle top elem for else case but if else is there but the condition is true, then to skip else we go to top of endofoif.
int startofwhile[N]; //at the start of while we have a label that we would reach when loop is once completed;
int ifwhilefalse[N]; //if boolexpr is wrong here then we skip the total while loop and continue further
void push(int , int);   //push(x, y) y=0 for iffalse array, y=1=>iftrue, y=-1=>endofif, y=2=>startofwhile, y=3=>ifwhilefalse,x is num to push   
int pop(int);       
int peek(int);   
///////////////

%}

%union {
	int dval;
	char lexeme[20];
	struct node* Node;	 
}

%token POSNUMBER FLOAT PLUS MINUS SEP MUL DIV POW OPENB CLOSEB DOUBLEPLUS  DOUBLEMINUS VARIABLE EQUALS IF ELSE OPENCB CLOSECB NOT DOUBLEEQUAL NOTEQUAL LESSTHANOREQUALTO GREATERTHANOREQUALTO LESSTHAN GREATERTHAN BOOLTRUE BOOLFALSE AND OR WHILE
//%type <dval> POSNUMBER
//%type <lexeme> VARIABLE 
%type <Node> E
%type <Node> T
%type <Node> F
%type <Node> K
%type <Node> B
%type <Node> N
%type <Node> I
%type <Node> V
%type <Node> ABCD
%type <Node> RELOP
%type <Node> BOOLOP
%type <Node> BOOLEXPR
%type <Node> BOOL
%type <Node> STMT
%type <Node> STMTS
%type <Node> WHILE //i donot know why but stopped warnings that never affected the output;
%type <Node> IF //i donot know why but stopped warnings that never affected the output;
%nonassoc P
%nonassoc Q
%%

STMTS: STMT SEP {//printf(" === NORMAL STMT\n");
		//printf("====INORDER====\n");
		//inorder($1);	
		//printf("\n====POSTORDER====\n");
		//postorder($1);
		//printf("completed nigaa!\n");	
		} STMTS

	| IF OPENB BOOLEXPR CLOSEB {
		genlabel();
		printf("\nIF ( %s === true) go to L%d:\nELSE go to L%d:\n", $3->string, peek(1), peek(0));
		} OPENCB {
		printf("\nL%d:\n", pop(1));
		} STMTS CLOSECB  FURTHERIF

	| WHILE {push(l++, 2); printf("\nL%d:\n",peek(2));} OPENB BOOLEXPR CLOSEB {
		push(l++,3);
		printf("\nIF ( %s === false) go to L%d:\n",$4->string, peek(3));
		} OPENCB STMTS CLOSECB {
		printf("\ngo to L%d:\n",pop(2));
		printf("\nL%d:\n",pop(3));		
		} STMTS 

	|{};

FURTHERIF: ELSE {
		push(l++, -1);
		printf("go to L%d:\n", peek(-1));
		printf("\nL%d:\n", pop(0));
		} OPENCB STMTS CLOSECB {
		printf("\nL%d:\n", pop(-1));
		} STMTS
	| 	{ //this is for the case of only if statement without any else
		printf("L%d:\n", pop(0));
		}STMTS;


STMT: V EQUALS E {
		/*struct node* n = malloc(sizeof(struct node));
		$$ = n;
		n->left = $1;
		n->right = $3;
		strcpy(n->lexval, "=");
		strcpy(n->tok, "EQUALS");*/

		$$ = gentemp();
		printf("%s = %s\n", $1->lexval,$3); 
		}
	|ABCD {$$=$1;};

E: E PLUS T {
		/*struct node* n = malloc(sizeof(struct node));
		$$ = n;
		n->left = $1;
		n->right = $3;
		strcpy($$->lexval, "+");
		strcpy($$->tok, "PLUS");*/

		$$ = gentemp();
		printf("%s = %s+%s\n", $$, $1,$3); 
		}
  | E MINUS T {
		/*struct node* n = malloc(sizeof(struct node));
		$$ = n;
		$$->left = $1;
		$$->right = $3;
		strcpy($$->lexval, "-");
		strcpy($$->tok, "MINUS");*/
		
		$$ = gentemp();
		printf("%s = %s-%s\n", $$, $1,$3); 
		}
  | T{$$ = $1;}
  ;

T: T MUL F {/*struct node* n = malloc(sizeof(struct node));
			$$ = n;
			$$->left = $1;
			$$->right = $3;
			strcpy($$->lexval, "*");
			strcpy($$->tok, "MUL");*/
		$$ = gentemp();
		printf("%s = %s*%s\n", $$, $1,$3); 
		}
  | T DIV F {/*struct node* n = malloc(sizeof(struct node));
			$$ = n;
			$$->left = $1;
			$$->right = $3;
			strcpy($$->lexval, "/");
			strcpy($$->tok, "DIV");
		*/
		
		$$ = gentemp();
		printf("%s = %s/%s\n", $$, $1,$3); 
		}
  | F{$$ = $1;}
  ;

F: K POW F {/*struct node* n = malloc(sizeof(struct node));
			$$ = n;
			$$->left = $1;
			$$->right = $3;
			strcpy($$->lexval, "^");
			strcpy($$->tok, "POW");
		*/$$ = gentemp();
		printf("%s = %s^%s\n", $$, $1,$3); 
		}
  | K{$$ = $1;};

K: V {$$ = $1;}
  | I {$$ = $1;}
  | B {$$ = $1;}
  | N {$$ = $1;};

N: ABCD {$$=$1;}

  | OPENB E CLOSEB {$$=$2;}
  | MINUS OPENB E CLOSEB {/*
struct node* n1 = malloc(sizeof(struct node));
			n1->left = NULL;
			n1->right = NULL;
			n1->dval=(-1);
			strcpy(n1->tok, "MINBRAC");
struct node* n0 = malloc(sizeof(struct node));
			$$ = n0;
			n0->left = n1;
			n0->right = $3;
			strcpy(n0->lexval, "*");
			strcpy(n0->tok, "BRACKETTERM");
		*/}; 

ABCD: DOUBLEPLUS V {/*struct node* n = malloc(sizeof(struct node));
			$$ = n;
			$$->left = NULL;
			$$->right = NULL;

			char temp[25];
			char ch[2]; strcpy(ch, "++");
			
			strcat(temp, ch);
			strcat(temp, $2->lexval);
			strcpy($$->lexval, temp);
			strcpy($$->tok, "VARIABLE");
		*/

		$$ = gentemp();
		printf("%s = %s+1\n", $$->string, $2->string);
		printf("%s = %s\n", $2->lexval, $$->string); 
		strcpy($$->lexval, $2->lexval);
		}
  | DOUBLEMINUS V {/*struct node* n = malloc(sizeof(struct node));
			$$ = n;
			$$->left = NULL;
			$$->right = NULL;
			char temp[25];
			char ch[2]; strcpy(ch, "--");
			strcat(temp, ch);
			strcat(temp, $2->lexval);
			strcpy($$->lexval, temp);
			strcpy($$->tok, "VARIABLE");
		*/

		$$ = gentemp();
		printf("%s = %s-1\n", $$->string, $2->string);
		printf("%s = %s\n", $2->lexval, $$->string); 
		strcpy($$->lexval, $2->lexval);
		}

  | V DOUBLEPLUS {/*struct node* n = malloc(sizeof(struct node));
			$$ = n;
			$$->left = NULL;
			$$->right = NULL;
			char ch[2]; strcpy(ch, "++");
			strcat($1->lexval, ch);
			strcpy($$->lexval, $1->lexval);
			strcpy($$->tok, "VARIABLE");
		*/

		$$ = gentemp();
		printf("%s = %s+1\n", $$->string, $1->string);
		printf("%s = %s\n", $1->lexval, $$->string); 
		$$ = $1;
		}

  |V DOUBLEMINUS {/*struct node* n = malloc(sizeof(struct node));
			$$ = n;
			$$->left = NULL;
			$$->right = NULL;
			char ch[2]; strcpy(ch, "--");
			strcat($1->lexval, ch);
			strcpy($$->lexval, $1->lexval);
			strcpy($$->tok, "VARIABLE");
		*/
		$$ = gentemp();
		printf("%s = %s-1\n", $$->string, $1->string);
		printf("%s = %s\n", $1->lexval, $$->string); 
		//strcpy($$->lexval, $1->string);
		$$ = $1;
		};

I: FLOAT{}
	| POSNUMBER {/*struct node* n = malloc(sizeof(struct node));
			$$ = n;
			$$->left = NULL;
			$$->right = NULL;
			$$->dval = yylval.dval;
			strcpy($$->tok, "NUMBER");*/
		$$ = gentemp();
		$$->dval = yylval.dval;
		printf("%s = %d\n", $$, yylval.dval);  
		}
	| MINUS POSNUMBER {/*struct node* n = malloc(sizeof(struct node));
			$$ = n;
			$$->left = NULL;
			$$->right = NULL;
			$$->dval = (-1*$2->dval);
			strcpy($$->tok, "NUMBER");
		*/
		$$ = gentemp();
		$$->dval = -1*yylval.dval;
		printf("%s = %d\n", $$, $$->dval); 
	};

V: VARIABLE{/*struct node* n = malloc(sizeof(struct node));
			$$ = n;
			$$->left = NULL;
			$$->right = NULL;
			strcpy($$->lexval, yylval.lexeme);
			strcpy($$->tok, "VARIABLE");
		*/
		
		$$ = gentemp();
		strcpy($$->lexval,yylval.lexeme);
		printf("%s = %s\n", $$->string, yylval.lexeme); 
		}
	| MINUS VARIABLE {/*struct node* n = malloc(sizeof(struct node));
			$$ = n;
			$$->left = NULL;
			$$->right = NULL;
			char d[1]; strcpy(d, "-");
			strcat(d, $2->lexval);
			strcpy($$->lexval, d);
			strcpy($$->tok, "VARIABLE");
		*/
		$$ = gentemp();
	char temp[30] = "-";
		strcat(temp, yylval.lexeme);
		printf("%s = %s\n", $$->string, yylval.lexeme);
		printf("%s = -1*%s\n", $$->string, $$->string); 

		strcpy($$->lexval,temp);
	};

B: BOOLTRUE {
		/*struct node* n = malloc(sizeof(struct node));
		$$ = n;
		//$$->left = NULL;
		//$$->right = NULL;
		strcpy($$->lexval, yylval.lexeme);
		strcpy($$->tok, "BOOLTRUE");*/
		$$ = gentemp();
		strcpy($$->lexval,yylval.lexeme);
		printf("%s = %s\n", $$->string, yylval.lexeme); 
		}
	| BOOLFALSE{/*
		struct node* n = malloc(sizeof(struct node));
		$$ = n;
		//$$->left = NULL;
		//$$->right = NULL;
		strcpy($$->lexval, yylval.lexeme);
		strcpy($$->tok, "BOOLFALSE");*/
		$$ = gentemp();
		strcpy($$->lexval,yylval.lexeme);
		printf("%s = %s\n", $$->string, yylval.lexeme); 
		}

	
	;

BOOLEXPR: BOOL BOOLOP BOOLEXPR {
	
		$$ = gentemp();
		printf("%s = %s %s %s\n", $$->string, $1->string, $2->lexval, $3->string);
		}
	 | BOOL {
	
		$$ = $1;
		}

	;

BOOL: E RELOP E {
	
		$$ = gentemp();
		printf("%s = %s %s %s\n", $$->string, $1->string, $2->lexval, $3->string);
	}	
	| E {
		$$ = gentemp();
		printf("%s = %s\n", $$->string, $1->string);
			
	}
	| OPENB BOOLEXPR CLOSEB {$$=$2;}
	| NOT BOOL {
		$$ = gentemp();
		printf("%s = !%s\n", $$->string, $2->string);
		}
	;

BOOLOP: AND {
		struct node* n = malloc(sizeof(struct node));
		$$ = n;
		//$$->left = NULL;
		//$$->right = NULL;
		strcpy($$->lexval, yylval.lexeme);
		strcpy($$->tok, "BOOLOP");
		}
	| OR {
		struct node* n = malloc(sizeof(struct node));
		$$ = n;
		//$$->left = NULL;
		//$$->right = NULL;
		strcpy($$->lexval, yylval.lexeme);
		strcpy($$->tok, "BOOLOP");
		}
	; 

RELOP: LESSTHAN{
		struct node* n = malloc(sizeof(struct node));
		$$ = n;
		//$$->left = NULL;
		//$$->right = NULL;
		strcpy($$->lexval, yylval.lexeme);
		strcpy($$->tok, "RELOP");
		}
	| GREATERTHAN {
		struct node* n = malloc(sizeof(struct node));
		$$ = n;
		//$$->left = NULL;
		//$$->right = NULL;
		strcpy($$->lexval, yylval.lexeme);
		strcpy($$->tok, "RELOP");
		}
	| LESSTHANOREQUALTO {
		struct node* n = malloc(sizeof(struct node));
		$$ = n;
		//$$->left = NULL;
		//$$->right = NULL;
		strcpy($$->lexval, yylval.lexeme);
		strcpy($$->tok, "RELOP");
		}
	| GREATERTHANOREQUALTO {
		struct node* n = malloc(sizeof(struct node));
		$$ = n;
		//$$->left = NULL;
		//$$->right = NULL;
		strcpy($$->lexval, yylval.lexeme);
		strcpy($$->tok, "RELOP");
		}
	| DOUBLEEQUAL {
		struct node* n = malloc(sizeof(struct node));
		$$ = n;
		//$$->left = NULL;
		//$$->right = NULL;
		strcpy($$->lexval, yylval.lexeme);
		strcpy($$->tok, "RELOP");
		}
	| NOTEQUAL{
		struct node* n = malloc(sizeof(struct node));
		$$ = n;
		//$$->left = NULL;
		//$$->right = NULL;
		strcpy($$->lexval, yylval.lexeme);
		strcpy($$->tok, "RELOP");
		}
	;
%%
/*
void inorder(struct node* Node){
	if(Node==NULL) return;
	inorder(Node->left);
	if(strcmp(Node->tok, "NUMBER")==0 || strcmp(Node->tok, "MINBRAC")==0){
		printf("\n%s\t\t%d", Node->tok, Node->dval);	
	}
	else{
		if(strcmp(Node->tok, "VARIABLE")==0 || strcmp(Node->tok, "BRACKETTERM")==0) printf("\n%s\t%s", Node->tok, Node->lexval);
		else printf("\n%s\t\t%s", Node->tok, Node->lexval);
	}
	inorder(Node->right);
}


void postorder(struct node* Node){
	if(Node==NULL) return;
	postorder(Node->left);
	postorder(Node->right);
	if(strcmp(Node->tok, "NUMBER")==0 || strcmp(Node->tok, "MINBRAC")==0){
		printf("\n%s\t\t%d", Node->tok, Node->dval);	
	}
	else{
		if(strcmp(Node->tok, "VARIABLE")==0 || strcmp(Node->tok, "BRACKETTERM")==0) printf("\n%s\t%s", Node->tok, Node->lexval);
		else printf("\n%s\t\t%s", Node->tok, Node->lexval);
		
	}
}*/

void genlabel(){
	push(l++, 1);
	push(l++, 0);
}

struct node* gentemp(){
	char word[100]="t";
	struct node* n = malloc(sizeof(struct node));
	char temp[50];
	sprintf(temp, "%d", count++);
	strcat(word, temp);
	strcpy(n->string, word);
	return n;
}
int yyerror(char *s){
	while(yylex()!=SEP){;};
 	printf(" === Invalid\n");
	yyparse();
}


int main(int argc, char* argv[]){
	if(argc >1){
		FILE *fp = fopen(argv[1], "r");
		if(fp) yyin = fp;	
	}

	yyparse();
printf("    Completed!!!\n\n");
	return 0;
}

void push(int x, int t){

if(t==-1){
	if(topendofif == N-1)
	        printf("Overflow State: can't add more elements into the stack\n");
        else{
        	topendofif+=1;
        	endofif[topendofif] = x;
	}
}
else if(t==1){

    if(toptrue == N-1)
        printf("Overflow State: can't add more elements into the stack\n");
    else{
        toptrue+=1;
        iftrue[toptrue] = x;

    }
}else if(t==0){
    if(topfalse == N-1)
        printf("Overflow State: can't add more elements into the stack\n");
    else{
        topfalse+=1;
        iffalse[topfalse] = x;

    }
}else if(t==2){
    if(topstartofwhile == N-1)
        printf("Overflow State: can't add more elements into the stack\n");
    else{
        topstartofwhile+=1;
        startofwhile[topstartofwhile] = x;

    }
}else if(t==3){
    if(topifwhilefalse == N-1)
        printf("Overflow State: can't add more elements into the stack\n");
    else{
        topifwhilefalse+=1;
        ifwhilefalse[topifwhilefalse] = x;

    }
}
}



int pop(int t){

if(t==-1){

    if(topendofif == N-1)
        printf("Overflow State: can't add more elements into the stack\n");
    else{
        int x = endofif[topendofif];
        topendofif-=1;
        return x;
    }
}
else if(t==1){

    if(toptrue == N-1)
        printf("Overflow State: can't add more elements into the stack\n");
    else{
        int x = iftrue[toptrue];
        toptrue-=1;
        return x;
    }
}else if(t==0){
    if(topfalse == N-1)
        printf("Overflow State: can't add more elements into the stack\n");
    else{
        int x = iffalse[topfalse];
        topfalse-=1;
        return x;
    }
}else if(t==2){
    if(topstartofwhile == N-1)
        printf("Overflow State: can't add more elements into the stack\n");
    else{
        int x = startofwhile[topstartofwhile];
        topstartofwhile-=1;
        return x;
    }
}else if(t==3){
    if(topifwhilefalse == N-1)
        printf("Overflow State: can't add more elements into the stack\n");
    else{
        int x = ifwhilefalse[topifwhilefalse];
        topifwhilefalse-=1;
        return x;
    }
}
    return -1;
}


int peek(int t){
if(t==-1){
    int x = endofif[topendofif];
    return x;
}
else if(t==1){
    int x = iftrue[toptrue];
    return x;
}
else if(t==0){
    int x = iffalse[topfalse];
    return x;
}
else if(t==2){
    int x = startofwhile[topstartofwhile];
    return x;
}
else if(t==3){
    int x = ifwhilefalse[topifwhilefalse];
    return x;
}

}
