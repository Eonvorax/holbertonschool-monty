#include "monty.h"

/**
 * rotl - rotates top element of the stack to the bottom
 * @top: pointer to top element of the stack
 * @line_number: line number of the current opcode
 *
 * Return: nothing
 */
void rotl(stack_t **top, unsigned int line_number)
{
	(void)line_number;
	(void)buffer;
	stack_t *bottom, *new_top;

	if (top == NULL || *top == NULL || (*top)->prev == NULL)
	{
		return;
	}
	bottom = *top;
	while (bottom->prev != NULL)
	{
		bottom = bottom->prev;
	}
	new_top = (*top)->prev;
	(*top)->prev->next = NULL;
	(*top)->prev = NULL;
	(*top)->next = bottom;
	bottom->prev = (*top);
	*top = new_top;
}
