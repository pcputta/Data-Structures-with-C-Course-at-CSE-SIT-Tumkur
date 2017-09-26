#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


#define STK_SIZE 10

void fnPush1(int [], int*, int);
void fnPush2(int [], int*, int);
int fnPop1(int [], int*);
int fnPop2(int [], int*);
void fnDisplay(int [], int, int);
void fnPeek(int [], int, int);

bool fnStkFull(int [], int, int);
bool fnStkEmpty1(int [], int);
bool fnStkEmpty2(int [], int);


int main()
{
	int myStack[STK_SIZE];
	int top1 = -1, top2 = STK_SIZE, iElem, iChoice;
	
	for(;;)
	{
		/*Code to display Menu and accept response */
		printf("\n1.PUSH\n2.POP\n3.DISPLAY\n4.PEEK\n5.EXIT\n");
		printf("\nEnter your Choice : ");
		scanf("%d", &iChoice);
		switch(iChoice)
		{
			case 1: if(!fnStkFull(myStack, top1, top2))
					{
						printf("\nEnter element to be pushed\n");
						scanf("%d", &iElem);
						
						printf("\nEnter which stack you want to push (1 or 2): ");
						scanf("%d", &iChoice);
						
						if(iChoice == 1)
							fnPush1(myStack, &top1, iElem);
						else
							fnPush2(myStack, &top2, iElem);
					}
					else
					{
						printf("\nStack Overflow\n");
					}
					break;
					
			case 2: 
					printf("\nEnter which stack you want to pop (1 or 2): ");
					scanf("%d", &iChoice);
					
					if(iChoice == 1)
					{
						if(!fnStkEmpty1(myStack, top1))
						{
							iElem = fnPop1(myStack, &top1);
							printf("\nPopped element is %d\n", iElem);
						}
						else
						{
							printf("\nStack1 Underflow\n");
						}					
					}
					else
					{
						if(!fnStkEmpty2(myStack, top2))
						{
							iElem = fnPop2(myStack, &top2);
							printf("\nPopped element is %d\n", iElem);
						}
						else
						{
							printf("\nStack2 Underflow\n");
						}					
					
					}
					break;
					
			case 3: fnDisplay(myStack, top1, top2);
					break;

			case 4: 
					fnPeek(myStack, top1, top2);
					break;

			case 5: exit(0);

		}
	}
	return 0;
}

bool fnStkFull(int Stack[], int t1, int t2)
{
	if(t1 == t2-1)
		return true;
	else
		return false;
}

bool fnStkEmpty1(int Stack[], int t)
{
	if(t == -1)
		return true;
	else
		return false;
}

bool fnStkEmpty2(int Stack[], int t)
{
	if(t == STK_SIZE)
		return true;
	else
		return false;
}


//fnPush(myStack, &top, iElem);
void fnPush1(int Stack[], int *t , int elem)
{
	*t = *t + 1;
	Stack[*t] = elem;	
}

void fnPush2(int Stack[], int *t , int elem)
{
	*t = *t - 1;
	Stack[*t] = elem;	
}


int fnPop1(int Stack[], int *t)
{
	int elem;
	elem = Stack[*t];
	*t = *t - 1;
	return elem;
}


int fnPop2(int Stack[], int *t)
{
	int elem;
	elem = Stack[*t];
	*t = *t + 1;
	return elem;
}

void fnDisplay(int Stack[], int t1, int t2)
{
	int i;
	if(!fnStkEmpty1(Stack, t1))
	{
		printf("\nContents of the stack 1 :\n");
		for(i = t1; i>=0; i--)
		{
			printf("%d\n", Stack[i]);
		}	
	}
	else
		printf("\nStack1 is Empty\n");

	printf("\n");

	if(!fnStkEmpty2(Stack, t2))
	{
		printf("\nContents of the stack 1 :\n");
		for(i = t2; i<STK_SIZE; i++)
		{
			printf("%d\n", Stack[i]);
		}	
	}
	else
		printf("\nStack2 is Empty\n");

}

void fnPeek(int Stack[], int t1, int t2)
{
	if(!fnStkEmpty1(Stack, t1))
	{
		printf("\nTop most element of Stack1 is : %d\n", Stack[t1]);
	}
	else
		printf("\nStack1 is Empty\n");

	printf("\n");

	if(!fnStkEmpty2(Stack, t2))
	{
		printf("\nTop most element of Stack2 is : %d\n", Stack[t2]);
	}
	else
		printf("\nStack2 is Empty\n");

}



