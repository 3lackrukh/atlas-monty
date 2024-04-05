#include "monty.h"

/**
 * free_stack- frees memory allocated to the stack.
 * 
 * Return: nothing.
*/

void free_stack(void)
{
	stack_t *current = tools.stack;
	stack_t *next;

	while (current != NULL)
	{
		next = current->next;
		free(current->n);
		free(current);
		current = next;
	}
}
