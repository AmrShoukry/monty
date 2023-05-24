#ifndef TESTFILE_FUNCTIONS_H
#define TESTFILE_FUNCTIONS_H

#include <stdio.h>
#include <stdlib.h>

#include "datastructures.h"


void push(stack_t **top, int n);/*function to push a number onto the stack*/
void pall(stack_t **top);/*function to print the entire stack*/
void pint(stack_t **top);/*prints the value of top followed by a newline or sends an error message if NULL*/
stack_t *pop(stack_t **top);/*pops the stack, returns new top of stack, or sends an error message*/
stack_t *swap(stack_t **top);/*swaps top with its previous, or sends an error message if stacksize is smaller than 2*/
void nop();/*DOES LITERALLY NOTHING*/

#endif /*TESTFILE_FUNCTIONS_H*/
