#include <string.h>
#include "utilities.h"

/**
 * processInstruction - chooses which function the line needs
 * @param p
 */
void processInstruction(stack_t **top, char *p)
{
	int *arr = substringExists(p);
	int choice = arr[0];
	if (choice == 0)
		push(top, arr[1]);
	else if (choice == 1)
		pint(top);/*TODO pint is not implemented*/
}

int matchP(char *str, int idx)
{

}

/**
 * substringExists - searches the string for a command
 * @param subStr
 * Return: the code for the command in the first array location-
 * - and the number in the command in the second array location
 */
int *substringExists(char *subStr) {
	int arr[2];
	int i = 0;
	char *substrBeginning;
	char *number;

	int choice = -1;
	arr[0] = 0;
	arr[1] = 1;

	if ((substrBeginning = strstr(subStr, "push")) != NULL)
	{
		strcpy(number, substrBeginning + 1);
	}

	return (0);
}



stack_t *allocateStack()
{
	stack_t *newStackMember = malloc(sizeof(stack_t));
	if (newStackMember == NULL)
	{
		fprintf( stderr, "Error: malloc failed\n");
		exit(8);
	}
	newStackMember->next = NULL;
	newStackMember->prev = NULL;
	return (newStackMember);
}

void freeCharPointer(char **freeMe)
{
	if (*freeMe != NULL)
		free(*freeMe);
	*freeMe = NULL;
}

/**
 * freeStack - recursively frees all members of the stack
 * should be called when program returns.
 * program relies on stack having next and previous being correctly NULL or not
 * @param stack
 */
void freeStack(stack_t **stack)
{
	if (stack == NULL)
		return;

	if ((*stack)->next != NULL)
		freeStack(&((*stack)->next));
	if ((*stack)->prev != NULL)
		freeStack(&((*stack)->prev));

	free(stack);
	stack = NULL;
}
