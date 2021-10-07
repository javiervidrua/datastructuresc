#include <stdio.h>
#include <stdlib.h>


// ========================================================================= //
#ifndef QUEUE_H
#define QUEUE_H
#define QUEUE_SIZE_MAX 10


// ========================================================================= //
typedef struct Data{
	int data;
} Data;

typedef struct Node{
	Data data;
	struct Node *next;
} Node;

typedef struct Queue{
	Node *top;
	int size;
} Queue;


// ========================================================================= //
void queue_init(Queue *q);
void queue_clear(Queue *q);
int queue_pop(Queue *q, Data *data);
int queue_push(Queue *q, Data data);
int queue_size(Queue *q);
void queue_print(Queue *q);
#endif // QUEUE_H