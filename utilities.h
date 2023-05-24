#ifndef MONTY_UTILITIES_H
#define MONTY_UTILITIES_H
#include "mandatory.h"

void processInstruction(stack_t **top, char *p);/*takes line and chooses what to do with it, processes input*/

stack_t *allocateStack();

void freeStack(stack_t **stack);

void freeCharPointer(char **freeMe);

int numberOfDigits(char *number);

void pushPreProcessing(stack_t **top, char *substrBeginning);
#endif
