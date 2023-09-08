#include "monty.h"

/**
 * mul - multiplies the second top element of the stack with the top element
 * @top: pointer to top element of the stack
 * @line_number: line number of the current opcode
 *
 * Return: nothing
 */
void mul(stack_t **top, unsigned int line_number)
{
	if (*top == NULL || (*top)->prev == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		free(buffer);
		exit(EXIT_FAILURE);
	}
	(*top)->prev->n *= (*top)->n;
	pop(top, line_number);
}
