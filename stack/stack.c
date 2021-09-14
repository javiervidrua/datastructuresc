#include "stack.h"


// ========================================================================= //
void stack_init(Stack *s){
	printf("stack: Initializing\n");
	
	s->top = NULL;
	s->size = 0;
	
	return;
}

void stack_clear(Stack *s){
	printf("stack: Clearing\n");
	
	Node *temporal = NULL;
	
	while(s->top != NULL){
		temporal = s->top;
		s->top = s->top->next;
		free(temporal);
	}

	s->top = NULL;
	s->size = 0;
	
	return;
}

int stack_pop(Stack *s, Data *data){
	printf("stack: Popping\n");
	
	Node *top = NULL;
	
	if(s->size <= 0){
		return 1;
	}

	*data = s->top->data;
	top = s->top;
	s->top = s->top->next;
	s->size--;
	free(top);
	
	return 0;	
}

int stack_push(Stack *s, Data data){
	printf("stack: Pushing\n");
	
	Node *new = NULL;
	
	if(s->size >= STACK_SIZE_MAX){
		return 1;
	}
	
	new = malloc(sizeof(Node)*1);
	new->data = data;
	new->next = s->top;
	s->top = new;
	s->size++;
	
	return 0;
}

int stack_size(Stack *s){
	printf("stack: Sizing\n");
	
	return s->size;
}

void stack_print(Stack *s){
	printf("stack: Printing\n");
	
	Node *top = s->top;
	int i = 1;
	
	while( s->size>0 && top!=NULL){
		printf("stack: Node number %d, data: %d\n", i, top->data.data);
		top = top->next;
		i++;
	}
	
	return;
}
