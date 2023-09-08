#include "monty.h"

/**
 * sub - subtracts the top element of the stack from the 2nd top element
 * @top: pointer to top element of the stack
 * @line_number: line number of the current opcode
 *
 * Return: nothing
 */
void sub(stack_t **top, unsigned int line_number)
{
	if (*top == NULL || (*top)->prev == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		free(buffer);
		exit(EXIT_FAILURE);
	}
	(*top)->prev->n -= (*top)->n;
	pop(top, line_number);
}
