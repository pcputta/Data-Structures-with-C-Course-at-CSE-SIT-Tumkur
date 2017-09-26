#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


#define STK_SIZE 5

void fnPush(int [], int*, int);
int fnPop(int [], int*);
void fnDisplay(int [], int);
int fnPeek(int [], int);

bool fnStkFull(int [], int);
bool fnStkEmpty(int [], int);


int main()
{
	int myStack[STK_SIZE];
	int top = -1, iElem, iChoice;
	
	for(;;)
	{
		/*Code to display Menu and accept response */
		printf("\n1.PUSH\n2.POP\n3.DISPLAY\n4.PEEK\n5.EXIT\n");
		printf("\nEnter your Choice : ");
		scanf("%d", &iChoice);
		switch(iChoice)
		{
			case 1: if(!fnStkFull(myStack, top))
					{
						printf("\nEnter element to be pushed\n");
						scanf("%d", &iElem);
						
						fnPush(myStack, &top, iElem);
						
					}
					else
					{
						printf("\nStack Overflow\n");
					}
					break;
					
			case 2: if(!fnStkEmpty(myStack, top))
					{
						iElem = fnPop(myStack, &top);
						printf("\nPopped element is %d\n", iElem);
					}
					else
					{
						printf("\nStack Underflow\n");
					}
					break;
					
			case 3: if(!fnStkEmpty(myStack, top))
					{
						fnDisplay(myStack, top);
					}
					else
					{
						printf("\nStack is Empty\n");
					}
					break;
			case 4: if(!fnStkEmpty(myStack, top))
					{
						iElem = fnPeek(myStack, top);
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

bool fnStkFull(int Stack[], int t)
{
	if(t == STK_SIZE-1)
		return true;
	else
		return false;
}

bool fnStkEmpty(int Stack[], int t)
{
	if(t == -1)
		return true;
	else
		return false;
}


//fnPush(myStack, &top, iElem);
void fnPush(int Stack[], int *t , int elem)
{
	*t = *t + 1;
	Stack[*t] = elem;
	
}

int fnPop(int Stack[], int *t)
{
	int elem;
	elem = Stack[*t];
	*t = *t -1;
	return elem;
}


void fnDisplay(int Stack[], int t)
{
	int i;
	printf("\nContents of the stack :\n");
	for(i = t; i>=0; i--)
	{
		printf("%d\n", Stack[i]);
	}
	printf("\n");
}

int fnPeek(int Stack[], int t)
{
	return Stack[t];
}



