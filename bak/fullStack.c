/*
 * fullStack.c
 *
 *  Created on: 6 de jun. de 2023
 *      Author: t00l
 */
/* ================== fullStack =================
 * This function determines if a stack is full.
 * Full is defined as heap full.
 * Pre stack is pointer to a stack head node
 * Return true if heap full false if heap has room */
#include <stdbool.h>
#include <stdlib.h>

#include "../bak/stackADT.h"

bool fullStack (STACK* stack) {
	// Local Definitions
	STACK_NODE* temp;
	// Statements
	if ((temp = (STACK_NODE*)malloc (sizeof(*(stack->top))))) {
		free (temp);
		return false;
	} // if

	// malloc failed
	return true;

} // fullStack


