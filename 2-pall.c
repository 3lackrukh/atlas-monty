#include "monty.h"
/**
 * pall- prints the elements in the stack in LIFO order
 *
 * @top: pointer to the top of the stack.
 *
 * Return: nothing.
 */

void pall(stack_t **stack, unsigned int line_number)
{
    stack_t *temp = *stack;
    unsigned int i;

	(void)line_number;
	for (i = 0; temp != NULL; i++)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
    printf("lines printed: %d\n", i);
}
