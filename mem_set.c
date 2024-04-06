#include "monty.h"

/**
 * mem_set- sets every byte of an allocated string to '\0'.
 *
 * @str: the string to be reset.
 *
 * Return: nothing.
 */

void mem_set(char *str)
{
	int i, l;

	l = strlen(str);
	for (i = 0; i < l; i++)
		str[i] = '\0';
}
