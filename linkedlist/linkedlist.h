#include <stdio.h>
#include <stdlib.h>


// ========================================================================= //
#define LINKEDLIST_SIZE_MAX 10


// ========================================================================= //
typedef struct Data{
	int data;
} Data;

typedef struct Node{
	Data data;
	struct Node *next;
} Node;

typedef struct Linkedlist{
	Node *first;
	Node *last;
	int size;
} Linkedlist;


// ========================================================================= //
void linkedlist_init(Linkedlist *l);
void linkedlist_clear(Linkedlist *l);
int linkedlist_add(Linkedlist *l, Data data);
int linkedlist_add_at_index(Linkedlist *l, Data data, int index);
int linkedlist_remove(Linkedlist *l, Data *data);
int linkedlist_remove_at_index(Linkedlist *l, Data *data, int index);
int linkedlist_size(Linkedlist *l);
void linkedlist_print(Linkedlist *l);