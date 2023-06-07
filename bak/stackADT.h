/*
 * StackADT.h
 *
 *  Created on: 6 de jun. de 2023
 *      Author: t00l
 */
#include <stdbool.h>
#ifndef STACKADT_H_
#define STACKADT_H_


// Stack ADT Type Defintions
typedef struct node {
	void* dataPtr;
	struct node* link;
} STACK_NODE;

typedef struct {
	int count;
	STACK_NODE* top;
} STACK;

STACK* createStack (void);
void* stackTop (STACK* stack);
bool emptyStack (STACK* stack);
bool fullStack (STACK* stack);
int stackCount (STACK* stack);
STACK* destroyStack (STACK* stack);
bool pushStack (STACK* stack, void* dataInPtr);
void* popStack (STACK* stack);

#endif /* STACKADT_H_ */
