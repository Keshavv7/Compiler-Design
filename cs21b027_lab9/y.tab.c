/* original parser id follows */
/* yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93" */
/* (use YYMAJOR/YYMINOR for ifdefs dependent on parser version) */

#define YYBYACC 1
#define YYMAJOR 2
#define YYMINOR 0
#define YYPATCH 20220128

#define YYEMPTY        (-1)
#define yyclearin      (yychar = YYEMPTY)
#define yyerrok        (yyerrflag = 0)
#define YYRECOVERING() (yyerrflag != 0)
#define YYENOMEM       (-2)
#define YYEOF          0
#undef YYBTYACC
#define YYBTYACC 0
#define YYDEBUGSTR YYPREFIX "debug"
#define YYPREFIX "yy"

#define YYPURE 0

#line 2 "prob1.y"
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
	/*struct node* left;*/
	/*struct node* right;	*/
};

/*void postorder(struct node*);*/
/*void inorder(struct node*);*/
int count=0;
struct node* gentemp();
void genlabel();


int l=0;

/*For stack implementation to keep track of L0, L1...:*/
int toptrue = -1;
int topfalse = -1;
int topendofif = -1;
int topstartofwhile = -1;
int topifwhilefalse = -1;

int iftrue[N]; /*if boolexpr is true then we go to L addr of the top elem of this*/
int iffalse[N]; /*if boolexpr is false then we go to L addr of the top elem of this*/
int endofif[N]; /*if boolexpr is false and we have an else stmt in it then we go to iffasle top elem for else case but if else is there but the condition is true, then to skip else we go to top of endofoif.*/
int startofwhile[N]; /*at the start of while we have a label that we would reach when loop is once completed;*/
int ifwhilefalse[N]; /*if boolexpr is wrong here then we skip the total while loop and continue further*/
void push(int , int);   /*push(x, y) y=0 for iffalse array, y=1=>iftrue, y=-1=>endofif, y=2=>startofwhile, y=3=>ifwhilefalse,x is num to push   */
int pop(int);       
int peek(int);   
/*/////////////*/

