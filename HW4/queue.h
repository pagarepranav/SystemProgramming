#ifndef QUEUE_H
#define QUEUE_H

typedef struct Queue{
	char* comm[5];
	int size;
	int status;
	char start[40];
	char end[40];
}Queue;

Queue* Q;
int front;
int back;
int check;

#endif
