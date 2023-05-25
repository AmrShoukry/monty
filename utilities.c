
#include "monty.h"

int check_opcode(char *op_code)
{
	int i = 0;

	if (op_code == NULL)
			return (-1);

	while(op_code[i] != '\0' && op_code[i] != '\n')
	{
		if (!(op_code[i] >= '0' && op_code[i] <= '9'))
		{
			return (-1);
		}
		i++;
	}

	return (atoi(op_code));
}

/**
 * processInstruction - chooses which function the line needs
 * @p: line from file
 * @top: the top of the stack
 */
void processInstruction(stack_t **top, char *p)
{
	char *instruction = strtok(p, " ");
	char *opcode = strtok(NULL, " ");
	char *other = strtok(NULL, " ");
	char *clear_ins = strtok(instruction, "\n");
	int numcode = check_opcode(opcode);

	if (strcmp(clear_ins, "push") == 0 && numcode != -1 && other == NULL)
		push(top, numcode);
	else if (strcmp(clear_ins, "pall") == 0 && numcode == -1 && other == NULL)
		pall(top);
	else if (strcmp(clear_ins, "pint") == 0 && numcode == -1 && other == NULL)
		pint(top);
	else if (strcmp(clear_ins, "pop") == 0 && numcode == -1 && other == NULL)
		pop(top);
	else if (strcmp(clear_ins, "swap") == 0 && numcode == -1 && other == NULL)
		swap(top);
	else if (strcmp(clear_ins, "nop") == 0 && numcode == -1 && other == NULL)
		nop();
	else
		printf("Invalid\n");
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
		exit(8);
	}
	newStackMember->next = NULL;
	newStackMember->prev = NULL;
	return (newStackMember);
}