#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#line 50 "prob1.y"
typedef union YYSTYPE {
	int dval;
	char lexeme[20];
	struct node* Node;	 
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 84 "y.tab.c"

/* compatibility with bison */
#ifdef YYPARSE_PARAM
/* compatibility with FreeBSD */
# ifdef YYPARSE_PARAM_TYPE
#  define YYPARSE_DECL() yyparse(YYPARSE_PARAM_TYPE YYPARSE_PARAM)
# else
#  define YYPARSE_DECL() yyparse(void *YYPARSE_PARAM)
# endif
#else
# define YYPARSE_DECL() yyparse(void)
#endif

/* Parameters sent to lex. */
#ifdef YYLEX_PARAM
# define YYLEX_DECL() yylex(void *YYLEX_PARAM)
# define YYLEX yylex(YYLEX_PARAM)
#else
# define YYLEX_DECL() yylex(void)
# define YYLEX yylex()
#endif

#if !(defined(yylex) || defined(YYSTATE))
int YYLEX_DECL();
#endif

/* Parameters sent to yyerror. */
#ifndef YYERROR_DECL
#define YYERROR_DECL() yyerror(const char *s)
#endif
#ifndef YYERROR_CALL
#define YYERROR_CALL(msg) yyerror(msg)
#endif

extern int YYPARSE_DECL();

#define POSNUMBER 257
#define FLOAT 258
#define PLUS 259
#define MINUS 260
#define SEP 261
#define MUL 262
#define DIV 263
#define POW 264
#define OPENB 265
#define CLOSEB 266
#define DOUBLEPLUS 267
#define DOUBLEMINUS 268
#define VARIABLE 269
#define EQUALS 270
#define IF 271
#define ELSE 272
#define OPENCB 273
#define CLOSECB 274
#define NOT 275
#define DOUBLEEQUAL 276
#define NOTEQUAL 277
#define LESSTHANOREQUALTO 278
#define GREATERTHANOREQUALTO 279
#define LESSTHAN 280
#define GREATERTHAN 281
#define BOOLTRUE 282
#define BOOLFALSE 283
#define AND 284
#define OR 285
#define WHILE 286
#define P 287
#define Q 288
#define YYERRCODE 256
typedef int YYINT;
static const YYINT yylhs[] = {                           -1,
   15,    0,   16,   17,    0,   19,   20,   21,    0,    0,
   22,   23,   18,   24,   18,   14,   14,    1,    1,    1,
    2,    2,    2,    3,    3,    4,    4,    4,    4,    6,
    6,    6,    9,    9,    9,    9,    7,    7,    7,    8,
    8,    5,    5,   12,   12,   13,   13,   13,   13,   11,
   11,   10,   10,   10,   10,   10,   10,
};
static const YYINT yylen[] = {                            2,
    0,    4,    0,    0,   10,    0,    0,    0,   11,    0,
    0,    0,    7,    0,    2,    3,    1,    3,    3,    1,
    3,    3,    1,    3,    1,    1,    1,    1,    1,    1,
    3,    4,    2,    2,    2,    2,    1,    1,    2,    1,
    2,    1,    1,    3,    1,    3,    1,    3,    2,    1,
    1,    1,    1,    1,    1,    1,    1,
};
static const YYINT yydefred[] = {                         0,
    0,    0,    0,   40,    0,    6,    0,    0,   17,    0,
   41,   33,   34,    0,    0,   35,   36,    0,    1,   38,
   37,    0,    0,    0,   42,   43,    0,    0,   23,    0,
   28,   29,   27,    0,   30,    0,    0,    0,    0,    0,
    0,   39,    0,    0,    0,   49,    0,    0,   56,   57,
   54,   55,   52,   53,    0,    0,    0,    0,    3,   50,
   51,    0,    0,    0,    2,    0,   31,   48,    0,    0,
    0,   21,   22,   24,    0,   44,    7,   32,    4,    0,
    0,    0,    0,    0,    0,    8,   11,    5,    0,    0,
    0,   15,    9,    0,    0,   12,    0,   13,
};
#if defined(YYDESTRUCT_CALL) || defined(YYSTYPE_TOSTRING)
static const YYINT yystos[] = {                           0,
  260,  267,  268,  269,  271,  286,  290,  298,  299,  304,
  269,  298,  298,  265,  309,  267,  268,  270,  261,  257,
  258,  260,  265,  275,  282,  283,  291,  292,  293,  294,
  295,  296,  297,  298,  299,  302,  303,  265,  265,  291,
  305,  257,  265,  291,  302,  303,  259,  260,  276,  277,
  278,  279,  280,  281,  300,  262,  263,  264,  266,  284,
  285,  301,  302,  291,  290,  291,  266,  266,  292,  292,
  291,  293,  293,  293,  306,  302,  266,  266,  273,  310,
  307,  273,  290,  290,  274,  274,  272,  308,  314,  311,
  312,  290,  290,  273,  290,  274,  313,  290,
};
#endif /* YYDESTRUCT_CALL || YYSTYPE_TOSTRING */
static const YYINT yydgoto[] = {                          7,
   27,   28,   29,   30,   31,   32,   33,   34,   35,   55,
   62,   36,   37,   10,   41,   75,   81,   88,   15,   80,
   90,   91,   97,   89,
};
static const YYINT yysindex[] = {                      -244,
 -262, -249, -249,    0, -255,    0,    0, -216,    0, -246,
    0,    0,    0,  -42, -233,    0,    0,  -23,    0,    0,
    0, -243,  -42,  -42,    0,    0, -242, -192,    0, -209,
    0,    0,    0, -173,    0, -245, -196,  -42,  -23, -158,
 -244,    0,  -23,  -28, -203,    0,  -23,  -23,    0,    0,
    0,    0,    0,    0,  -23,  -23,  -23,  -23,    0,    0,
    0,  -42, -193, -194,    0, -179,    0,    0, -192, -192,
 -158,    0,    0,    0, -187,    0,    0,    0,    0, -177,
 -244, -244, -159, -157, -156,    0,    0,    0, -244, -244,
 -155,    0,    0, -244, -154,    0, -244,    0,
};
static const YYINT yyrindex[] = {                       119,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0, -254, -125,    0, -152,
    0,    0,    0, -202,    0,    0, -145,    0,    0, -139,
    2,    0,    0, -180,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  -98,  -71,
 -238,    0,    0,    0,    0,    0,    0,    0,    0,    0,
 -151, -151,    0,    0,    1,    0,    0,    0,    2,    2,
    0,    0,    0, -151,    0,    0,    2,    0,
};
#if YYBTYACC
static const YYINT yycindex[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,
};
#endif
static const YYINT yygindex[] = {                       -41,
  -10,   65,   11,    0,    0,    0,    0,    3,    9,    0,
    0,  -19,  106,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,
};
#define YYTABLESIZE 287
static const YYINT yytable[] = {                         65,
   14,   10,    8,   45,   12,   13,   11,   40,    9,   14,
    1,   47,   44,   42,   19,    1,   47,   48,   63,    4,
   59,   43,    2,    3,    4,   11,    5,   46,   64,   47,
   47,   38,   66,   49,   50,   51,   52,   53,   54,   83,
   84,    6,   76,    8,   71,   46,   46,   92,   93,    9,
   16,   17,   95,   18,   58,   98,   26,   26,   26,   26,
   26,   26,   68,   26,   47,   48,   72,   73,   74,   56,
   57,   67,   77,   26,   26,   26,   26,   26,   26,   47,
   48,   26,   26,    8,    8,   79,   78,   60,   61,    9,
    9,    8,    8,   16,   17,   82,    8,    9,    9,    8,
   47,   48,    9,   47,   47,    9,   25,   25,   25,   25,
   25,   69,   70,   25,   85,   87,   86,   94,   10,   96,
   45,   16,   10,   25,   25,   25,   25,   25,   25,   46,
    0,   25,   25,   20,   20,   20,    0,    0,    0,    0,
   20,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   20,   20,   20,   20,   20,   20,    0,    0,   20,   20,
   18,   18,   18,    0,    0,    0,    0,   18,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   18,   18,   18,
   18,   18,   18,    0,    0,   18,   18,   19,   19,   19,
    0,    0,    0,    0,   19,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   19,   19,   19,   19,   19,   19,
    0,    0,   19,   19,   20,   21,    0,   22,    0,    0,
    0,    0,   23,    0,    2,    3,    4,    0,    0,    0,
   47,   48,   24,   20,   21,    0,   22,   67,    0,   25,
   26,   39,    0,    2,    3,    4,    0,   49,   50,   51,
   52,   53,   54,    0,    0,    0,    0,    0,   25,   26,
   14,    0,    0,    0,    0,    0,    0,   14,   14,   14,
    0,   14,    0,    0,   14,   10,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   14,
};
static const YYINT yycheck[] = {                         41,
    0,    0,    0,   23,    2,    3,  269,   18,    0,  265,
  260,  266,   23,  257,  261,  260,  259,  260,   38,  269,
  266,  265,  267,  268,  269,  269,  271,  266,   39,  284,
  285,  265,   43,  276,  277,  278,  279,  280,  281,   81,
   82,  286,   62,   41,   55,  284,  285,   89,   90,   41,
  267,  268,   94,  270,  264,   97,  259,  260,  261,  262,
  263,  264,  266,  266,  259,  260,   56,   57,   58,  262,
  263,  266,  266,  276,  277,  278,  279,  280,  281,  259,
  260,  284,  285,   81,   82,  273,  266,  284,  285,   81,
   82,   89,   90,  267,  268,  273,   94,   89,   90,   97,
  259,  260,   94,  284,  285,   97,  259,  260,  261,  262,
  263,   47,   48,  266,  274,  272,  274,  273,    0,  274,
  266,  261,  274,  276,  277,  278,  279,  280,  281,   24,
   -1,  284,  285,  259,  260,  261,   -1,   -1,   -1,   -1,
  266,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  276,  277,  278,  279,  280,  281,   -1,   -1,  284,  285,
  259,  260,  261,   -1,   -1,   -1,   -1,  266,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  276,  277,  278,
  279,  280,  281,   -1,   -1,  284,  285,  259,  260,  261,
   -1,   -1,   -1,   -1,  266,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  276,  277,  278,  279,  280,  281,
   -1,   -1,  284,  285,  257,  258,   -1,  260,   -1,   -1,
   -1,   -1,  265,   -1,  267,  268,  269,   -1,   -1,   -1,
  259,  260,  275,  257,  258,   -1,  260,  266,   -1,  282,
  283,  265,   -1,  267,  268,  269,   -1,  276,  277,  278,
  279,  280,  281,   -1,   -1,   -1,   -1,   -1,  282,  283,
  260,   -1,   -1,   -1,   -1,   -1,   -1,  267,  268,  269,
   -1,  271,   -1,   -1,  274,  274,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  286,
};
#if YYBTYACC
static const YYINT yyctable[] = {                        -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,
};
#endif
#define YYFINAL 7
#ifndef YYDEBUG
#define YYDEBUG 1
#endif
#define YYMAXTOKEN 288
#define YYUNDFTOKEN 315
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? YYUNDFTOKEN : (a))
#if YYDEBUG
static const char *const yyname[] = {

"$end",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"error","POSNUMBER","FLOAT","PLUS",
"MINUS","SEP","MUL","DIV","POW","OPENB","CLOSEB","DOUBLEPLUS","DOUBLEMINUS",
"VARIABLE","EQUALS","IF","ELSE","OPENCB","CLOSECB","NOT","DOUBLEEQUAL",
"NOTEQUAL","LESSTHANOREQUALTO","GREATERTHANOREQUALTO","LESSTHAN","GREATERTHAN",
"BOOLTRUE","BOOLFALSE","AND","OR","WHILE","P","Q","$accept","STMTS","E","T","F",
"K","B","N","I","V","ABCD","RELOP","BOOLOP","BOOLEXPR","BOOL","STMT","$$1",
"$$2","$$3","FURTHERIF","$$4","$$5","$$6","$$7","$$8","$$9","illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : STMTS",
"$$1 :",
"STMTS : STMT SEP $$1 STMTS",
"$$2 :",
"$$3 :",
"STMTS : IF OPENB BOOLEXPR CLOSEB $$2 OPENCB $$3 STMTS CLOSECB FURTHERIF",
"$$4 :",
"$$5 :",
"$$6 :",
"STMTS : WHILE $$4 OPENB BOOLEXPR CLOSEB $$5 OPENCB STMTS CLOSECB $$6 STMTS",
"STMTS :",
"$$7 :",
"$$8 :",
"FURTHERIF : ELSE $$7 OPENCB STMTS CLOSECB $$8 STMTS",
"$$9 :",
"FURTHERIF : $$9 STMTS",
"STMT : V EQUALS E",
"STMT : ABCD",
"E : E PLUS T",
"E : E MINUS T",
"E : T",
"T : T MUL F",
"T : T DIV F",
"T : F",
"F : K POW F",
"F : K",
"K : V",
"K : I",
"K : B",
"K : N",
"N : ABCD",
"N : OPENB E CLOSEB",
"N : MINUS OPENB E CLOSEB",
"ABCD : DOUBLEPLUS V",
"ABCD : DOUBLEMINUS V",
"ABCD : V DOUBLEPLUS",
"ABCD : V DOUBLEMINUS",
"I : FLOAT",
"I : POSNUMBER",
"I : MINUS POSNUMBER",
"V : VARIABLE",
"V : MINUS VARIABLE",
"B : BOOLTRUE",
"B : BOOLFALSE",
"BOOLEXPR : BOOL BOOLOP BOOLEXPR",
"BOOLEXPR : BOOL",
"BOOL : E RELOP E",
"BOOL : E",
"BOOL : OPENB BOOLEXPR CLOSEB",
"BOOL : NOT BOOL",
"BOOLOP : AND",
"BOOLOP : OR",
"RELOP : LESSTHAN",
"RELOP : GREATERTHAN",
"RELOP : LESSTHANOREQUALTO",
"RELOP : GREATERTHANOREQUALTO",
"RELOP : DOUBLEEQUAL",
"RELOP : NOTEQUAL",

};
#endif

#if YYDEBUG
int      yydebug;
#endif

int      yyerrflag;
int      yychar;
YYSTYPE  yyval;
YYSTYPE  yylval;
int      yynerrs;

#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
YYLTYPE  yyloc; /* position returned by actions */
YYLTYPE  yylloc; /* position from the lexer */
#endif

