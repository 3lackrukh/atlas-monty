#include "monty.h"

/**
 * is_blank- checks a string to see if it is all whitespace.
 *
 * @str: the string to be checked.
 *
 * Return: 1 if the line is all whitespace. 0 if not.
 */

int is_blank(char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		if (str[i] != ' ' && str[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}
