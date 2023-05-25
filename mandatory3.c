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
 * div - ...
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

