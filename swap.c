#include "monty.h"

/**
 * swap - swaps the top two elements of the stack
 * @top: pointer to top element of the stack
 * @line_number: line number of the current opcode
 *
 * Return: nothing
 */

void swap(stack_t **top, unsigned int line_number)
{
    int swp;
    swp = (*top)->n;
    (*top)->n = (*top)->prev->n;
    (*top)->prev->n = swp;

    if (*top == NULL || (*top)->prev == NULL)
    {
        printf("L%d: can't swap, stack too short\n", line_number);
        free(buffer);
        exit(EXIT_FAILURE);
    }
}
