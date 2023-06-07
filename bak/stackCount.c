/*
 * stackCount.c
 *
 *  Created on: 6 de jun. de 2023
 *      Author: t00l
 */


/* ================== stackCount =================
 * Returns number of elements in stack.
 * Pre stack is a pointer to the stack
 * Post count returned */
#include "../bak/stackADT.h"

int stackCount (STACK* stack) {
	// Statements
	return stack->count;
} // stackCount
