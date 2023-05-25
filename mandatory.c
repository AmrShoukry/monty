#include "monty.h"

/**
 * push - push into the top of the stack
 *
 * Description: 'Function'
 *
 * @top: top node of the stack
 * @n: the value to be added
 *
 * Return: void.
 */


void push(stack_t **top, int n)
{
	stack_t *newStackMember = allocateStack();

	if ((*top) == NULL)
	{
		(*top) = newStackMember;
		(*top)->n = n;
	}
	else
	{
		(*top)->next = newStackMember;
		(*top)->next->prev = (*top);

		(*top) = (*top)->next;
		(*top)->n = n;
	}
}

/**
 * pall - print all stack values
 *
 * Description: 'Function'
 *
 * @top: top node of the stack
 *
 * Return: the removed node.
 */


void pall(stack_t **top)
{
	stack_t *current = *top;

	if (top == NULL || *top == NULL)
		return;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->prev;
	}
}



/**
 * pint - print top node value
 *
 * Description: 'Function'
 *
 * @top: top node of the stack
 *
 * Return: void.
 */

void pint(stack_t **top)
{
	if (top == NULL || *top == NULL)
		return;

	printf("%d\n", (*top)->n);
}

/**
 * pop - pop the last value of the stack
 *
 * Description: 'Function'
 *
 * @top: top node of the stack
 *
 * Return: the removed node.
 */

stack_t *pop(stack_t **top)
{
	stack_t *temp = NULL;

	if (top == NULL || *top == NULL)
		return (NULL);
	temp = *top;


	(*top) = (*top)->prev;

	if ((*top) != NULL)
		(*top)->next = NULL;
	free(temp);
	return ((*top));
}


/**
 * swap - swap top two values
 *
 * Description: 'Function'
 *
 * @top: top node of the stack
 *
 * Return: new top node.
 */

stack_t *swap(stack_t **top)
{
	stack_t *temp;

	if (top == NULL || *top == NULL || (*top)->prev == NULL)
		return (NULL);

	temp = (*top)->prev;

	if (temp->prev != NULL)
	{
		temp->prev->next = *top;
		(*top)->prev = temp->prev;
	}
	else
	{
		(*top)->prev = NULL;
	}

	(*top)->next = temp;
	temp->prev = (*top);
	temp->next = NULL;

	*top = temp;
	return (temp);
}
