/* This program reads a source program and parses it to make sure all opening-closing parentheses, brackets, and braces are paired. Written by: Date: */

#include <stdio.h>
#include <stdlib.h>

#include "../bak/stackADT.h"

// Error Messages
const char closMiss[] = "Closing %c missing at line %d\n";
const char openMiss[] = "Opening %c missing at line %d\n";

int main (void) {
    // Local Definitions
    STACK* stack;
    char token;
    char* dataPtr;
    char fileID[25];
    FILE* fpIn;
    int lineCount = 1;

    // Statements
    // Create Stack
    stack = createStack ();

    printf ("Enter file ID for file to be parsed: ");
    scanf ("%s", fileID);

    fpIn = fopen (fileID, "r");
    if (!fpIn) {
        printf("Error opening %s\n", fileID);
        exit(100);
    }

    // read characters from the source code and parse
    while ((token = fgetc (fpIn)) != EOF ) {
        if (token == '\n') {
            lineCount++;
        }

        if (token == '(' || token == '[' || token == '{') {
            dataPtr = (char*) malloc (sizeof (char));
            pushStack (stack, dataPtr);
        } else if (token == ')' || token == ']' || token == '}') {
            if (emptyStack (stack)) {
                printf (openMiss, token, lineCount);
                return 1;
            } else {
                char topToken = *(char*)stackTop(stack);
                popStack (stack);

                if ((token == ')' && topToken != '(') ||
                    (token == ']' && topToken != '[') ||
                    (token == '}' && topToken != '{')) {
                    printf (closMiss, topToken, lineCount);
                    return 1;
                }
            }
        }
    } // while

    if (!emptyStack (stack)) {
        char topToken = *(char*)stackTop(stack);
        printf (closMiss, topToken, lineCount);
        return 1;
    } // if

    // Now destroy the stack
    destroyStack (stack);
}
