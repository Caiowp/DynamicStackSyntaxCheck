/*
 * emptyStack.c
 *
 *  Created on: 6 de jun. de 2023
 *      Author: t00l
 */

/* ================= emptyStack ================
 *  This function determines if a stack is empty.
 *  Pre stack is pointer to a stack
 *  Post returns 1 if empty; 0 if data in stack */
#include <stdbool.h>

#include "../bak/stackADT.h"

bool emptyStack (STACK* stack) {
	// Statements
	return (stack->count == 0);
} // emptyStack

