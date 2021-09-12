#include "queue.h"


// ========================================================================= //
void queue_init(Queue *q){
	printf("queue: Initializing\n");
	
	q->top = NULL;
	q->size = 0;
	
	return;
}

void queue_clear(Queue *q){
	printf("queue: Clearing\n");
	
	Node *temporal = NULL;
	
	while(q->top != NULL){
		temporal = q->top;
		q->top = q->top->next;
		free(temporal);
	}

	q->top = NULL;
	q->size = 0;
	
	return;
}

int queue_pop(Queue *q, Data *data){
	printf("queue: Popping\n");
	
	Node * last = NULL, *lastlast = NULL;
	
	if(q->size <= 0){
		return 1;
	}

	else if(q->size == 1){
		*data = q->top->data;
		q->size--;
		free(q->top);
		q->top = NULL;

		return 0;
	}

	else{
		last = q->top;
		lastlast = last;

		// Search for the last and antepenultimate nodes
		while (last->next != NULL){
			lastlast = last;
			last = last->next;
		}

		*data = last->data;
		lastlast->next = NULL;
		q->size--;
		free(last);
		
		return 0;
	}

	return 0;	
}

int queue_push(Queue *q, Data data){
	printf("queue: Pushing\n");
	
	Node * new = NULL;
	
	if(q->size >= QUEUE_SIZE_MAX){
		return 1;
	}
	
	new = malloc(sizeof(Node)*1);
	new->data = data;
	new->next = q->top;
	q->top = new;
	q->size++;
	
	return 0;
}

int queue_size(Queue *q){
	printf("queue: Sizing\n");
	
	return q->size;
}

void queue_print(Queue *q){
	printf("queue: Printing\n");
	
	Node * top = q->top;
	int i = 1;
	
	while( q->size>0 && top!=NULL){
		printf("queue: Node number %d, data: %d\n", i, top->data.data);
		top = top->next;
		i++;
	}
	
	return;
}
