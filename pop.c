#include "monty.h"

/**
 * pop - removes the top element of the given stack
 * @top: pointer to top element of the stack
 * @line_number: line number of the current opcode
 *
 * Return: nothing
 */
void pop(stack_t **top, unsigned int line_number)
{
	if (top == NULL || *top == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		free(buffer);
		exit(EXIT_FAILURE);
	}
	if ((*top)->prev == NULL)
	{
		free(*top);
		*top = NULL;
	}
	else
	{
		*top = (*top)->prev;
		free((*top)->next);
		(*top)->next = NULL;
	}
}
