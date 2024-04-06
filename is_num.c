#include "monty.h"

/**
 * is_num- checks whether a string contains only numbers.
 *
 * @str: the string to be checked.
 *
 * Return: 1 if true, 0 if false.
 */

int is_num(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
	{
		if ((str[i] < '0' || str[i] > '9') && (str[i] != '+') && (str[i] != '-'))
			return (0);
	}
	return (1);
}
