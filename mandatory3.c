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
		fprintf(stderr, "L%i: can't sub, stack too short\n", i);
		exit(EXIT_FAILURE);
	}

	(*top)->prev->n = (*top)->prev->n - (*top)->n;

	pop(top, i);
}

/**
 * divide - ...
 * @top: ...
 * @i: ...
 */

void divide(stack_t **top, int i)
{
	if (top == NULL || *top == NULL || (*top)->prev == NULL)
	{
		fprintf(stderr, "L%i: can't div, stack too short\n", i);
		exit(EXIT_FAILURE);
	}

	if ((*top)->n == 0)
	{
		fprintf(stderr, "L%i: division by zero\n", i);
		exit(EXIT_FAILURE);
	}

	(*top)->prev->n = (*top)->prev->n / (*top)->n;

	pop(top, i);
}

/**
 * mul - ...
 * @top: ...
 * @i: ...
 */

void mul(stack_t **top, int i)
{
	if (top == NULL || *top == NULL || (*top)->prev == NULL)
	{
		fprintf(stderr, "L%i: can't mul, stack too short\n", i);
		exit(EXIT_FAILURE);
	}

	(*top)->prev->n = (*top)->prev->n * (*top)->n;

	pop(top, i);
}


/**
 * mod - ...
 * @top: ...
 * @i: ...
 */

void mod(stack_t **top, int i)
{
	if (top == NULL || *top == NULL || (*top)->prev == NULL)
	{
		fprintf(stderr, "L%i: can't mod, stack too short\n", i);
		exit(EXIT_FAILURE);
	}

	if ((*top)->n == 0)
	{
		fprintf(stderr, "L%i: division by zero\n", i);
		exit(EXIT_FAILURE);
	}

	(*top)->prev->n = (*top)->prev->n % (*top)->n;

	pop(top, i);
}



/**
 * rotr - rotate stack to the right
 *
 * Description: 'Function'
 *
 * @top: top node of the stack
 *
 * Return: void.
 */


void rotr(stack_t **top)
{
	stack_t *current = *top;
	stack_t *temp = *top;

	if (current == NULL || current->prev == NULL)
		return;

	if (current->prev->prev == NULL)
	{
		swap(top, 0);
		return;
	}

	while (current->prev != NULL)
	{
		current = current->prev;
	}

	temp = current->next;
	temp->prev = NULL;
	current->prev = (*top);
	current->next = NULL;
	(*top)->next = current;

	(*top) = current;
}
