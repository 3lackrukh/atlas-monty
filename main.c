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

int main(int ac, char **av)
{
    int i, match;
    unsigned int line_ct = 0;
    FILE *file;
    size_t len = 0;
    ssize_t read;
    toolbox tools = {
        line = NULL,
        line_ct = 0,
        stack = NULL,
    };

    /*check for 2 arguments*/
    if (ac != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }
    
    /*open file*/
    file = fopen(av[1], "r");
    if (file == NULL)
    {
        fprintf(stderr, "Error: Can't open file %s\n", av[1]);
        exit(EXIT_FAILURE);
    }

    /*read and parse line*/
    while ((read = getline(&tools.line, &len, file)) != -1)
    {
        if (tools.line_ct > 0)
            free(tools.line);
        tools.line_ct++;
        op_find;
        

	}
    /*clean up allocated memory from line*/
    free(tools.line);
    /*free linked list*/
    /*close file*/
    fclose(file);
    exit(EXIT_SUCCESS);
}

