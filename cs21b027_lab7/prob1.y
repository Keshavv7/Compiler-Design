%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void yyerror(char*);
int eflag = 0;
int yylex();
extern FILE * yyin;

struct node{
	struct node* left;
	struct node* right;
	char token[100];
	char lexeme[100];
	int val;
};

// traversals
void inorder(struct node*);
void preorder(struct node*);
void postorder(struct node*);
%}

%start StatementList

%token NUMBER VAR ADD SUB MUL DIV EQ PREPOSTADD PREPOSTSUB LPAREN RPAREN SEMICOLON
%union{
	char lexeme[100];
	int dval;
	struct node* n;
}

%type <dval> NUMBER
%type <lexeme> VAR
%type <n> StatementList
%type <n> S
%type <n> Statement
%type <n> Term
%type <n> Factor
%type <n> SIGNVal
%type <n> Val

%%

StatementList:
             StatementList S {
                                printf("\n\nAccepted EXPR. (See preorder, postorder, and inorder below)\nInorder traversal on the syntax tree is\n---------------------------------\nTOKEN\t\tLEXEME\n---------------------------------");
                                inorder($2);
				printf("\n\nPreorder traversal on the syntax tree is\n---------------------------------\nTOKEN\t\tLEXEME\n---------------------------------");
				preorder($2);
                                printf("\n\nPostorder traversal on the syntax tree is\n---------------------------------\nTOKEN\t\tLEXEME\n---------------------------------");
                                postorder($2);
				printf("\n\n\n");
                }
		| { $$ = NULL; } 
		;

S:
 	Statement SEMICOLON { $$ = $1; }
	| SEMICOLON { $$ = NULL; }
	;

Statement:
        VAR EQ Statement {
		struct node* n1 = (struct node*)malloc(sizeof(struct node));
		n1->left = NULL; n1->right = NULL;
		strcpy(n1->lexeme, $1); strcpy(n1->token, "ID"); 
		$$ = (struct node*)malloc(sizeof(struct node)); 
		$$->left = n1; $$->right = $3; 
		strcpy($$->lexeme, "="); strcpy($$->token, "OP"); 
	}
        | 
	Term { $$ = $1; } 
        ;

Term:
        Term ADD Factor { 
		$$ = (struct node*)malloc(sizeof(struct node)); 
		$$->left = $1; $$->right = $3; 
		strcpy($$->lexeme, "+"); strcpy($$->token, "OP"); 
	}
	| Term SUB Factor { 
		$$ = (struct node*)malloc(sizeof(struct node)); 
		$$->left = $1; $$->right = $3; 
		strcpy($$->lexeme, "-"); strcpy($$->token, "OP"); 
	}
        | Factor { $$ = $1; }
        ;

Factor:
        Factor MUL SIGNVal { 
		$$ = (struct node*)malloc(sizeof(struct node)); 
		$$->left = $1; $$->right = $3; 
		strcpy($$->lexeme, "*"); strcpy($$->token, "OP");
	}
	| Factor DIV SIGNVal { 
		$$ = (struct node*)malloc(sizeof(struct node)); 
		$$->left = $1; $$->right = $3; 
		strcpy($$->lexeme, "/"); strcpy($$->token, "OP"); 
	}
        | SIGNVal { $$ = $1; }
	;

SIGNVal:
        ADD Val { 
		$$ = (struct node*)malloc(sizeof(struct node)); 
		$$->left = NULL; $$->right = $2; 
		strcpy($$->lexeme, "+"); strcpy($$->token, "OP"); 
	}
	| SUB Val { 
		$$ = (struct node*)malloc(sizeof(struct node)); 
		$$->left = NULL; $$->right = $2; 
		strcpy($$->lexeme, "-"); strcpy($$->token, "OP"); 
	}
        | Val { $$ = $1; }
        ;

Val:
        VAR { 
		struct node* n = (struct node*)malloc(sizeof(struct node));
                $$ = n;
		$$->left = NULL; $$->right = NULL; 
		strcpy($$->lexeme, $1); strcpy($$->token, "ID"); 
	}
        | NUMBER { 
		struct node* n = (struct node*)malloc(sizeof(struct node));
                $$ = n;
		$$->left = NULL; $$->right = NULL;
		$$->val = $1; strcpy($$->token, "NUMBER");
	}
        | PREPOSTADD VAR { 
		struct node* n1 = (struct node*)malloc(sizeof(struct node)); 
		n1->left = NULL; n1->right = NULL; 
		strcpy(n1->lexeme, $2); strcpy(n1->token, "ID"); 
		struct node* n = (struct node*)malloc(sizeof(struct node));
                $$ = n;	
		$$->left = NULL; $$->right = n1; 
		strcpy($$->lexeme, "++"); strcpy($$->token, "OP"); 
	}
	| PREPOSTSUB VAR { 
		struct node* n1 = (struct node*)malloc(sizeof(struct node)); 
		n1->left = NULL; n1->right = NULL; 
		strcpy(n1->lexeme, $2); strcpy(n1->token, "ID"); 
		struct node* n = (struct node*)malloc(sizeof(struct node));
                $$ = n;
		$$->left = NULL; $$->right = n1; 
		strcpy($$->lexeme, "--"); 
		strcpy($$->token, "OP"); 
	}
        | VAR PREPOSTADD { 
		struct node* n1 = (struct node*)malloc(sizeof(struct node)); 
		n1->left = NULL; n1->right = NULL; 
		strcpy(n1->lexeme, $1); strcpy(n1->token, "ID"); 
		struct node* n = (struct node*)malloc(sizeof(struct node));
                $$ = n;
		$$->left = n1; $$->right = NULL; 
		strcpy($$->lexeme, "++"); strcpy($$->token, "OP"); 
	}
	| VAR PREPOSTSUB { 
		struct node* n1 = (struct node*)malloc(sizeof(struct node)); 
		n1->left = NULL; n1->right = NULL; 
		strcpy(n1->lexeme, $1); strcpy(n1->token, "ID"); 
		struct node* n = (struct node*)malloc(sizeof(struct node));
		$$ = n; 
		$$->left = n1; $$->right = NULL; 
		strcpy($$->lexeme, "--"); strcpy($$->token, "OP"); 
	}
        | LPAREN Term RPAREN { $$ = $2; }
	;	

%%

void yyerror(char* s){
        while(yylex() != SEMICOLON && yylex() != EOF);
        printf(" --> Rejected EXPR\n");
        yyparse();
}

void inorder(struct node* n1){
	if(n1 == NULL){
		return;
	}	

	inorder(n1->left);
	if(strcmp(n1->token, "NUMBER") == 0){
		printf("\n%s\t\t%d", n1->token, n1->val);
	} else{
		printf("\n%s\t\t%s", n1->token, n1->lexeme);
	}
	inorder(n1->right);
}

void preorder(struct node* n){
        if(n == NULL) return;

	if(strcmp(n->token, "NUMBER") == 0){
                printf("\n%s\t\t%d", n->token, n->val);
        } else{
                printf("\n%s\t\t%s", n->token, n->lexeme);
        }

        preorder(n->left);
        preorder(n->right);
}

void postorder(struct node* n){
	if(n == NULL) return;

        postorder(n->left);
	postorder(n->right);
        if(strcmp(n->token, "NUMBER") == 0){
                printf("\n%s\t\t%d", n->token, n->val);
        } else{
                printf("\n%s\t\t%s", n->token, n->lexeme);
        }
}

int main(int argc, char* argv[])
{
        if(argc > 1)
        {
                FILE *fp = fopen(argv[1], "r");
                if(fp) yyin = fp;
        }
        yyparse();
        return 0;
}
