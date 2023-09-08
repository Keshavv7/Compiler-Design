
CFLAGS=-g -DDEBUG
CC=gcc

all: mylexer

mylexer: lex.yy.c
	$(CC) $(CFLAGS) lex.yy.c -o mylexer -ll

lex.yy.c: ip.l
	lex ip.l

clean: 
	rm -f *.o lex.yy.c mylexer
