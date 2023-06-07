/*
 * stackTop.c
 *
 *  Created on: 6 de jun. de 2023
 *      Author: t00l
 */


/* ================== stackTop =================
 * Retrieves data from the top of stack without changing the stack.
 * Pre stack is a pointer to the stack
 * Post Returns data pointer if successful null pointer if stack empty */
#include <stdlib.h>

#include "../bak/stackADT.h"

void* stackTop (STACK* stack) {
	// Statements
	if (stack->count == 0)
		return NULL;
	else
		return stack->top->dataPtr;
} // stackTop
