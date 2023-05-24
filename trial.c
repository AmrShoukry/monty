#include <stdio.h>
#include <stdlib.h>
#include "utilities.h"
#include "mandatory.h"
#include "datastructures.h"

void implement(stack_t **top);

int main(void)
{
	stack_t *stack;
	implement(&stack);

	return (0);
}

void implement(stack_t **top)
{
	push(top, 5);
	push(top, 8);
	swap(top);
	pop(top);
	pint(top);	
}
