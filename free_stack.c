#include "monty.h"

/**
 * free_stack- frees memory allocated to the stack.
 * 
 * Return: nothing.
*/

void free_stack(void)
{
	stack_t *current;
	stack_t *next;

	current = *tools.stack;
	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
}
