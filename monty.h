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

void push(stack_t **top, int n);/*function to push a number onto the stack*/
void pall(stack_t **top);/*function to print the entire stack*/
void pint(stack_t **top);/*prints the value of top followed by a newline or sends an error message if NULL*/
stack_t *pop(stack_t **top);/*pops the stack, returns new top of stack, or sends an error message*/
stack_t *swap(stack_t **top);/*swaps top with its previous, or sends an error message if stacksize is smaller than 2*/
void nop();/*DOES LITERALLY NOTHING*/

void processInstruction(stack_t **top, char *p);/*takes line and chooses what to do with it, processes input*/
stack_t *allocateStack();
void freeStack(stack_t **stack);
void freeCharPointer(char **freeMe);
int numberOfDigits(char *number);
void pushPreProcessing(stack_t **top, char *substrBeginning);

#endif
