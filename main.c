#include "monty.h"

char *buffer = NULL;

/**
 * free_stack - frees each element of the stack
 * @top: pointer to top element of the stack
 *
 * Return: nothing
*/
void free_stack(stack_t **top)
{
    stack_t *node;

    if (top == NULL)
        return;
    node = *top;
    while (node != NULL)
    {
        *top = (*top)->prev;
        free(node);
        node = *top;
    }
}

/**
 * pall - prints the stack from top to bottom
 * @top: pointer to top element of the stack
 * @line_number: line number of the current opcode
 *
 * Return: nothing
 */
void pall(stack_t **top, unsigned int line_number)
{
    stack_t *node;

    if (top == NULL)
        return;
    node = *top;
    while (node != NULL)
    {
        printf("%d\n", node->n);
        node = node->prev;
    }
}

/**
 * push - adds an element to the stack
 * @top: pointer to top element of the stack
 * @line_number: line number of the current opcode
 * Return: address of added node
 */
void push(stack_t **top, unsigned int line_number)
{
    stack_t *node = NULL;
    char *line = NULL;

    if (top == NULL)
    {
        fprintf(stderr, "L%d: usage: push integer", line_number);
        exit(EXIT_FAILURE);
    }
    fprintf(stderr, "L%d: usage: push integer", line_number);

    node->n = atoi(strtok(NULL, " "));
}

/**
 * main - for testing purposes
 * @argc: number of arguments passed to main
 * @argv: array of string arguments
 *
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
    FILE *fp;
    size_t max_line_len = 4096;
    unsigned int i = 0;
    char *token = NULL;
    stack_t **top = NULL;
    instruction_t opcodes[] = {
        {"push", push},
        {"pall", pall},
        {NULL, NULL}};

    if (argc != 2)
    {
        perror("USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }
    fp = fopen(argv[1], "r");
    if (fp == NULL)
    {
        fprintf(stderr, "Error: Can't open file %s", argv[1]);
        exit(EXIT_FAILURE);
    }
    while (getline(&buffer, &max_line_len, fp))
    {
        buffer[strlen(buffer) - 1] = '\0';
        /* find a match in opcodes[]*/
        while (opcodes[i].opcode != NULL)
        {
            token = strtok(buffer, " ");
            if (strcmp(token, opcodes[i].opcode) == 0)
            {
                opcodes[i].f(top, i + 1);
            }
            i++;
        }
    }
    fclose(fp);
    /* free linked list */
    return (0);
}