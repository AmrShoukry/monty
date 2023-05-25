#include "monty.h"

/**
 * nop - nothing
 *
 * Description: 'Function'
 *
 * Return: void.
 */


void nop(void)
{
}


/**
 * add - remove top node and add its value to the new top one
 *
 * Description: 'Function'
 *
 * @top: top node of the stack
 * @i: line number
 *
 * Return: void.
 */

void add(stack_t **top, int i)
{
	stack_t *temp = *top;

	if (top == NULL || *top == NULL || (*top)->prev == NULL)
	{
		fprintf(stderr, "L%i: can't add, stack too short\n", i);
		exit(EXIT_FAILURE);
	}

	(*top)->prev->n = (*top)->prev->n + (*top)->n;
	(*top) = (*top)->prev;

	free(temp);
}


