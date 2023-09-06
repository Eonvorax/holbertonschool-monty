#include "monty.h"

/**
 * add - adds the top two elements of the stack, removing the top one
 * @top: pointer to top element of the stack
 * @line_number: line number of the current opcode
 *
 * Return: nothing
 */
void add(stack_t **top, unsigned int line_number)
{
	if (*top == NULL || (*top)->prev == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		free(buffer);
		exit(EXIT_FAILURE);
	}
	(*top)->prev->n += (*top)->n;
	pop(top, line_number);
}
