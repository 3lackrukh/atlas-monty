#include "monty.h"

/**
 * push- adds a new node at the top
 * of a doubly linked stack.
 *
 * @stack: pointer to a pointer to the top of
 * the stack.
 *
 * @line_number: the line number in the open file.
 *
 * Return: nothing.
 */

void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node;
	char *val_str;
	int value;
	
	(void) line_number;
	strtok(tools.line, " $");
	val_str = strtok(tools.line, " $");
	printf("value found = %s\n", val_str);
	value = atoi(val_str);
	printf("converted to int %d\n", value);
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free(tools.line);
		free_stack();
		exit(EXIT_FAILURE);
	}
	new_node->n = value;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack != NULL)
		(*stack)->prev  = new_node;

	*stack = new_node;
}
