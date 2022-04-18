CC=gcc
CFLAGS=-c -Wall
all: uab_sh hello fibonacci

uab_sh:shell.o
	$(CC) shell.o -o uab_sh

shell.o:shell.c
	$(CC) $(CFLAGS) shell.c

hello:hello.o
	$(CC) hello.o -o hello
	
hello.o:hello.c
	$(CC) $(CFLAGS) hello.c

fibonacci:fib.o
	$(CC) fib.o -o fibonacci

fib.o:fib.c
	$(CC) $(CFLAGS) fib.c

clean:
	rm -fr *o uab_sh hello fibonacci
