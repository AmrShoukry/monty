
#include "monty.h"

/**
 * check_opcode - convert opcode into digits
 * @op_code: op_code number
 * Return: op_code digits
 */

int check_argument(char *argument)
{
	int i = 0;

	if (argument == NULL)
		return (-1);

	while (argument[i] != '\0' && argument[i] != '\n')
	{
		if (!(argument[i] >= '0' && argument[i] <= '9'))
		{
			return (-1);
		}
		i++;
	}

	return (atoi(argument));
}

/**
 * processInstruction - chooses which function the line needs
 * @i: line number
 * @p: line from file
 * @top: the top of the stack
 */
void processInstruction(int i, stack_t **top, char *p)
{
	char *instruction = strtok(p, " ");
	char *argument = strtok(NULL, " ");
	char *clear_ins = strtok(instruction, "\n");
	int numcode = check_argument(argument);

	if (strcmp(clear_ins, "push") == 0)
	{
		if (numcode == -1)
		{
			fprintf(stderr, "L%i: usage: push integer\n", i);
			exit(EXIT_FAILURE);
		}
		else
			push(top, numcode);
	}
	else if (strcmp(clear_ins, "pall") == 0)
		pall(top);
	else if (strcmp(clear_ins, "pint") == 0)
		pint(top, i);
	else if (strcmp(clear_ins, "pop") == 0)
		pop(top, i);
	else if (strcmp(clear_ins, "swap") == 0)
		swap(top, i);
	else if (strcmp(clear_ins, "add") == 0)
		add(top, i);
	else if (strcmp(clear_ins, "nop") == 0)
		nop();
	else
	{
		fprintf(stderr, "L%i: unknown instruction %s\n", i, instruction);
		exit(EXIT_FAILURE);
	}
}

/**
 * allocateStack - ...
 * Return: new stack
 */
stack_t *allocateStack()
{
	stack_t *newStackMember = malloc(sizeof(stack_t));

	if (newStackMember == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	newStackMember->next = NULL;
	newStackMember->prev = NULL;
	return (newStackMember);
}
