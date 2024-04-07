#include "monty.h"
/**
 * pint- prints the top element in the stack.
 *
 * @stack: pointer to the top of the stack.
 *
 * @line_number: the current line number of the open file.
 *
 * Return: nothing.
 */

void pint(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		free(tools.line);
		fclose(tools.file);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", temp->n);
	mem_set(tools.line);
}
