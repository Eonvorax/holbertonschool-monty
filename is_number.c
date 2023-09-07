#include "monty.h"

/**
 * is_number - checks if given string is a number
 * @str: given string to check
 *
 * Return: 0 if string is a number, -1 if not
 */
int is_number(char *str)
{
	(void)buffer;
	int len = strlen(str);
	int i = 0;

	if (str[0] == '-')
		i++;
	for (; i < len; i++)
	{
		if (isdigit(str[i]) == 0)
		{
			return (-1);
		}
	}
	return (0);
}
