CFLAGS=-g -DDEBUG
LINKERFLAG=-ll
CC=gcc

all: lexer

lexer: lex.yy.c
	$(CC) $(CFLAGS) lex.yy.c -o lexer $(LINKERFLAG)

lex.yy.c: lexer.l
	flex lexer.l

clean:
	rm -f lexer lex.yy.c
