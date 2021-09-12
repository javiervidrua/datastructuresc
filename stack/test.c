#include "stack.c"


int main(int argc, char * argv[]){
	Stack s;
	
	stack_init(&s);
	stack_print(&s);
	
	Data d = { 1234 };
	printf("test: Pushing %d into the stack, return value: %d\n", d.data, stack_push(&s, d));
	stack_print(&s);
	
	d.data = 4321;
	printf("test: Pushing %d into the stack, return value: %d\n", d.data, stack_push(&s, d));
	stack_print(&s);
	
	printf("test: The size of the stack is %d\n", stack_size(&s));
	stack_print(&s);
	
	int r = stack_pop(&s, &d);
	printf("test: Popping %d from the stack, return value: %d\n", d.data, r);
	stack_print(&s);
	
	stack_clear(&s);
	stack_print(&s);
	
	printf("test: Pushing %d into the stack, return value: %d\n", d.data, stack_push(&s, d));
	stack_print(&s);
	
	return 0;
}
