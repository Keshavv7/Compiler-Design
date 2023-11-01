#ifndef _yy_defines_h_
#define _yy_defines_h_

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
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union YYSTYPE {
	int dval;
	char lexeme[20];
	struct node* Node;	 
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
extern YYSTYPE yylval;

#endif /* _yy_defines_h_ */
