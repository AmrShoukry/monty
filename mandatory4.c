#include "monty.h"

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
