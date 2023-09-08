#include "monty.h"

/**
 * pchar - prints the char at the top of the stack, followed by a new line
 * @top: pointer to top element of the stack
 * @line_number: line number of the current opcode
 *
 * Return: nothing
 */

void pchar(stack_t **top, unsigned int line_number)
{
	if (top == NULL || *top == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		free(buffer);
		exit(EXIT_FAILURE);
	}
	if ((*top)->n < 0 || (*top)->n > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		free(buffer);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (*top)->n);
}
