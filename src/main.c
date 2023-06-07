#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "stackADT.h"

const char closMiss[] = "Closing %c missing at line %d\n";
const char openMiss[] = "Opening %c missing at line %d\n";

int main(){
	STACK* s = createStack();
	char token;
	char fileID[25];
	FILE* fpIn;
	int lineCount = 1;
	char* popedValue;

    printf ("Enter file ID for file to be parsed: ");
    scanf ("%s", fileID);

    fpIn = fopen (fileID, "r");
    if (!fpIn) {
        printf("Error opening %s\n", fileID);
        exit(100);
    }
    while ((token = fgetc (fpIn)) != EOF ){
    	switch(token){
    	case '\n':
    		if(!emptyStack(s)){
//    			popedValue = (char*) popStack(s);
    			printf(closMiss,*(char*)stackTop(s),lineCount);
    			printf("\n\n%d",stackCount(s));
    			return 1;
    		}
    		lineCount++;
    		break;
    	case '[':
    		if(pushStack(s,&token)) break;
    		else{
    			printf("Error pushing to stack");
    			return 1;
    		}
    	case '{':
    		if(pushStack(s,&token)) break;
    		else{
    			printf("Error pushing to stack");
    			return 1;
    		}
    	case '(':
    		if(pushStack(s,&token)) break;
    		else{
    			printf("Error pushing to stack");
    			return 1;
    		}
    	case '}':
    		if(!emptyStack(s)){
    			popedValue = (char *) popStack(s);
        		if(*popedValue != '{') printf(openMiss,'{',lineCount);
    		} else printf(openMiss,'{',lineCount);
    		return 1;
    	case ']':
    		if(!emptyStack(s)){
    			popedValue = (char *) popStack(s);
        		if(*popedValue != '[') printf(openMiss,'[',lineCount);
    		} else printf(openMiss,'[',lineCount);
    		return 1;
    	case ')':
    		if(!emptyStack(s)){
    			popedValue = (char *) popStack(s);
        	 	if(*popedValue != '(') printf(openMiss,'(',lineCount);
    		} else printf(openMiss,'(',lineCount);
    		return 1;
       	}

    }

    if (!emptyStack (s)) {
        char topToken = *(char*)stackTop(s);
        printf (closMiss, topToken, lineCount);
        return 1;
    } // if

    s=destroyStack(s);
	return 0;
}
