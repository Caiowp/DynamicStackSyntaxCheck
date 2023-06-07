/*
 * popStack.c
 *
 *  Created on: 6 de jun. de 2023
 *      Author: t00l
 */
/* =================== pop ====================
 * Delete node from linked list stack.
 * Pre pStackTop is pointer to valid stack Post
 * charOut contains deleted data
 * Return true if successful false if underflow */

/* =================== popStack ==================
 * This function pops item on the top of the stack.
 * Pre stack is pointer to a stack
 * Post
 * Returns pointer to user data if successful NULL if underflow */
#include <stdlib.h>

#include "../bak/stackADT.h"

void* popStack (STACK* stack) {
	// Local Definitions
	void* dataOutPtr;
	STACK_NODE* temp;

	// Statements
	if (stack->count == 0)
		dataOutPtr = NULL;
	else {
		temp = stack->top;
		dataOutPtr = stack->top->dataPtr;
		stack->top = stack->top->link;
		free (temp);
		(stack->count)--;
	} // else
	return dataOutPtr;
} // popStack

