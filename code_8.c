#include <stdio.h>
#include <stdlib.h>

typedef struct list_t
{
	int data;
	struct list_t * next;
} list;

void view (list * head)
{
	while (head != NULL)
	{
		printf("%d ", head->data);
		head = head->next;
	}
	printf("\r\n");
}

list * reverse_linked_list (list * head)
{
	list * curr = head;
	list * prev = NULL;
	list * next = NULL;
	
	while (curr != NULL)
	{
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	
	return prev;
}

int main()
{
	list * head = (list *) malloc (sizeof(list));
	list * first = (list *) malloc (sizeof(list));
	list * second = (list *) malloc (sizeof(list));
	list * third = (list *) malloc (sizeof(list));
	list * rev;
	
	head->data = 10;
	first->data = 11;
	second->data = 12;
	third->data = 13;
	
	head->next = first;
	first->next = second;
	second->next = third;
	third->next = NULL;
	
	view(head);
	
	rev = reverse_linked_list (head);
	
	view(rev);
	return 0;
}
