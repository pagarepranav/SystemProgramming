CC=gcc
CFLAGS=-c -Wall
all: mysched

mysched:hw4.o
	$(CC) hw4.o -o mysched
hw4.o:hw4.c
	$(CC) $(CFLAGS) hw4.c
clean:
	rm -fr *o mysched
	
	
