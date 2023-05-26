#include "monty.h"

/**
 * instructions - ...
 * @i: ...
 * @top: ...
 * @clear_ins: ...
 * Return: 1 if used, else 0
 */

int instructions(int i, stack_t **top, char *clear_ins)
{
	if (strcmp(clear_ins, "pall") == 0)
	{
		pall(top);
		return (1);
	}
	else if (strcmp(clear_ins, "pint") == 0)
	{
		pint(top, i);
		return (1);
	}
	else if (strcmp(clear_ins, "pop") == 0)
	{
		pop(top, i);
		return (1);
	}
	else if (strcmp(clear_ins, "swap") == 0)
	{
		swap(top, i);
		return (1);
	}	else if (strcmp(clear_ins, "add") == 0)
	{
		add(top, i);
		return (1);
	}	else if (strcmp(clear_ins, "pchar") == 0)
	{
		pchar(top, i);
		return (1);
	}	else if (strcmp(clear_ins, "nop") == 0 || clear_ins[0] == '#')
	{
		nop();
		return (1);
	}
	else
	{
		return (moreInstructions(i, top, clear_ins));
	}
	return (0);
}

/**
 * moreInstructions - ...
 * @i: ...
 * @top: ...
 * @clear_ins: ...
 * Return: 1 if used, else 0
 */

int moreInstructions(int i, stack_t **top, char *clear_ins)
{
	if (strcmp(clear_ins, "sub") == 0)
	{
		sub(top, i);
		return (1);
	}
	else if (strcmp(clear_ins, "div") == 0)
	{
		div(top, i);
		return (1);
	}
	else if (strcmp(clear_ins, "mul") == 0)
	{
		mul(top, i);
		return (1);
	}
	else if (strcmp(clear_ins, "mod") == 0)
	{
		mod(top, i);
		return (1);
	}
	else if (strcmp(clear_ins, "pstr") == 0)
	{
		pstr(top);
		return (1);
	}
	else if (strcmp(clear_ins, "rotl") == 0)
	{
		rotl(top);
		return (1);
	}
	return (0);
}
