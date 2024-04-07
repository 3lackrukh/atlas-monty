#include "monty.h"

/**
 * swap- swaps the top two elements of
 * of a doubly linked stack.
 *
 * @stack: pointer to a pointer to the top of
 * the stack.
 *
 * @line_number: the line number in the open file.
 *
 * Return: nothing.
 */

void swap(stack_t **stack, unsigned int line_number)
{
	int a = 0;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		free_stack();
		free(tools.line);
		fclose(tools.file);
		exit(EXIT_FAILURE);
	}
	a = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = a;
	mem_set(tools.line);
}
