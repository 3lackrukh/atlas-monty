#include "monty.h"

/**
 * push- adds a new node at the top
 * of a doubly linked stack.
 *
 * @top: pointer to a pointer to the top of
 * the stack.
 *
 * @n: integer data to be stored in the new node.
 *
 * Return: the top of the stack.
 */

void push(stack_t **top, const int n)
{
	stack_t *new_node;

	if (top == NULL)
		return (NULL);

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
		return (NULL);

	new_node->n = n;
	new_node->prev = NULL;
	new_node->next = *top;

	if (*top != NULL)
		(*top)->prev = new_node;

	*top = new_node;
}
