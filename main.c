#include "monty.h"

/**
 * main - the file interpreter loop for executing monty bytecode files.
 * 
 * @ac: Argument count.
 * 
 * @av: vector of arguments.
 * 
 * @env: vector of environment variables.
*/
toolbox tools;

int main(int ac, char **av)
{
    FILE *file;
    size_t len = 0;
    ssize_t read;
    tools.line = NULL;
    tools.line_ct = 0;
    tools.stack = NULL;

    if (ac != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }
    
    file = fopen(av[1], "r");
    if (file == NULL)
    {
        fprintf(stderr, "Error: Can't open file %s\n", av[1]);
        exit(EXIT_FAILURE);
    }

    while ((read = getline(&tools.line, &len, file)) != -1)
    {
        if (tools.line_ct > 0)
            free(tools.line);
        printf("bytes read on line %d = %d", read, line_ct);
        tools.line[read - 1] = '\0';
        tools.line_ct++;
        printf("line to run: %s\n", tools.line);
        op_find();
	}
    free(tools.line);
    free_stack();
    fclose(file);
    exit(EXIT_SUCCESS);
}

