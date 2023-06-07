/*
 * destroyStack.c
 *
 *  Created on: 6 de jun. de 2023
 *      Author: t00l
 */

/* ================== destroyStack =================
 *  This function releases all nodes to the heap.
 *  Pre A stack
 *  Post returns null pointer */
#include <stdlib.h>

#include "../bak/stackADT.h"

STACK* destroyStack (STACK* stack) {
	// Local Definitions
	STACK_NODE* temp;
	// Statements
	if (stack) {
		// Delete all nodes in stack
		while (stack->top != NULL) {
			// Delete data entry free
			(stack->top->dataPtr);
			temp = stack->top;
			stack->top = stack->top->link;
			free (temp);
		} // while

		// Stack now empty. Destroy stack head node.
		free (stack);
	} // if stack

	return NULL;

} // destroyStack
