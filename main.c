#include "monty.h"

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
    return (0);
}