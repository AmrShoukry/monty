
#include "monty.h"


/**
 * processInstruction - chooses which function the line needs
 * @p: line from file
 * @top: the top of the stack
 */
void processInstruction(stack_t **top, char *p)
{

	if (strstr(p, "push") != NULL)
		pushPreProcessing(top, strstr(p, "push"));
	else if (strstr(p, "pall") != NULL)
		pall(top);
	else if (strstr(p, "pint") != NULL)
		pint(top);
	else if (strstr(p, "pop") != NULL)
		pop(top);
	else if (strstr(p, "swap") != NULL)
		swap(top);
//	else if (strstr(p, "nop") != NULL)
//		nop();
}

/**
 * pushPreProcessing - pre processes input for the push function
 * @top: the stack
 * @substrBeginning: the beginning of the word "push"
 */
void pushPreProcessing(stack_t **top, char *substrBeginning)
{
	int numOfDigits = 0;
	char *number;

	numOfDigits = numberOfDigits(substrBeginning + 5);
	number = malloc(sizeof(char) * numOfDigits + 1);
	strncpy(number, substrBeginning + 5, numOfDigits);
	number[numOfDigits] = '\0';
	push(top, atoi(number));
	free(number);
}

/**
 * numberOfDigits - gets the number of digits
 * @number: ...
 * Return: int
 */
int numberOfDigits(char *number)
{
	int i = 0;

	while (isdigit(number[i]))
		i++;
	return (i);
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
