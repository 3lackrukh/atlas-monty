#include "monty.h"

/**
 * add- adds the top two elements of
 * of a doubly linked stack.
 *
 * @stack: pointer to a pointer to the top of
 * the stack.
 *
 * @line_number: the line number in the open file.
 *
 * Return: nothing.
 */

void add(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		free_stack();
		free(tools.line);
		fclose(tools.file);
		exit(EXIT_FAILURE);
	}
	*stack = (*stack)->next;
	(*stack)->n = ((*stack)->n + (*stack)->prev->n);
	(*stack)->prev = NULL;
	free(temp);
	mem_set(tools.line);
}
