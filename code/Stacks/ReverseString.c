#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define STK_SIZE 50

typedef struct{
	char stkArray[STK_SIZE];
	int top;
}STACK_TYPE;

void fnPush(STACK_TYPE*, char);
char fnPop(STACK_TYPE*);

int main()
{
	char acStr[10], acRev[10], ch;
	int i;
	STACK_TYPE myStack;
	myStack.top = -1;
	
	printf("\nEnter a string\n");
	fgets(acStr, 10, stdin);
	
	myStack.stkArray[++myStack.top] = '#';
	
	for(i=0;i<strlen(acStr);i++)
	{
		ch = acStr[i];
		myStack.stkArray[++myStack.top] = ch;
	}
	
	i=0;
	while(myStack.stkArray[myStack.top] != '#')
	{
		acRev[i++] = myStack.stkArray[myStack.top--]; 
	}
	acRev[i] = '\0';
	
	printf("\nEntered String : %s ", acStr);
	printf("\nReversed String : %s ", acRev);
	
	if(strcmp(acStr, acRev))
	{
		printf("\nEntered string is not a palindrome\n");
	}
	else
	{
		printf("\nEntered string is a palindrome\n");
	}
	
	return 0;
}
