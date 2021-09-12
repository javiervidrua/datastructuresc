#include "queue.c"


int main(int argc, char * argv[]){
	Queue q;
	
	queue_init(&q);
	queue_print(&q);
	
	Data d = { 1234 };
	printf("test: Pushing %d into the queue, return value: %d\n", d.data, queue_push(&q, d));
	queue_print(&q);
	
	Data dd = { 9876 };
	printf("test: Pushing %d into the queue, return value: %d\n", dd.data, queue_push(&q, dd));
	queue_print(&q);
	
	printf("test: The size of the queue is %d\n", queue_size(&q));
	queue_print(&q);
	
	int r = queue_pop(&q, &d);
	printf("test: Popping %d from the queue, return value: %d\n", d.data, r);
	queue_print(&q);
	
	queue_clear(&q);
	queue_print(&q);
	
	printf("test: Pushing %d into the queue, return value: %d\n", d.data, queue_push(&q, d));
	queue_print(&q);
	
	return 0;
}
