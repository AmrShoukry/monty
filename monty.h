#ifndef MONTY_MONTY_H
#define MONTY_MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

void push(stack_t **top, int n);
void pall(stack_t **top);
void pint(stack_t **top, int i);
stack_t *pop(stack_t **top, int i);
stack_t *swap(stack_t **top, int i);
void add(stack_t **top, int i);
void nop(void);

char *trim_text(char *text);
int check_argument(int *numcode, char *argument);
void processInstruction(int i, stack_t **top, char *p);
stack_t *allocateStack();
void freeStack(stack_t **stack);
void freeCharPointer(char **freeMe);

/* BONUS */
void sub(stack_t **top, int i);
void pchar(stack_t **top, int i);
void divide(stack_t **top, int i);
void pstr(stack_t **top);
void mul(stack_t **top, int i);
void mod(stack_t **top, int i);
void rotl(stack_t **top);
void rotr(stack_t **top);

#endif
