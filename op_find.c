#include "monty.h"

/**
 * op_find- parses the file line in tools
 * checking for a matching operator. If found, the
 * corresponding function is called.
 * 
 * Return: nothing.
*/

void op_find(void)
{
    instruction_t ops = {
        {"push", push},
        {"pall", pall},
        {NULL, NULL},
    };
    char *token;
    int match = 0;

     /*tokenize line read with delimiters ( $)*/
    token = strtok(tools.line, " $");
    for (i = 0; ops[i].opcode != NULL && !match; i++)
    {
        if (!strcmp(token, ops[i].opcode))
        {
            match = 1;
            ops[i].f(&tools.stack, tools.line_ct);
        }
        else
        {
            fprintf(stderr, "L%d: unknown instruction %s\n", tools.line_ct, token);
            free(tools.line);
            exit(EXIT_FAILURE);
        }
    }
}