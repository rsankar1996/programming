#include <stdio.h>
#include <stdlib.h>

typedef struct mem_log
{
	void * ptr;
	size_t size;
	const char * file;
	int line;
	struct mem_log * next;
} mem_log_t;

mem_log_t * head;

#define safe_malloc(size)	mem_malloc(size, __FILE__, __LINE__)
#define safe_free(ptr)		mem_free(ptr)

void * mem_malloc (size_t size, const char * file, int line)
{
	void * ptr = malloc (size);
	if (NULL == ptr)
	{
		return NULL;
	}
	
	mem_log_t * node = (mem_log_t *) malloc (sizeof (mem_log_t));
	if (NULL == node)
	{
		return NULL;
	}

	node->ptr = ptr;
	node->size = size;
	node->file = file;
	node->line = line;
	node->next = head;
	head = node;
	
	return ptr;
}

void mem_free (void * ptr)
{
	mem_log_t ** curr = &head;
	mem_log_t * prev = NULL;
	
	while ((*curr)->ptr != ptr)
	{
		prev = *curr;
		*curr = (*curr)->next;
	}
	
	if (NULL == (*curr))
	{
		printf ("invalid free memory\r\n");
		return;
	}
	
	printf ("found address %p\r\n", (*curr)->ptr);
	
	mem_log_t * tmp = (*curr)->next;

	free ((*curr)->ptr);
	free ((*curr));
	
	if (NULL == prev)
	{
		prev = tmp;
	}
	else
	{
		prev->next = tmp;
	}
}

int check_mem_leak ()
{
	mem_log_t * tmp = head;

	while (NULL != tmp)
	{
		printf("Memory leak detected at %p address, allocated at %d line of %s file for %ld size\r\n", tmp->ptr, tmp->line, tmp->file, tmp->size);
		tmp = tmp->next;
	}
}

int main ()
{
	int * ptr1 = safe_malloc(10);
	int * ptr2 = safe_malloc(20);
	int * ptr3 = safe_malloc(25);

	check_mem_leak();
	
	printf ("free ptr3\r\n");
	
	safe_free (ptr3);
	
	check_mem_leak();
}


