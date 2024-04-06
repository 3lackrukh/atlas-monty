#include "monty.h"

/**
 * op_find- parses the file line in tools
 * checking for a matching operator.
 * If found, the corresponding function is called.
 *
 * Return: nothing.
*/

void op_find(void)
{
	instruction_t ops[] = {
		{"push", push},
		{"pall", pall},
		{NULL, NULL}
	};
	char *token;
	int match, i;

	token = strtok(tools.line, " $\n");
	match = 0;
	for (i = 0; ops[i].opcode != NULL && !match; i++)
	{
		if (!strcmp(token, ops[i].opcode))
		{
			match = 1;
			ops[i].f(&tools.stack, tools.line_ct);
		}
	}
	if (match == 0)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", tools.line_ct, token);
		free(tools.line);
		free_stack();
		fclose(tools.file);
		exit(EXIT_FAILURE);
	}
}