#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
#ifndef YYLLOC_DEFAULT
#define YYLLOC_DEFAULT(loc, rhs, n) \
do \
{ \
    if (n == 0) \
    { \
        (loc).first_line   = YYRHSLOC(rhs, 0).last_line; \
        (loc).first_column = YYRHSLOC(rhs, 0).last_column; \
        (loc).last_line    = YYRHSLOC(rhs, 0).last_line; \
        (loc).last_column  = YYRHSLOC(rhs, 0).last_column; \
    } \
    else \
    { \
        (loc).first_line   = YYRHSLOC(rhs, 1).first_line; \
        (loc).first_column = YYRHSLOC(rhs, 1).first_column; \
        (loc).last_line    = YYRHSLOC(rhs, n).last_line; \
        (loc).last_column  = YYRHSLOC(rhs, n).last_column; \
    } \
} while (0)
#endif /* YYLLOC_DEFAULT */
#endif /* defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED) */
#if YYBTYACC

#ifndef YYLVQUEUEGROWTH
#define YYLVQUEUEGROWTH 32
#endif
#endif /* YYBTYACC */

/* define the initial stack-sizes */
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH  YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 10000
#define YYMAXDEPTH  10000
#endif
#endif

#ifndef YYINITSTACKSIZE
#define YYINITSTACKSIZE 200
#endif

typedef struct {
    unsigned stacksize;
    YYINT    *s_base;
    YYINT    *s_mark;
    YYINT    *s_last;
    YYSTYPE  *l_base;
    YYSTYPE  *l_mark;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    YYLTYPE  *p_base;
    YYLTYPE  *p_mark;
#endif
} YYSTACKDATA;
#if YYBTYACC

struct YYParseState_s
{
    struct YYParseState_s *save;    /* Previously saved parser state */
    YYSTACKDATA            yystack; /* saved parser stack */
    int                    state;   /* saved parser state */
    int                    errflag; /* saved error recovery status */
    int                    lexeme;  /* saved index of the conflict lexeme in the lexical queue */
    YYINT                  ctry;    /* saved index in yyctable[] for this conflict */
};
typedef struct YYParseState_s YYParseState;
#endif /* YYBTYACC */
/* variables for the parser stack */
static YYSTACKDATA yystack;
#if YYBTYACC

/* Current parser state */
static YYParseState *yyps = 0;

/* yypath != NULL: do the full parse, starting at *yypath parser state. */
static YYParseState *yypath = 0;

/* Base of the lexical value queue */
static YYSTYPE *yylvals = 0;

/* Current position at lexical value queue */
static YYSTYPE *yylvp = 0;

/* End position of lexical value queue */
static YYSTYPE *yylve = 0;

/* The last allocated position at the lexical value queue */
static YYSTYPE *yylvlim = 0;

#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
/* Base of the lexical position queue */
static YYLTYPE *yylpsns = 0;

/* Current position at lexical position queue */
static YYLTYPE *yylpp = 0;

/* End position of lexical position queue */
static YYLTYPE *yylpe = 0;

/* The last allocated position at the lexical position queue */
static YYLTYPE *yylplim = 0;
#endif

/* Current position at lexical token queue */
static YYINT  *yylexp = 0;

static YYINT  *yylexemes = 0;
#endif /* YYBTYACC */
#line 456 "prob1.y"
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
#line 738 "y.tab.c"

/* For use in generated program */
#define yydepth (int)(yystack.s_mark - yystack.s_base)
#if YYBTYACC
#define yytrial (yyps->save)
#endif /* YYBTYACC */

#if YYDEBUG
#include <stdio.h>	/* needed for printf */
#endif

#include <stdlib.h>	/* needed for malloc, etc */
#include <string.h>	/* needed for memset */

/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(YYSTACKDATA *data)
{
    int i;
    unsigned newsize;
    YYINT *newss;
    YYSTYPE *newvs;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    YYLTYPE *newps;
#endif

    if ((newsize = data->stacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return YYENOMEM;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = (int) (data->s_mark - data->s_base);
    newss = (YYINT *)realloc(data->s_base, newsize * sizeof(*newss));
    if (newss == 0)
        return YYENOMEM;

    data->s_base = newss;
    data->s_mark = newss + i;

    newvs = (YYSTYPE *)realloc(data->l_base, newsize * sizeof(*newvs));
    if (newvs == 0)
        return YYENOMEM;

    data->l_base = newvs;
    data->l_mark = newvs + i;

#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    newps = (YYLTYPE *)realloc(data->p_base, newsize * sizeof(*newps));
    if (newps == 0)
        return YYENOMEM;

    data->p_base = newps;
    data->p_mark = newps + i;
#endif

    data->stacksize = newsize;
    data->s_last = data->s_base + newsize - 1;

#if YYDEBUG
    if (yydebug)
        fprintf(stderr, "%sdebug: stack size increased to %d\n", YYPREFIX, newsize);
#endif
    return 0;
}

#if YYPURE || defined(YY_NO_LEAKS)
static void yyfreestack(YYSTACKDATA *data)
{
    free(data->s_base);
    free(data->l_base);
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    free(data->p_base);
#endif
    memset(data, 0, sizeof(*data));
}
#else
#define yyfreestack(data) /* nothing */
#endif /* YYPURE || defined(YY_NO_LEAKS) */
#if YYBTYACC

static YYParseState *
yyNewState(unsigned size)
{
    YYParseState *p = (YYParseState *) malloc(sizeof(YYParseState));
    if (p == NULL) return NULL;

    p->yystack.stacksize = size;
    if (size == 0)
    {
        p->yystack.s_base = NULL;
        p->yystack.l_base = NULL;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
        p->yystack.p_base = NULL;
#endif
        return p;
    }
    p->yystack.s_base    = (YYINT *) malloc(size * sizeof(YYINT));
    if (p->yystack.s_base == NULL) return NULL;
    p->yystack.l_base    = (YYSTYPE *) malloc(size * sizeof(YYSTYPE));
    if (p->yystack.l_base == NULL) return NULL;
    memset(p->yystack.l_base, 0, size * sizeof(YYSTYPE));
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    p->yystack.p_base    = (YYLTYPE *) malloc(size * sizeof(YYLTYPE));
    if (p->yystack.p_base == NULL) return NULL;
    memset(p->yystack.p_base, 0, size * sizeof(YYLTYPE));
#endif

    return p;
}

static void
yyFreeState(YYParseState *p)
{
    yyfreestack(&p->yystack);
    free(p);
}
#endif /* YYBTYACC */

#define YYABORT  goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR  goto yyerrlab
#if YYBTYACC
#define YYVALID        do { if (yyps->save)            goto yyvalid; } while(0)
#define YYVALID_NESTED do { if (yyps->save && \
                                yyps->save->save == 0) goto yyvalid; } while(0)
#endif /* YYBTYACC */

