#include "monty.h"

/**
 * pint - prints the value at the top of the stack
 * @top: pointer to top element of the stack
 * @line_number: line number of the current opcode
 *
 * Return: nothing
 */

void pint(stack_t **top, unsigned int line_number)
{
    if (top == NULL || *top == NULL)
    {
        fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
        free(buffer);
        exit(EXIT_FAILURE);
    }
    printf("%d\n", (*top)->n);
}