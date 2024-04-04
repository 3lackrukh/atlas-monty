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

int main(int ac, char **av, char **env)
{
    int status = 1, line_ct = 0, i, match, value;
    stack_t *top = NULL;
    FILE *file;
    char *line = NULL, *token, *val_str;
    size_t len = 0;
    ssize_t read;

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
    while ((read = getline(&line, &len, file)) != -1)
    {
        line_ct++;
        /*tokenize line read with delimiters ( $)*/
        token = strtok(line, ' ');
        match = 0;
        for (i = 0; operations[i] != NULL && !match; i++)
        {
            if (!strcmp(token, operations[i].op_code))
            {
                match = 1;
                val_str = strtok(NULL, '$');
                value = atoi(val_str);
                operations[i]->f(&top, value);
            }
            else
            {
                fprintf(stderr, "L%d: unknown instruction %s\n", line_ct, token);
                free(line);
                exit(EXIT_FAILURE);
            }
	}
    }
    /*clean up allocated memory from line*/
    free(line);
    /*close file*/
    fclose(file);
    exit(EXIT_SUCCESS);
}