int
YYPARSE_DECL()
{
    int yym, yyn, yystate, yyresult;
#if YYBTYACC
    int yynewerrflag;
    YYParseState *yyerrctx = NULL;
#endif /* YYBTYACC */
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    YYLTYPE  yyerror_loc_range[3]; /* position of error start/end (0 unused) */
#endif
#if YYDEBUG
    const char *yys;

    if ((yys = getenv("YYDEBUG")) != 0)
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
    if (yydebug)
        fprintf(stderr, "%sdebug[<# of symbols on state stack>]\n", YYPREFIX);
#endif
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    memset(yyerror_loc_range, 0, sizeof(yyerror_loc_range));
#endif

#if YYBTYACC
    yyps = yyNewState(0); if (yyps == 0) goto yyenomem;
    yyps->save = 0;
#endif /* YYBTYACC */
    yym = 0;
    /* yyn is set below */
    yynerrs = 0;
    yyerrflag = 0;
    yychar = YYEMPTY;
    yystate = 0;

#if YYPURE
    memset(&yystack, 0, sizeof(yystack));
#endif

    if (yystack.s_base == NULL && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
    yystack.s_mark = yystack.s_base;
    yystack.l_mark = yystack.l_base;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    yystack.p_mark = yystack.p_base;
#endif
    yystate = 0;
    *yystack.s_mark = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
#if YYBTYACC
        do {
        if (yylvp < yylve)
        {
            /* we're currently re-reading tokens */
            yylval = *yylvp++;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
            yylloc = *yylpp++;
#endif
            yychar = *yylexp++;
            break;
        }
        if (yyps->save)
        {
            /* in trial mode; save scanner results for future parse attempts */
            if (yylvp == yylvlim)
            {   /* Enlarge lexical value queue */
                size_t p = (size_t) (yylvp - yylvals);
                size_t s = (size_t) (yylvlim - yylvals);

                s += YYLVQUEUEGROWTH;
                if ((yylexemes = (YYINT *)realloc(yylexemes, s * sizeof(YYINT))) == NULL) goto yyenomem;
                if ((yylvals   = (YYSTYPE *)realloc(yylvals, s * sizeof(YYSTYPE))) == NULL) goto yyenomem;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                if ((yylpsns   = (YYLTYPE *)realloc(yylpsns, s * sizeof(YYLTYPE))) == NULL) goto yyenomem;
#endif
                yylvp   = yylve = yylvals + p;
                yylvlim = yylvals + s;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                yylpp   = yylpe = yylpsns + p;
                yylplim = yylpsns + s;
#endif
                yylexp  = yylexemes + p;
            }
            *yylexp = (YYINT) YYLEX;
            *yylvp++ = yylval;
            yylve++;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
            *yylpp++ = yylloc;
            yylpe++;
#endif
            yychar = *yylexp++;
            break;
        }
        /* normal operation, no conflict encountered */
#endif /* YYBTYACC */
        yychar = YYLEX;
#if YYBTYACC
        } while (0);
#endif /* YYBTYACC */
        if (yychar < 0) yychar = YYEOF;
#if YYDEBUG
        if (yydebug)
        {
            if ((yys = yyname[YYTRANSLATE(yychar)]) == NULL) yys = yyname[YYUNDFTOKEN];
            fprintf(stderr, "%s[%d]: state %d, reading token %d (%s)",
                            YYDEBUGSTR, yydepth, yystate, yychar, yys);
#ifdef YYSTYPE_TOSTRING
#if YYBTYACC
            if (!yytrial)
#endif /* YYBTYACC */
                fprintf(stderr, " <%s>", YYSTYPE_TOSTRING(yychar, yylval));
#endif
            fputc('\n', stderr);
        }
#endif
    }
#if YYBTYACC

    /* Do we have a conflict? */
    if (((yyn = yycindex[yystate]) != 0) && (yyn += yychar) >= 0 &&
        yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT) yychar)
    {
        YYINT ctry;

        if (yypath)
        {
            YYParseState *save;
#if YYDEBUG
            if (yydebug)
                fprintf(stderr, "%s[%d]: CONFLICT in state %d: following successful trial parse\n",
                                YYDEBUGSTR, yydepth, yystate);
#endif
            /* Switch to the next conflict context */
            save = yypath;
            yypath = save->save;
            save->save = NULL;
            ctry = save->ctry;
            if (save->state != yystate) YYABORT;
            yyFreeState(save);

        }
        else
        {

            /* Unresolved conflict - start/continue trial parse */
            YYParseState *save;
#if YYDEBUG
            if (yydebug)
            {
                fprintf(stderr, "%s[%d]: CONFLICT in state %d. ", YYDEBUGSTR, yydepth, yystate);
                if (yyps->save)
                    fputs("ALREADY in conflict, continuing trial parse.\n", stderr);
                else
                    fputs("Starting trial parse.\n", stderr);
            }
#endif
            save                  = yyNewState((unsigned)(yystack.s_mark - yystack.s_base + 1));
            if (save == NULL) goto yyenomem;
            save->save            = yyps->save;
            save->state           = yystate;
            save->errflag         = yyerrflag;
            save->yystack.s_mark  = save->yystack.s_base + (yystack.s_mark - yystack.s_base);
            memcpy (save->yystack.s_base, yystack.s_base, (size_t) (yystack.s_mark - yystack.s_base + 1) * sizeof(YYINT));
            save->yystack.l_mark  = save->yystack.l_base + (yystack.l_mark - yystack.l_base);
            memcpy (save->yystack.l_base, yystack.l_base, (size_t) (yystack.l_mark - yystack.l_base + 1) * sizeof(YYSTYPE));
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
            save->yystack.p_mark  = save->yystack.p_base + (yystack.p_mark - yystack.p_base);
            memcpy (save->yystack.p_base, yystack.p_base, (size_t) (yystack.p_mark - yystack.p_base + 1) * sizeof(YYLTYPE));
#endif
            ctry                  = yytable[yyn];
            if (yyctable[ctry] == -1)
            {
#if YYDEBUG
                if (yydebug && yychar >= YYEOF)
                    fprintf(stderr, "%s[%d]: backtracking 1 token\n", YYDEBUGSTR, yydepth);
#endif
                ctry++;
            }
            save->ctry = ctry;
            if (yyps->save == NULL)
            {
                /* If this is a first conflict in the stack, start saving lexemes */
                if (!yylexemes)
                {
                    yylexemes = (YYINT *) malloc((YYLVQUEUEGROWTH) * sizeof(YYINT));
                    if (yylexemes == NULL) goto yyenomem;
                    yylvals   = (YYSTYPE *) malloc((YYLVQUEUEGROWTH) * sizeof(YYSTYPE));
                    if (yylvals == NULL) goto yyenomem;
                    yylvlim   = yylvals + YYLVQUEUEGROWTH;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                    yylpsns   = (YYLTYPE *) malloc((YYLVQUEUEGROWTH) * sizeof(YYLTYPE));
                    if (yylpsns == NULL) goto yyenomem;
                    yylplim   = yylpsns + YYLVQUEUEGROWTH;
#endif
                }
                if (yylvp == yylve)
                {
                    yylvp  = yylve = yylvals;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                    yylpp  = yylpe = yylpsns;
#endif
                    yylexp = yylexemes;
                    if (yychar >= YYEOF)
                    {
                        *yylve++ = yylval;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                        *yylpe++ = yylloc;
#endif
                        *yylexp  = (YYINT) yychar;
                        yychar   = YYEMPTY;
                    }
                }
            }
            if (yychar >= YYEOF)
            {
                yylvp--;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                yylpp--;
#endif
                yylexp--;
                yychar = YYEMPTY;
            }
            save->lexeme = (int) (yylvp - yylvals);
            yyps->save   = save;
        }
        if (yytable[yyn] == ctry)
        {
#if YYDEBUG
            if (yydebug)
                fprintf(stderr, "%s[%d]: state %d, shifting to state %d\n",
                                YYDEBUGSTR, yydepth, yystate, yyctable[ctry]);
#endif
            if (yychar < 0)
            {
                yylvp++;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                yylpp++;
#endif
                yylexp++;
            }
            if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
                goto yyoverflow;
            yystate = yyctable[ctry];
            *++yystack.s_mark = (YYINT) yystate;
            *++yystack.l_mark = yylval;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
            *++yystack.p_mark = yylloc;
#endif
            yychar  = YYEMPTY;
            if (yyerrflag > 0) --yyerrflag;
            goto yyloop;
        }
        else
        {
            yyn = yyctable[ctry];
            goto yyreduce;
        }
    } /* End of code dealing with conflicts */
#endif /* YYBTYACC */
    if (((yyn = yysindex[yystate]) != 0) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT) yychar)
    {
#if YYDEBUG
        if (yydebug)
            fprintf(stderr, "%s[%d]: state %d, shifting to state %d\n",
                            YYDEBUGSTR, yydepth, yystate, yytable[yyn]);
#endif
        if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
        yystate = yytable[yyn];
        *++yystack.s_mark = yytable[yyn];
        *++yystack.l_mark = yylval;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
        *++yystack.p_mark = yylloc;
#endif
        yychar = YYEMPTY;
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if (((yyn = yyrindex[yystate]) != 0) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT) yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag != 0) goto yyinrecovery;
#if YYBTYACC

    yynewerrflag = 1;
    goto yyerrhandler;
    goto yyerrlab; /* redundant goto avoids 'unused label' warning */

yyerrlab:
    /* explicit YYERROR from an action -- pop the rhs of the rule reduced
     * before looking for error recovery */
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    yystack.p_mark -= yym;
#endif

    yynewerrflag = 0;
