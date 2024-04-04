#include "monty.h"
/**
 * pall- prints the elements in the stack in LIFO order
 *
 * @top: pointer to the top of the stack.
 *
 * Return: nothing.
 */

void pall(const stack_t *top, int n)
{
    stack_t *temp = top;

    n = 0;
	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		n++;
		temp = temp->next;
	}
    printf("lines printed: %d\n", n)
}
