/*
 * pushStack.c
 *
 *  Created on: 6 de jun. de 2023
 *      Author: t00l
 */


/* =================== push ====================
 * Inserts node into linked list stack.
 * Pre ƒƒƒpStackTop is pointer to valid stack
 * Post ƒƒƒ charIn inserted
 * Return true if successful false if underflow */
#include <stdbool.h>
#include <stdlib.h>

#include "../bak/stackADT.h"

bool pushStack (STACK* stack, void* dataInPtr) {
	// Local Definitions
	STACK_NODE* newPtr;
	// Statements
	newPtr = (STACK_NODE* ) malloc(sizeof( STACK_NODE));
	if (!newPtr) return false;
	newPtr->dataPtr = dataInPtr;
	newPtr->link = stack->top;
	stack->top = newPtr;

	(stack->count)++;

	return true;
} // pushStack

