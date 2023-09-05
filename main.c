#include "monty.h"

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
void pall(stack_t **top, __attribute__((unused)) unsigned int line_number)
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
	int data;

	if (top == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	node = malloc(sizeof(stack_t) * 1);
	if (node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	line = strtok(NULL, " \t");
	if (isdigit(*line) == 0)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	data = atoi(line);
	node->n = data;
	node->next = NULL;
	node->prev = *top;
	if (*top != NULL)
	{
		(*top)->next = node;
	}
	*top = node;
}

/**
 * get_opcode - find an opcode match for the given line
 * @top: pointer to top element of the stack
 * @line_number: given lin number of the instruction
 *
 * Return: nothing
 */
void get_opcode(stack_t **top, unsigned int line_number)
{
	unsigned int i = 0;
	char *token = NULL;
	instruction_t opcodes[] = {
		{"push", push},
		{"pall", pall},
		{NULL, NULL}
		};

	buffer[strlen(buffer) - 1] = '\0';
	while (opcodes[i].opcode != NULL)
	{
		token = strtok(buffer, " \t");
		if (token == NULL)
			return;
		if (strcmp(token, opcodes[i].opcode) == 0)
		{
			opcodes[i].f(top, i + 1);
			return;
		}
		i++;
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, token);
	free_stack(top);
	free(buffer);
	exit(EXIT_FAILURE);
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
	stack_t *top = NULL;
	unsigned int line_number = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fp = fopen(argv[1], "r");
	if (fp == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (getline(&buffer, &max_line_len, fp) != EOF)
	{
		line_number++;
		get_opcode(&top, line_number);
	}
	free(buffer);
	fclose(fp);
	free_stack(&top);
	return (0);
}
