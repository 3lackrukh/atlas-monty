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

void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = line_number;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack != NULL)
		(*stack)->prev  = new_node;

	*stack = new_node;
}
