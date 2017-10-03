#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 4

bool fnStkFull(int);
bool fnStkEmpty(int);
void fnPush(int [], int*);
int fnPop(int [], int*);
void fnDisplay(int[], int);
int fnPeek(int [], int);

int main()
{
	int stkArray[MAX];
	int top = -1;
	int iElem, iChoice;

	for(;;)
	{
		printf("\nSTACK OPERATIONS\n");
		printf("====================");
		printf("\n1.PUSH\n2.POP\n3.DISPLAY\n4.PEEK\n5.EXIT\n");
		printf("Enter your choice\n");
		scanf("%d",&iChoice);
		switch(iChoice)
		{
			case 1: fnPush(stkArray, &top);
					break;
					
			case 2: iElem = fnPop(stkArray, &top);
					if(iElem != -1)
						printf("\nPopped Element is %d\n", iElem);
					break;
					
			case 3: fnDisplay(stkArray, top);
					break;
					
			case 4: if(!fnStkEmpty(top))
					{
						iElem = fnPeek(stkArray, top);
						printf("\nElement at the  top of the stack is %d\n", iElem);					
					}
					else
						printf("\nEmpty Stack\n");
					break;
					
			case 5: exit(1);
			
			default: printf("\nWrong choice\n");
		}
	}
	return 0;
}

bool fnStkFull(int t)
{
	return ((t == MAX-1) ? true : false);
}

bool fnStkEmpty(int t)
{
	return ((t == -1) ? true : false);
}

void fnPush(int stk[], int *t)
{
	int iElem;
	if(fnStkFull(*t))
	{
		printf("\nStack Overflow\n");
		return;
	}
	printf("\nEnter element to be pushed onto the stack\n");
	scanf("%d", &iElem);
	
	*t = *t + 1;
	stk[*t] = iElem;
}

int fnPop(int stk[], int *t)
{
	int iElem;
	if(fnStkEmpty(*t))
	{
		printf("\nStack Underflow\n");
		return -1;
	}
	iElem = stk[*t];
	*t = *t - 1;
	
	return iElem;
}

void fnDisplay(int stk[], int t)
{
	int i;
	if(fnStkEmpty(t))
	{
		printf("\nStack Empty\n");
		return;
	}
	printf("\nStack Contents are: \n");
	for(i = t ; i > -1; --i)
	{
		printf("\t%d\n", stk[i]);
	}
}

int fnPeek(int stk[], int t)
{
	return stk[t];
}

