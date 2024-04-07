#include "monty.h"

/**
 * nop- doesnt do anything.
 *
 * @stack: pointer to a pointer to the top of
 * the stack.
 *
 * @line_number: the line number in the open file.
 *
 * Return: nothing.
 */

void nop(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;

	mem_set(tools.line);
}
