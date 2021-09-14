#include "linkedlist.c"


int main(int argc, char * argv[]){
	Linkedlist s;
	
	linkedlist_init(&s);
	linkedlist_print(&s);
	
	Data d = { 1234 };
	printf("test: Adding %d to the linkedlist, return value: %d\n", d.data, linkedlist_add(&s, d));
	linkedlist_print(&s);
	
	d.data = 4321;
	printf("test: Adding %d into the linkedlist at index 1, return value: %d\n", d.data, linkedlist_add_at_index(&s, d, 1));
	linkedlist_print(&s);
	
	printf("test: The size of the linkedlist is %d\n", linkedlist_size(&s));
	linkedlist_print(&s);
	
	int r = linkedlist_remove(&s, &d);
	printf("test: Removing from the linkedlist, return value: %d\n", d.data, r);
	linkedlist_print(&s);
	
	linkedlist_clear(&s);
	linkedlist_print(&s);
	
	d.data = 4321;
	printf("test: Adding %d into the linkedlist at index 1, return value: %d\n", d.data, linkedlist_add_at_index(&s, d, 1));
	linkedlist_print(&s);
	d.data = 1234;
	printf("test: Adding %d into the linkedlist at index 1, return value: %d\n", d.data, linkedlist_add_at_index(&s, d, 1));
	linkedlist_print(&s);

	r = linkedlist_remove_at_index(&s, &d, 1);
	printf("test: Removing from the linkedlist at index 1, return value: %d\n", d.data, r);
	linkedlist_print(&s);
	
	return 0;
}
