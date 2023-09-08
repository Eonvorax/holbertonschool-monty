#include "monty.h"

/**
 * rotr - rotates bottom element of the stack to the top
 * @top: pointer to top element of the stack
 * @line_number: line number of the current opcode
 *
 * Return: nothing
 */
void rotr(stack_t **top, unsigned int line_number)
{
	(void)line_number;
	(void)buffer;
	stack_t *bottom, *new_bottom;

	if (top == NULL || *top == NULL || (*top)->prev == NULL)
	{
		return;
	}
	bottom = *top;
	while (bottom->prev != NULL)
	{
		bottom = bottom->prev;
	}
	new_bottom = bottom->next;
	new_bottom->prev = NULL;
	bottom->next = NULL;
	bottom->prev = (*top);
	(*top)->next = bottom;
	*top = bottom;
}
