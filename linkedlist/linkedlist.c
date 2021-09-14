#include "linkedlist.h"


// ========================================================================= //
void linkedlist_init(Linkedlist *l){
	printf("linkedlist: Initializing\n");

	l->first = l->last = NULL;
	l->size = 0;

	return;
}

void linkedlist_clear(Linkedlist *l){
	printf("linkedlist: Clearing\n");

	Node *temporal = NULL;
	
	while(l->first != NULL){
		temporal = l->first;
		l->first = l->first->next;
		free(temporal);
	}

	l->first = NULL;
	l->size = 0;
	
	return;
}

int linkedlist_add(Linkedlist *l, Data data){
	printf("linkedlist: Adding\n");

	Node *new = NULL;
	
	if(l->size >= LINKEDLIST_SIZE_MAX){
		return 1;
	}

	new = malloc(sizeof(Node)*1);
	new->data = data;
	
	if(l->first == NULL){
		new->next = l->first;
		l->first = new;
		l->last = new;
	}
	else{
		new->next = l->last->next;
		l->last->next = new;
		l->last = new;
	}
	
	l->size++;
	
	return 0;
}

int linkedlist_add_at_index(Linkedlist *l, Data data, int index){
	// index belongs to range(1, l->size)
	// out-of-range: return 1
	printf("linkedlist: Adding at index\n");

	int i = 1;
	Node *new = NULL, *last = l->first, *lastlast = l->first;

	if(index < 0 || index > LINKEDLIST_SIZE_MAX){
		return 1;
	}

	if(index == (l->size)+1){
		return linkedlist_add(l, data);
	}

	if(l->first == NULL){
		return 1;
	}

	new = malloc(sizeof(Node)*1);
	new->data = data;

	if(index == 1){
		new->next = l->first;
		l->first = new;
		
		l->size++;

		return 0;
	}

	while(last != NULL){
		if(i == index){
			new->next = lastlast->next;
			lastlast->next = new;

			l->size++;

			return 0;
		}
		
		lastlast = last;
		last = last->next;
		i++;
	}

	return 1;
}

int linkedlist_remove(Linkedlist *l, Data *data){
	printf("linkedlist: Removing\n");

	Node *last = l->first, *lastlast = l->first;

	while(last != NULL){
		if(last == l->last){
			l->last = lastlast;
			lastlast->next = NULL;
			l->size--;
			*data = last->data;
			free(last);
			
			return 0;
		}
		lastlast = last;
		last = last->next;
	}

	return 1;
}

int linkedlist_remove_at_index(Linkedlist *l, Data *data, int index){
	// index belongs to range(1, l->size)
	// out-of-range: return 1
	printf("linkedlist: Removing at index\n");

	int i = 1;
	Node *last = l->first, *lastlast = l->first;

	if(index < 0 || index > LINKEDLIST_SIZE_MAX){
		return 1;
	}

	if(index == l->size){
		return linkedlist_remove(l, data);
	}

	if(l->first == NULL){
		return 1;
	}

	if(index == 1){
		l->first = l->first->next;
		*data = last->data;
		free(last);
		
		l->size--;

		return 0;
	}

	while(last != NULL){
		if(i == index){
			lastlast->next = last->next;
			*data = last->data;
			free(last);
			
			l->size--;

			return 0;
		}
		
		lastlast = last;
		last = last->next;
		i++;
	}

	return 1;
}

int linkedlist_size(Linkedlist *l){
	printf("linkedlist: Sizing\n");
	
	return l->size;
}

void linkedlist_print(Linkedlist *l){
	printf("linkedlist: Printing\n");

	Node *first = l->first;
	int i = 1;
	
	while( l->size>0 && first!=NULL){
		printf("linkedlist: Node number %d, data: %d\n", i, first->data.data);
		first = first->next;
		i++;
	}
	
	return;
}