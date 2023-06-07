/*
 * createStack.c
 *
 *  Created on: 6 de jun. de 2023
 *      Author: t00l
 */


/* =============== createStack ==============
 * This algorithm creates an empty stack.
 * Pre Nothing
 * Post Returns pointer to a null stack -or- NULL if overflow */
#include <stdlib.h>

#include "../bak/stackADT.h"

STACK* createStack (void) {
	// Local Definitions
	STACK* stack;

	// Statements
	stack = (STACK*) malloc( sizeof (STACK));
	if (stack) {
		stack->count = 0;
		stack->top = NULL;
	} // if
	return stack;
} // createStack
