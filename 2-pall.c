#include "monty.h"
/**
 * pall- prints the elements in the stack in LIFO order
 *
 * @stack: pointer to the top of the stack.
 *
 * @line_number: the current line number of the open file.
 *
 * Return: nothing.
 */

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	unsigned int i;

	(void)line_number;
	if (*stack == NULL)
		return;
	for (i = 0; temp != NULL; i++)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
	mem_set(tools.line);
}
