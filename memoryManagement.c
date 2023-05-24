#include "utilities.h"

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
	if (stack == NULL)
		return;

	if ((*stack)->next != NULL)
		freeStack(&((*stack)->next));
	if ((*stack)->prev != NULL)
		freeStack(&((*stack)->prev));

	free(stack);
	stack = NULL;
}