yyerrhandler:
    while (yyps->save)
    {
        int ctry;
        YYParseState *save = yyps->save;
#if YYDEBUG
        if (yydebug)
            fprintf(stderr, "%s[%d]: ERROR in state %d, CONFLICT BACKTRACKING to state %d, %d tokens\n",
                            YYDEBUGSTR, yydepth, yystate, yyps->save->state,
                    (int)(yylvp - yylvals - yyps->save->lexeme));
#endif
        /* Memorize most forward-looking error state in case it's really an error. */
        if (yyerrctx == NULL || yyerrctx->lexeme < yylvp - yylvals)
        {
            /* Free old saved error context state */
            if (yyerrctx) yyFreeState(yyerrctx);
            /* Create and fill out new saved error context state */
            yyerrctx                 = yyNewState((unsigned)(yystack.s_mark - yystack.s_base + 1));
            if (yyerrctx == NULL) goto yyenomem;
            yyerrctx->save           = yyps->save;
            yyerrctx->state          = yystate;
            yyerrctx->errflag        = yyerrflag;
            yyerrctx->yystack.s_mark = yyerrctx->yystack.s_base + (yystack.s_mark - yystack.s_base);
            memcpy (yyerrctx->yystack.s_base, yystack.s_base, (size_t) (yystack.s_mark - yystack.s_base + 1) * sizeof(YYINT));
            yyerrctx->yystack.l_mark = yyerrctx->yystack.l_base + (yystack.l_mark - yystack.l_base);
            memcpy (yyerrctx->yystack.l_base, yystack.l_base, (size_t) (yystack.l_mark - yystack.l_base + 1) * sizeof(YYSTYPE));
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
            yyerrctx->yystack.p_mark = yyerrctx->yystack.p_base + (yystack.p_mark - yystack.p_base);
            memcpy (yyerrctx->yystack.p_base, yystack.p_base, (size_t) (yystack.p_mark - yystack.p_base + 1) * sizeof(YYLTYPE));
#endif
            yyerrctx->lexeme         = (int) (yylvp - yylvals);
        }
        yylvp          = yylvals   + save->lexeme;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
        yylpp          = yylpsns   + save->lexeme;
#endif
        yylexp         = yylexemes + save->lexeme;
        yychar         = YYEMPTY;
        yystack.s_mark = yystack.s_base + (save->yystack.s_mark - save->yystack.s_base);
        memcpy (yystack.s_base, save->yystack.s_base, (size_t) (yystack.s_mark - yystack.s_base + 1) * sizeof(YYINT));
        yystack.l_mark = yystack.l_base + (save->yystack.l_mark - save->yystack.l_base);
        memcpy (yystack.l_base, save->yystack.l_base, (size_t) (yystack.l_mark - yystack.l_base + 1) * sizeof(YYSTYPE));
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
        yystack.p_mark = yystack.p_base + (save->yystack.p_mark - save->yystack.p_base);
        memcpy (yystack.p_base, save->yystack.p_base, (size_t) (yystack.p_mark - yystack.p_base + 1) * sizeof(YYLTYPE));
#endif
        ctry           = ++save->ctry;
        yystate        = save->state;
        /* We tried shift, try reduce now */
        if ((yyn = yyctable[ctry]) >= 0) goto yyreduce;
        yyps->save     = save->save;
        save->save     = NULL;
        yyFreeState(save);

        /* Nothing left on the stack -- error */
        if (!yyps->save)
        {
#if YYDEBUG
            if (yydebug)
                fprintf(stderr, "%sdebug[%d,trial]: trial parse FAILED, entering ERROR mode\n",
                                YYPREFIX, yydepth);
#endif
            /* Restore state as it was in the most forward-advanced error */
            yylvp          = yylvals   + yyerrctx->lexeme;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
            yylpp          = yylpsns   + yyerrctx->lexeme;
#endif
            yylexp         = yylexemes + yyerrctx->lexeme;
            yychar         = yylexp[-1];
            yylval         = yylvp[-1];
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
            yylloc         = yylpp[-1];
#endif
            yystack.s_mark = yystack.s_base + (yyerrctx->yystack.s_mark - yyerrctx->yystack.s_base);
            memcpy (yystack.s_base, yyerrctx->yystack.s_base, (size_t) (yystack.s_mark - yystack.s_base + 1) * sizeof(YYINT));
            yystack.l_mark = yystack.l_base + (yyerrctx->yystack.l_mark - yyerrctx->yystack.l_base);
            memcpy (yystack.l_base, yyerrctx->yystack.l_base, (size_t) (yystack.l_mark - yystack.l_base + 1) * sizeof(YYSTYPE));
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
            yystack.p_mark = yystack.p_base + (yyerrctx->yystack.p_mark - yyerrctx->yystack.p_base);
            memcpy (yystack.p_base, yyerrctx->yystack.p_base, (size_t) (yystack.p_mark - yystack.p_base + 1) * sizeof(YYLTYPE));
#endif
            yystate        = yyerrctx->state;
            yyFreeState(yyerrctx);
            yyerrctx       = NULL;
        }
        yynewerrflag = 1;
    }
    if (yynewerrflag == 0) goto yyinrecovery;
#endif /* YYBTYACC */

    YYERROR_CALL("syntax error");
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    yyerror_loc_range[1] = yylloc; /* lookahead position is error start position */
#endif

#if !YYBTYACC
    goto yyerrlab; /* redundant goto avoids 'unused label' warning */
yyerrlab:
#endif
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if (((yyn = yysindex[*yystack.s_mark]) != 0) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT) YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    fprintf(stderr, "%s[%d]: state %d, error recovery shifting to state %d\n",
                                    YYDEBUGSTR, yydepth, *yystack.s_mark, yytable[yyn]);
#endif
                if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
                yystate = yytable[yyn];
                *++yystack.s_mark = yytable[yyn];
                *++yystack.l_mark = yylval;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                /* lookahead position is error end position */
                yyerror_loc_range[2] = yylloc;
                YYLLOC_DEFAULT(yyloc, yyerror_loc_range, 2); /* position of error span */
                *++yystack.p_mark = yyloc;
#endif
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    fprintf(stderr, "%s[%d]: error recovery discarding state %d\n",
                                    YYDEBUGSTR, yydepth, *yystack.s_mark);
#endif
                if (yystack.s_mark <= yystack.s_base) goto yyabort;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                /* the current TOS position is the error start position */
                yyerror_loc_range[1] = *yystack.p_mark;
#endif
#if defined(YYDESTRUCT_CALL)
#if YYBTYACC
                if (!yytrial)
#endif /* YYBTYACC */
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                    YYDESTRUCT_CALL("error: discarding state",
                                    yystos[*yystack.s_mark], yystack.l_mark, yystack.p_mark);
#else
                    YYDESTRUCT_CALL("error: discarding state",
                                    yystos[*yystack.s_mark], yystack.l_mark);
#endif /* defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED) */
#endif /* defined(YYDESTRUCT_CALL) */
                --yystack.s_mark;
                --yystack.l_mark;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                --yystack.p_mark;
#endif
            }
        }
    }
    else
    {
        if (yychar == YYEOF) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            if ((yys = yyname[YYTRANSLATE(yychar)]) == NULL) yys = yyname[YYUNDFTOKEN];
            fprintf(stderr, "%s[%d]: state %d, error recovery discarding token %d (%s)\n",
                            YYDEBUGSTR, yydepth, yystate, yychar, yys);
        }
#endif
#if defined(YYDESTRUCT_CALL)
#if YYBTYACC
        if (!yytrial)
#endif /* YYBTYACC */
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
            YYDESTRUCT_CALL("error: discarding token", yychar, &yylval, &yylloc);
#else
            YYDESTRUCT_CALL("error: discarding token", yychar, &yylval);
#endif /* defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED) */
#endif /* defined(YYDESTRUCT_CALL) */
        yychar = YYEMPTY;
        goto yyloop;
    }

yyreduce:
    yym = yylen[yyn];
#if YYDEBUG
    if (yydebug)
    {
        fprintf(stderr, "%s[%d]: state %d, reducing by rule %d (%s)",
                        YYDEBUGSTR, yydepth, yystate, yyn, yyrule[yyn]);
#ifdef YYSTYPE_TOSTRING
#if YYBTYACC
        if (!yytrial)
#endif /* YYBTYACC */
            if (yym > 0)
            {
                int i;
                fputc('<', stderr);
                for (i = yym; i > 0; i--)
                {
                    if (i != yym) fputs(", ", stderr);
                    fputs(YYSTYPE_TOSTRING(yystos[yystack.s_mark[1-i]],
                                           yystack.l_mark[1-i]), stderr);
                }
                fputc('>', stderr);
            }
#endif
        fputc('\n', stderr);
    }
#endif
    if (yym > 0)
        yyval = yystack.l_mark[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)

    /* Perform position reduction */
    memset(&yyloc, 0, sizeof(yyloc));
