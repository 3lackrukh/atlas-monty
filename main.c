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
    size_t len = 0;
    ssize_t read;
    tools.file = NULL;
    tools.line = NULL;
    tools.line_ct = 0;
    tools.stack = NULL;

    if (ac != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }
    
    tools.file = fopen(av[1], "r");
    if (tools.file == NULL)
    {
        fprintf(stderr, "Error: Can't open file %s\n", av[1]);
        exit(EXIT_FAILURE);
    }
    while ((read = getline(&tools.line, &len, tools.file)) != -1)
    {
	    tools.line_ct++;
	    if (read == 1 || is_blank(tools.line))
		    continue;
        /*tools.line[read - 1] = '\0';*/
        op_find();
    }
    free(tools.line);
    free_stack();
    fclose(tools.file);
    exit(EXIT_SUCCESS);
}
