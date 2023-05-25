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
	if (top == NULL || *top == NULL || (*top)->prev == NULL)
	{
		fprintf(stderr, "L%i: can't add, stack too short\n", i);
		exit(EXIT_FAILURE);
	}

	(*top)->prev->n = (*top)->prev->n + (*top)->n;

	pop(top, i);
}


/**
 * pchar - print top value as a character
 *
 * Description: 'Function'
 *
 * @top: top node of the stack
 * @i: line number
 *
 * Return: void.
 */

void pchar(stack_t **top, int i)
{
	int value;

	if (top == NULL || *top == NULL)
	{
		fprintf(stderr, "L%i: can't pchar, stack empty\n", i);
		exit(EXIT_FAILURE);
	}
	value = (*top)->n;
	if (!((value >= 65 && value <= 90) || (value >= 97 && value <= 122)))
	{
		fprintf(stderr, "L%i: can't pchar, value out of range\n", i);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", value);
}





/**
 * pstr - print top values as a string
 *
 * Description: 'Function'
 *
 * @top: top node of the stack
 *
 * Return: void.
 */

void pstr(stack_t **top)
{
	stack_t *current = *top;
	int value;
	int stop = 0;

	while (current != NULL && stop == 0)
	{
		value = current->n;
		if (!((value >= 65 && value <= 90) || (value >= 97 && value <= 122)))
			stop = 1;
		else
			printf("%c", current->n);
		current = current->prev;
	}
	printf("\n");
}




/**
 * rotl - rotate stack to the left
 *
 * Description: 'Function'
 *
 * @top: top node of the stack
 *
 * Return: void.
 */

void rotl(stack_t **top)
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
	temp = (*top)->prev;
	current->prev = *top;
	(*top)->next = current;
	(*top)->prev = NULL;
	temp->next = NULL;

	*top = temp;
}
