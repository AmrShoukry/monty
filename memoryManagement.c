#include "monty.h"

/**
 * freeCharPointer - frees and nulls a char pointer
 * @freeMe: ...
 */
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
 * @stack: ...
 */
void freeStack(stack_t **stack)
{
	stack_t *tempPrev = NULL;
	stack_t *tempNext = NULL;

	if (stack == NULL || *stack == NULL)
		return;

	tempNext = (*stack)->next;
	tempPrev = (*stack)->prev;

	free(*stack);
	*stack = NULL;

	if (tempNext != NULL)
	{
		tempNext->next = NULL;
		freeStack(&tempNext);
	}
	if (tempPrev != NULL)
	{
		tempPrev->next = NULL;
		freeStack(&tempPrev);
	}
<<<<<<< HEAD
	/*free(*stack);
	*stack = NULL;*/
=======
>>>>>>> 1851c18c239481be93c978e2710759d108c0dd53
}