#if YYBTYACC
    if (!yytrial)
#endif /* YYBTYACC */
    {
        YYLLOC_DEFAULT(yyloc, &yystack.p_mark[-yym], yym);
        /* just in case YYERROR is invoked within the action, save
           the start of the rhs as the error start position */
        yyerror_loc_range[1] = yystack.p_mark[1-yym];
    }
#endif

    switch (yyn)
    {
case 1:
#line 80 "prob1.y"
	{/*printf(" === NORMAL STMT\n");*/
		/*printf("====INORDER====\n");*/
		/*inorder($1);	*/
		/*printf("\n====POSTORDER====\n");*/
		/*postorder($1);*/
		/*printf("completed nigaa!\n");	*/
		}
#line 1417 "y.tab.c"
break;
case 3:
#line 88 "prob1.y"
	{
		genlabel();
		printf("\nIF ( %s === true) go to L%d:\nELSE go to L%d:\n", yystack.l_mark[-1].Node->string, peek(1), peek(0));
		}
#line 1425 "y.tab.c"
break;
case 4:
#line 91 "prob1.y"
	{
		printf("\nL%d:\n", pop(1));
		}
#line 1432 "y.tab.c"
break;
case 6:
#line 95 "prob1.y"
	{push(l++, 2); printf("\nL%d:\n",peek(2));}
#line 1437 "y.tab.c"
break;
case 7:
#line 95 "prob1.y"
	{
		push(l++,3);
		printf("\nIF ( %s === false) go to L%d:\n",yystack.l_mark[-1].Node->string, peek(3));
		}
#line 1445 "y.tab.c"
break;
case 8:
#line 98 "prob1.y"
	{
		printf("\ngo to L%d:\n",pop(2));
		printf("\nL%d:\n",pop(3));		
		}
#line 1453 "y.tab.c"
break;
case 10:
#line 103 "prob1.y"
	{}
#line 1458 "y.tab.c"
break;
case 11:
#line 105 "prob1.y"
	{
		push(l++, -1);
		printf("go to L%d:\n", peek(-1));
		printf("\nL%d:\n", pop(0));
		}
#line 1467 "y.tab.c"
break;
case 12:
#line 109 "prob1.y"
	{
		printf("\nL%d:\n", pop(-1));
		}
#line 1474 "y.tab.c"
break;
case 14:
#line 112 "prob1.y"
	{ /*this is for the case of only if statement without any else*/
		printf("L%d:\n", pop(0));
		}
#line 1481 "y.tab.c"
break;
case 16:
#line 117 "prob1.y"
	{
		/*struct node* n = malloc(sizeof(struct node));
		$$ = n;
		n->left = $1;
		n->right = $3;
		strcpy(n->lexval, "=");
		strcpy(n->tok, "EQUALS");*/

		yyval.Node = gentemp();
		printf("%s = %s\n", yystack.l_mark[-2].Node->lexval,yystack.l_mark[0].Node); 
		}
#line 1496 "y.tab.c"
break;
case 17:
#line 128 "prob1.y"
	{yyval.Node=yystack.l_mark[0].Node;}
#line 1501 "y.tab.c"
break;
case 18:
#line 130 "prob1.y"
	{
		/*struct node* n = malloc(sizeof(struct node));
		$$ = n;
		n->left = $1;
		n->right = $3;
		strcpy($$->lexval, "+");
		strcpy($$->tok, "PLUS");*/

		yyval.Node = gentemp();
		printf("%s = %s+%s\n", yyval.Node, yystack.l_mark[-2].Node,yystack.l_mark[0].Node); 
		}
#line 1516 "y.tab.c"
break;
case 19:
#line 141 "prob1.y"
	{
		/*struct node* n = malloc(sizeof(struct node));
		$$ = n;
		$$->left = $1;
		$$->right = $3;
		strcpy($$->lexval, "-");
		strcpy($$->tok, "MINUS");*/
		
		yyval.Node = gentemp();
		printf("%s = %s-%s\n", yyval.Node, yystack.l_mark[-2].Node,yystack.l_mark[0].Node); 
		}
#line 1531 "y.tab.c"
break;
case 20:
#line 152 "prob1.y"
	{yyval.Node = yystack.l_mark[0].Node;}
#line 1536 "y.tab.c"
break;
case 21:
#line 155 "prob1.y"
	{/*struct node* n = malloc(sizeof(struct node));
			$$ = n;
			$$->left = $1;
			$$->right = $3;
			strcpy($$->lexval, "*");
			strcpy($$->tok, "MUL");*/
		yyval.Node = gentemp();
		printf("%s = %s*%s\n", yyval.Node, yystack.l_mark[-2].Node,yystack.l_mark[0].Node); 
		}
#line 1549 "y.tab.c"
break;
case 22:
#line 164 "prob1.y"
	{/*struct node* n = malloc(sizeof(struct node));
			$$ = n;
			$$->left = $1;
			$$->right = $3;
			strcpy($$->lexval, "/");
			strcpy($$->tok, "DIV");
		*/
		
		yyval.Node = gentemp();
		printf("%s = %s/%s\n", yyval.Node, yystack.l_mark[-2].Node,yystack.l_mark[0].Node); 
		}
#line 1564 "y.tab.c"
break;
case 23:
#line 175 "prob1.y"
	{yyval.Node = yystack.l_mark[0].Node;}
#line 1569 "y.tab.c"
break;
case 24:
#line 178 "prob1.y"
	{/*struct node* n = malloc(sizeof(struct node));
			$$ = n;
			$$->left = $1;
			$$->right = $3;
			strcpy($$->lexval, "^");
			strcpy($$->tok, "POW");
		*/yyval.Node = gentemp();
		printf("%s = %s^%s\n", yyval.Node, yystack.l_mark[-2].Node,yystack.l_mark[0].Node); 
		}
#line 1582 "y.tab.c"
break;
case 25:
#line 187 "prob1.y"
	{yyval.Node = yystack.l_mark[0].Node;}
#line 1587 "y.tab.c"
break;
case 26:
#line 189 "prob1.y"
	{yyval.Node = yystack.l_mark[0].Node;}
#line 1592 "y.tab.c"
break;
case 27:
#line 190 "prob1.y"
	{yyval.Node = yystack.l_mark[0].Node;}
#line 1597 "y.tab.c"
break;
case 28:
#line 191 "prob1.y"
	{yyval.Node = yystack.l_mark[0].Node;}
#line 1602 "y.tab.c"
break;
case 29:
#line 192 "prob1.y"
	{yyval.Node = yystack.l_mark[0].Node;}
#line 1607 "y.tab.c"
break;
case 30:
#line 194 "prob1.y"
	{yyval.Node=yystack.l_mark[0].Node;}
#line 1612 "y.tab.c"
break;
case 31:
#line 196 "prob1.y"
	{yyval.Node=yystack.l_mark[-1].Node;}
#line 1617 "y.tab.c"
break;
case 32:
#line 197 "prob1.y"
	{/*
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
		*/}
#line 1634 "y.tab.c"
break;
case 33:
#line 211 "prob1.y"
	{/*struct node* n = malloc(sizeof(struct node));
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

		yyval.Node = gentemp();
		printf("%s = %s+1\n", yyval.Node->string, yystack.l_mark[0].Node->string);
		printf("%s = %s\n", yystack.l_mark[0].Node->lexval, yyval.Node->string); 
		strcpy(yyval.Node->lexval, yystack.l_mark[0].Node->lexval);
		}
#line 1657 "y.tab.c"
break;
case 34:
#line 230 "prob1.y"
	{/*struct node* n = malloc(sizeof(struct node));
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

		yyval.Node = gentemp();
		printf("%s = %s-1\n", yyval.Node->string, yystack.l_mark[0].Node->string);
		printf("%s = %s\n", yystack.l_mark[0].Node->lexval, yyval.Node->string); 
		strcpy(yyval.Node->lexval, yystack.l_mark[0].Node->lexval);
		}
#line 1678 "y.tab.c"
break;
case 35:
#line 248 "prob1.y"
	{/*struct node* n = malloc(sizeof(struct node));
			$$ = n;
			$$->left = NULL;
			$$->right = NULL;
			char ch[2]; strcpy(ch, "++");
			strcat($1->lexval, ch);
			strcpy($$->lexval, $1->lexval);
			strcpy($$->tok, "VARIABLE");
		*/

		yyval.Node = gentemp();
		printf("%s = %s+1\n", yyval.Node->string, yystack.l_mark[-1].Node->string);
		printf("%s = %s\n", yystack.l_mark[-1].Node->lexval, yyval.Node->string); 
		yyval.Node = yystack.l_mark[-1].Node;
		}
#line 1697 "y.tab.c"
break;
case 36:
#line 264 "prob1.y"
	{/*struct node* n = malloc(sizeof(struct node));
			$$ = n;
			$$->left = NULL;
			$$->right = NULL;
			char ch[2]; strcpy(ch, "--");
			strcat($1->lexval, ch);
			strcpy($$->lexval, $1->lexval);
			strcpy($$->tok, "VARIABLE");
		*/
		yyval.Node = gentemp();
		printf("%s = %s-1\n", yyval.Node->string, yystack.l_mark[-1].Node->string);
		printf("%s = %s\n", yystack.l_mark[-1].Node->lexval, yyval.Node->string); 
		/*strcpy($$->lexval, $1->string);*/
		yyval.Node = yystack.l_mark[-1].Node;
		}
#line 1716 "y.tab.c"
break;
case 37:
#line 280 "prob1.y"
	{}
#line 1721 "y.tab.c"
break;
case 38:
#line 281 "prob1.y"
	{/*struct node* n = malloc(sizeof(struct node));
			$$ = n;
			$$->left = NULL;
			$$->right = NULL;
			$$->dval = yylval.dval;
			strcpy($$->tok, "NUMBER");*/
		yyval.Node = gentemp();
		yyval.Node->dval = yylval.dval;
		printf("%s = %d\n", yyval.Node, yylval.dval);  
		}
#line 1735 "y.tab.c"
break;
case 39:
#line 291 "prob1.y"
	{/*struct node* n = malloc(sizeof(struct node));
			$$ = n;
			$$->left = NULL;
			$$->right = NULL;
			$$->dval = (-1*$2->dval);
			strcpy($$->tok, "NUMBER");
		*/
		yyval.Node = gentemp();
		yyval.Node->dval = -1*yylval.dval;
		printf("%s = %d\n", yyval.Node, yyval.Node->dval); 
	}
#line 1750 "y.tab.c"
break;
case 40:
#line 303 "prob1.y"
	{/*struct node* n = malloc(sizeof(struct node));
			$$ = n;
			$$->left = NULL;
			$$->right = NULL;
			strcpy($$->lexval, yylval.lexeme);
			strcpy($$->tok, "VARIABLE");
		*/
		
		yyval.Node = gentemp();
		strcpy(yyval.Node->lexval,yylval.lexeme);
		printf("%s = %s\n", yyval.Node->string, yylval.lexeme); 
		}
#line 1766 "y.tab.c"
break;
case 41:
#line 315 "prob1.y"
	{/*struct node* n = malloc(sizeof(struct node));
			$$ = n;
			$$->left = NULL;
			$$->right = NULL;
			char d[1]; strcpy(d, "-");
			strcat(d, $2->lexval);
			strcpy($$->lexval, d);
			strcpy($$->tok, "VARIABLE");
		*/
		yyval.Node = gentemp();
	char temp[30] = "-";
		strcat(temp, yylval.lexeme);
		printf("%s = %s\n", yyval.Node->string, yylval.lexeme);
		printf("%s = -1*%s\n", yyval.Node->string, yyval.Node->string); 

		strcpy(yyval.Node->lexval,temp);
	}
#line 1787 "y.tab.c"
break;
case 42:
#line 333 "prob1.y"
	{
		/*struct node* n = malloc(sizeof(struct node));
		$$ = n;
		//$$->left = NULL;
		//$$->right = NULL;
		strcpy($$->lexval, yylval.lexeme);
		strcpy($$->tok, "BOOLTRUE");*/
		yyval.Node = gentemp();
		strcpy(yyval.Node->lexval,yylval.lexeme);
		printf("%s = %s\n", yyval.Node->string, yylval.lexeme); 
		}
#line 1802 "y.tab.c"
break;
case 43:
#line 344 "prob1.y"
	{/*
		struct node* n = malloc(sizeof(struct node));
		$$ = n;
		//$$->left = NULL;
		//$$->right = NULL;
		strcpy($$->lexval, yylval.lexeme);
		strcpy($$->tok, "BOOLFALSE");*/
		yyval.Node = gentemp();
		strcpy(yyval.Node->lexval,yylval.lexeme);
		printf("%s = %s\n", yyval.Node->string, yylval.lexeme); 
		}
#line 1817 "y.tab.c"
break;
case 44:
#line 359 "prob1.y"
	{
	
		yyval.Node = gentemp();
		printf("%s = %s %s %s\n", yyval.Node->string, yystack.l_mark[-2].Node->string, yystack.l_mark[-1].Node->lexval, yystack.l_mark[0].Node->string);
		}
#line 1826 "y.tab.c"
break;
case 45:
#line 364 "prob1.y"
	{
	
		yyval.Node = yystack.l_mark[0].Node;
		}
#line 1834 "y.tab.c"
break;
case 46:
#line 371 "prob1.y"
	{
	
		yyval.Node = gentemp();
		printf("%s = %s %s %s\n", yyval.Node->string, yystack.l_mark[-2].Node->string, yystack.l_mark[-1].Node->lexval, yystack.l_mark[0].Node->string);
	}
#line 1843 "y.tab.c"
break;
case 47:
#line 376 "prob1.y"
	{
		yyval.Node = gentemp();
		printf("%s = %s\n", yyval.Node->string, yystack.l_mark[0].Node->string);
			
	}
#line 1852 "y.tab.c"
break;
case 48:
#line 381 "prob1.y"
	{yyval.Node=yystack.l_mark[-1].Node;}
#line 1857 "y.tab.c"
break;
case 49:
#line 382 "prob1.y"
	{
		yyval.Node = gentemp();
		printf("%s = !%s\n", yyval.Node->string, yystack.l_mark[0].Node->string);
		}
#line 1865 "y.tab.c"
break;
case 50:
#line 388 "prob1.y"
	{
		struct node* n = malloc(sizeof(struct node));
		yyval.Node = n;
		/*$$->left = NULL;*/
		/*$$->right = NULL;*/
		strcpy(yyval.Node->lexval, yylval.lexeme);
		strcpy(yyval.Node->tok, "BOOLOP");
		}
#line 1877 "y.tab.c"
break;
case 51:
#line 396 "prob1.y"
	{
		struct node* n = malloc(sizeof(struct node));
		yyval.Node = n;
		/*$$->left = NULL;*/
		/*$$->right = NULL;*/
		strcpy(yyval.Node->lexval, yylval.lexeme);
		strcpy(yyval.Node->tok, "BOOLOP");
		}
#line 1889 "y.tab.c"
break;
case 52:
#line 406 "prob1.y"
	{
		struct node* n = malloc(sizeof(struct node));
		yyval.Node = n;
		/*$$->left = NULL;*/
		/*$$->right = NULL;*/
		strcpy(yyval.Node->lexval, yylval.lexeme);
		strcpy(yyval.Node->tok, "RELOP");
		}
#line 1901 "y.tab.c"
break;
case 53:
#line 414 "prob1.y"
	{
		struct node* n = malloc(sizeof(struct node));
		yyval.Node = n;
		/*$$->left = NULL;*/
		/*$$->right = NULL;*/
		strcpy(yyval.Node->lexval, yylval.lexeme);
		strcpy(yyval.Node->tok, "RELOP");
		}
#line 1913 "y.tab.c"
break;
case 54:
#line 422 "prob1.y"
	{
		struct node* n = malloc(sizeof(struct node));
		yyval.Node = n;
		/*$$->left = NULL;*/
		/*$$->right = NULL;*/
		strcpy(yyval.Node->lexval, yylval.lexeme);
		strcpy(yyval.Node->tok, "RELOP");
		}
#line 1925 "y.tab.c"
break;
case 55:
#line 430 "prob1.y"
	{
		struct node* n = malloc(sizeof(struct node));
		yyval.Node = n;
		/*$$->left = NULL;*/
		/*$$->right = NULL;*/
		strcpy(yyval.Node->lexval, yylval.lexeme);
		strcpy(yyval.Node->tok, "RELOP");
		}
#line 1937 "y.tab.c"
break;
case 56:
#line 438 "prob1.y"
	{
		struct node* n = malloc(sizeof(struct node));
		yyval.Node = n;
		/*$$->left = NULL;*/
		/*$$->right = NULL;*/
		strcpy(yyval.Node->lexval, yylval.lexeme);
		strcpy(yyval.Node->tok, "RELOP");
		}
#line 1949 "y.tab.c"
break;
case 57:
#line 446 "prob1.y"
	{
		struct node* n = malloc(sizeof(struct node));
		yyval.Node = n;
		/*$$->left = NULL;*/
		/*$$->right = NULL;*/
		strcpy(yyval.Node->lexval, yylval.lexeme);
		strcpy(yyval.Node->tok, "RELOP");
		}
#line 1961 "y.tab.c"
break;
#line 1963 "y.tab.c"
    default:
        break;
    }
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    yystack.p_mark -= yym;
#endif
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
        {
            fprintf(stderr, "%s[%d]: after reduction, ", YYDEBUGSTR, yydepth);
#ifdef YYSTYPE_TOSTRING
#if YYBTYACC
            if (!yytrial)
#endif /* YYBTYACC */
                fprintf(stderr, "result is <%s>, ", YYSTYPE_TOSTRING(yystos[YYFINAL], yyval));
#endif
            fprintf(stderr, "shifting from state 0 to final state %d\n", YYFINAL);
        }
