
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
char **splitInstruction(char *p)
{
	/*char **arr;
	int i = 0;
	int j;
	int LeftPointer = 0;
	int RightPointer = 0;
	int count = 0;
	int found = 0;

	arr = malloc(sizeof(char *) * 2);

	while (p[RightPointer] != '\0')
	{
		if (p[RightPointer] == ' ')
		{
			count = RightPointer - LeftPointer;
			arr[i] = malloc(sizeof(char *) * (count + 1));
			for(j = LeftPointer; j <= RightPointer; j++)
			{
				arr[i][j - LeftPointer] = p[j];
			}
			arr[i][i] = '\0';
			i++;
			LeftPointer = RightPointer + 1;
			found = 1;
		}
		if (found == 1)
		{
			
		}
		RightPointer++;
	}

	return (arr);*/
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
//printf("Checkpoint====================\n");
	int numcode = check_opcode(opcode);
/*	printf("instruction: %s\n", instruction);
	printf("opcode: %s\n", opcode);
	printf("other: %s\n", other);
	printf("numcode: %d\n", numcode);
*/
	if (strcmp(clear_ins, "push") == 0 && numcode != -1 && other == NULL)
		/*pushPreProcessing(top, strstr(p, "push"));*/
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
