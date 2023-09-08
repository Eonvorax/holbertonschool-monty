#include "monty.h"

/**
 * pstr - prints the string starting at the top of the stack, then a new line
 * @top: pointer to top element of the stack
 * @line_number: line number of the current opcode
 *
 * Description: The integer stored in each element of the stack is treated as
 * the ascii value of the character to be printed
 * The string stops when either:
 *      the stack is over
 *      the value of the element is 0
 *      the value of the element is not in the ascii table
 *
 * Return: nothing
 */

void pstr(stack_t **top, unsigned int line_number)
{
	(void)line_number;
	(void)buffer;
	stack_t *node;

	if (top == NULL || *top == NULL)
	{
		printf("\n");
		return;
	}
	node = *top;
	while (node != NULL && node->n > 0 && node->n < 128)
	{
		printf("%c", node->n);
		node = node->prev;
	}
	printf("\n");
}
