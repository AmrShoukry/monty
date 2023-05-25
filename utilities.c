#include "monty.h"

/**
 * trim_text - remove whitespaces
 * @text: input instruction
 * Return: trimmed text
 */

char *trim_text(char *text)
{
		while (*text == ' ' || *text == 9)
			text++;
		return (text);
}

/**
 * check_argument - convert argument into digits
 * @argument: argument number
 * Return: argument digits
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
	char *trimmed_p = trim_text(p);
	char *instruction = strtok(trimmed_p, " ");
	char *argument = strtok(NULL, " ");
	char *clear_ins = strtok(instruction, "\n");
	int numcode = check_argument(argument);

	if (clear_ins == NULL || clear_ins == "")
		return;

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
