#include <stdio.h>
#include <stdlib.h>


// ========================================================================= //
#define STACK_SIZE_MAX 10


// ========================================================================= //
typedef struct Data{
	int data;
} Data;

typedef struct Node{
	Data data;
	struct Node *next;
} Node;

typedef struct Stack{
	Node *top;
	int size;
} Stack;


// ========================================================================= //
void stack_init(Stack *s);
void stack_clear(Stack *s);
int stack_pop(Stack *s, Data *data);
int stack_push(Stack *s, Data data);
int stack_size(Stack *s);
void stack_print(Stack *s);
