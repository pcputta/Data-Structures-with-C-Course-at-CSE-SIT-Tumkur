#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


#define STK_SIZE 5

typedef struct{
	int stkArray[STK_SIZE];
	int top;
}STACK_TYPE;

bool fnStkFull(STACK_TYPE);
bool fnStkEmpty(STACK_TYPE);
void fnPush(STACK_TYPE*, int);
int fnPop(STACK_TYPE*);
void fnDisplay(STACK_TYPE);
int fnPeek(STACK_TYPE);

int main()
{
	STACK_TYPE myStack;
	myStack.top = -1;
	int iElem, iChoice;
	
	for(;;)
	{
		/*Code to display Menu and accept response */
		printf("\n1.PUSH\n2.POP\n3.DISPLAY\n4.PEEK\n5.EXIT\n");
		printf("\nEnter your Choice : ");
		scanf("%d", &iChoice);
		switch(iChoice)
		{
			case 1: if(!fnStkFull(myStack))
					{
						printf("\nEnter element to be pushed\n");
						scanf("%d", &iElem);
						
						fnPush(&myStack, iElem);
					}
					else
					{
						printf("\nStack Overflow\n");
					}
					break;
					
			case 2: if(!fnStkEmpty(myStack))
					{
						iElem = fnPop(&myStack);
						printf("\nPopped element is %d\n", iElem);
					}
					else
					{
						printf("\nStack Underflow\n");
					}
					break;
					
			case 3: if(!fnStkEmpty(myStack))
					{
						fnDisplay(myStack);
					}
					else
					{
						printf("\nStack is Empty\n");
					}
					break;
			case 4: if(!fnStkEmpty(myStack))
					{
						iElem = fnPeek(myStack);
						printf("\nElement at the top of the stack is %d\n", iElem);
					}
					else
					{
						printf("\nStack is Empty\n");
					}
					break;

			case 5: exit(0);

		}
	}
	return 0;
}

bool fnStkFull(STACK_TYPE stk)
{
	if(stk.top == STK_SIZE-1)
		return true;
	else
		return false;
}

bool fnStkEmpty(STACK_TYPE stk)
{
	if(stk.top == -1)
		return true;
	else
		return false;
}


//fnPush(myStack, &top, iElem);
void fnPush(STACK_TYPE *stk, int elem)
{
//	*t = *t + 1;
	stk->top = stk->top + 1;
//	Stack[*t] = elem;
	stk->stkArray[stk->top] = elem;
	
}


int fnPop(STACK_TYPE *stk)
{
	int elem;
	elem = stk->stkArray[stk->top]
	stk->top = stk->top - 1;
	return elem;
}


void fnDisplay(STACK_TYPE stk)
{
	int i;
	printf("\nContents of the stack :\n");
	for(i = stk.top; i>=0; i--)
	{
		printf("%d\n", stk.stkArray[i]);
	}
	printf("\n");
}

int fnPeek(STACK_TYPE stk)
{
	return stk.stkArray[stk.top];
}



