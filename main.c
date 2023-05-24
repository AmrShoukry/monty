#define  _POSIX_C_SOURCE 200809L
#include "monty.h"
#include <stdio.h>

/**
 * main - handles the file
 * opens the file specified in argv[1
 * @argc: number of args, should always be 2
 * @argv: the args
 * Return: exit code
 */
int main(int argc, char *argv[])
{
	FILE *fptr;
	stack_t *stack = NULL;
	char *buffer = NULL;
	size_t bufSize = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (8);/*need to validate if this is the correct EXIT_FAILURE*/
	}

	fptr = fopen(argv[1], "r");

	while (getline(&buffer, &bufSize, fptr) != -1)
	{
		processInstruction(&stack, buffer);
		freeCharPointer(&buffer);
	}
	freeCharPointer(&buffer);

	freeStack(&stack);

	return (0);
}