#endif
        yystate = YYFINAL;
        *++yystack.s_mark = YYFINAL;
        *++yystack.l_mark = yyval;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
        *++yystack.p_mark = yyloc;
#endif
        if (yychar < 0)
        {
#if YYBTYACC
            do {
            if (yylvp < yylve)
            {
                /* we're currently re-reading tokens */
                yylval = *yylvp++;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                yylloc = *yylpp++;
#endif
                yychar = *yylexp++;
                break;
            }
            if (yyps->save)
            {
                /* in trial mode; save scanner results for future parse attempts */
                if (yylvp == yylvlim)
                {   /* Enlarge lexical value queue */
                    size_t p = (size_t) (yylvp - yylvals);
                    size_t s = (size_t) (yylvlim - yylvals);

                    s += YYLVQUEUEGROWTH;
                    if ((yylexemes = (YYINT *)realloc(yylexemes, s * sizeof(YYINT))) == NULL)
                        goto yyenomem;
                    if ((yylvals   = (YYSTYPE *)realloc(yylvals, s * sizeof(YYSTYPE))) == NULL)
                        goto yyenomem;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                    if ((yylpsns   = (YYLTYPE *)realloc(yylpsns, s * sizeof(YYLTYPE))) == NULL)
                        goto yyenomem;
#endif
                    yylvp   = yylve = yylvals + p;
                    yylvlim = yylvals + s;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                    yylpp   = yylpe = yylpsns + p;
                    yylplim = yylpsns + s;
#endif
                    yylexp  = yylexemes + p;
                }
                *yylexp = (YYINT) YYLEX;
                *yylvp++ = yylval;
                yylve++;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                *yylpp++ = yylloc;
                yylpe++;
#endif
                yychar = *yylexp++;
                break;
            }
            /* normal operation, no conflict encountered */
#endif /* YYBTYACC */
            yychar = YYLEX;
#if YYBTYACC
            } while (0);
#endif /* YYBTYACC */
            if (yychar < 0) yychar = YYEOF;
#if YYDEBUG
            if (yydebug)
            {
                if ((yys = yyname[YYTRANSLATE(yychar)]) == NULL) yys = yyname[YYUNDFTOKEN];
                fprintf(stderr, "%s[%d]: state %d, reading token %d (%s)\n",
                                YYDEBUGSTR, yydepth, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == YYEOF) goto yyaccept;
        goto yyloop;
    }
    if (((yyn = yygindex[yym]) != 0) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT) yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
    {
        fprintf(stderr, "%s[%d]: after reduction, ", YYDEBUGSTR, yydepth);
#ifdef YYSTYPE_TOSTRING
#if YYBTYACC
        if (!yytrial)
#endif /* YYBTYACC */
            fprintf(stderr, "result is <%s>, ", YYSTYPE_TOSTRING(yystos[yystate], yyval));
#endif
        fprintf(stderr, "shifting from state %d to state %d\n", *yystack.s_mark, yystate);
    }
#endif
    if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
    *++yystack.s_mark = (YYINT) yystate;
    *++yystack.l_mark = yyval;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    *++yystack.p_mark = yyloc;
#endif
    goto yyloop;
#if YYBTYACC

    /* Reduction declares that this path is valid. Set yypath and do a full parse */
yyvalid:
    if (yypath) YYABORT;
    while (yyps->save)
    {
        YYParseState *save = yyps->save;
        yyps->save = save->save;
        save->save = yypath;
        yypath = save;
    }
#if YYDEBUG
    if (yydebug)
        fprintf(stderr, "%s[%d]: state %d, CONFLICT trial successful, backtracking to state %d, %d tokens\n",
                        YYDEBUGSTR, yydepth, yystate, yypath->state, (int)(yylvp - yylvals - yypath->lexeme));
#endif
    if (yyerrctx)
    {
        yyFreeState(yyerrctx);
        yyerrctx = NULL;
    }
    yylvp          = yylvals + yypath->lexeme;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    yylpp          = yylpsns + yypath->lexeme;
#endif
    yylexp         = yylexemes + yypath->lexeme;
    yychar         = YYEMPTY;
    yystack.s_mark = yystack.s_base + (yypath->yystack.s_mark - yypath->yystack.s_base);
    memcpy (yystack.s_base, yypath->yystack.s_base, (size_t) (yystack.s_mark - yystack.s_base + 1) * sizeof(YYINT));
    yystack.l_mark = yystack.l_base + (yypath->yystack.l_mark - yypath->yystack.l_base);
    memcpy (yystack.l_base, yypath->yystack.l_base, (size_t) (yystack.l_mark - yystack.l_base + 1) * sizeof(YYSTYPE));
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    yystack.p_mark = yystack.p_base + (yypath->yystack.p_mark - yypath->yystack.p_base);
    memcpy (yystack.p_base, yypath->yystack.p_base, (size_t) (yystack.p_mark - yystack.p_base + 1) * sizeof(YYLTYPE));
#endif
    yystate        = yypath->state;
    goto yyloop;
#endif /* YYBTYACC */

yyoverflow:
    YYERROR_CALL("yacc stack overflow");
#if YYBTYACC
    goto yyabort_nomem;
yyenomem:
    YYERROR_CALL("memory exhausted");
yyabort_nomem:
#endif /* YYBTYACC */
    yyresult = 2;
    goto yyreturn;

yyabort:
    yyresult = 1;
    goto yyreturn;

yyaccept:
#if YYBTYACC
    if (yyps->save) goto yyvalid;
#endif /* YYBTYACC */
    yyresult = 0;

yyreturn:
#if defined(YYDESTRUCT_CALL)
    if (yychar != YYEOF && yychar != YYEMPTY)
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
        YYDESTRUCT_CALL("cleanup: discarding token", yychar, &yylval, &yylloc);
#else
        YYDESTRUCT_CALL("cleanup: discarding token", yychar, &yylval);
#endif /* defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED) */

    {
        YYSTYPE *pv;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
        YYLTYPE *pp;

        for (pv = yystack.l_base, pp = yystack.p_base; pv <= yystack.l_mark; ++pv, ++pp)
             YYDESTRUCT_CALL("cleanup: discarding state",
                             yystos[*(yystack.s_base + (pv - yystack.l_base))], pv, pp);
#else
        for (pv = yystack.l_base; pv <= yystack.l_mark; ++pv)
             YYDESTRUCT_CALL("cleanup: discarding state",
                             yystos[*(yystack.s_base + (pv - yystack.l_base))], pv);
#endif /* defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED) */
    }
#endif /* defined(YYDESTRUCT_CALL) */

#if YYBTYACC
    if (yyerrctx)
    {
        yyFreeState(yyerrctx);
        yyerrctx = NULL;
    }
    while (yyps)
    {
        YYParseState *save = yyps;
        yyps = save->save;
        save->save = NULL;
        yyFreeState(save);
    }
    while (yypath)
    {
        YYParseState *save = yypath;
        yypath = save->save;
        save->save = NULL;
        yyFreeState(save);
    }
#endif /* YYBTYACC */
    yyfreestack(&yystack);
    return (yyresult);
}
