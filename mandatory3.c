#include "monty.h"

/**
 * sub - subtracts top 2
 * @top: ...
 * @i: ...
 */

void sub(stack_t **top, int i)
{
	if (top == NULL || *top == NULL || (*top)->prev == NULL)
	{
		fprintf(stderr, "L%i: can't add, stack too short\n", i);
		exit(EXIT_FAILURE);
	}

	(*top)->prev->n = (*top)->prev->n - (*top)->n;

	pop(top, i);
}

