#include <stdio.h>
#include <stdlib.h>

#define QUEUE_SIZE 5

void fnInsertRear(int [], int*, int);
int fnDeleteFront(int[], int*, int*);
void fnDisplay(int [], int, int);
bool fnQueueFull(int[], int);
bool fnQueueEmpty(int[], int, int);

int main()
{
    int myQueue[QUEUE_SIZE];
    int iFront = 0, iRear = -1;
    int iElem, iChoice;
    
	for(;;)
	{
		printf("\nQueue Operations\n");
		printf("=====================");
		printf("\n1.Qinsert\n2.Qdelete\n3.Qdisplay\n4.Exit\n");
		printf("Enter your choice\n");
		scanf("%d",&iChoice);
		switch(iChoice)
		{
			case 1: if(!fnQueueFull(myQueue, iRear))
			        {
			            printf("\nEnter an element : ");
			            scanf("%d", &iElem);
			            fnInsertRear(myQueue, &iRear, iElem);
			        }
			        else
			        {
			            printf("\nQueue is Full\n");
			        }

				break;
			case 2: if(!fnQueueEmpty(myQueue, iFront, iRear))
			        {
			            iElem = fnDeleteFront(myQueue, &iFront, &iRear);
			            printf("\nDeleted element is %d\n", iElem);
			        }
			        else
			        {
			            printf("\nQueue is Empty\n");
			        }

				break;
			case 3: if(!fnQueueEmpty(myQueue, iFront, iRear))
			        {
			            printf("\nContents of the Queue is \n");
			            fnDisplay(myQueue, iFront, iRear);
			        }
			        else
			        {
			            printf("\nQueue is Empty\n");
			        }

				break;
				
			case 4: exit(0);
			
			default: printf("\nInvalid choice\n");

				break;
		}
	}
    return 0;
}

bool fnQueueFull(int queue[], int r)
{
    if(r == QUEUE_SIZE-1)
        return true;
    else
        return false;
}

bool fnQueueEmpty(int queue[], int f, int r)
{
    if(r == f-1)
        return true;
    else
        return false;
}

void fnInsertRear(int queue[], int *r, int iVal)
{
    *r = *r + 1;
    queue[*r] = iVal;
}

int fnDeleteFront(int queue[], int *f, int *r)
{
    int iElem;
    iElem = queue[*f];
    
    if(*f == *r)
    {
        *f = 0;
        *r = -1;
    }
    else
    {
        *f = *f + 1;
    }
    return iElem;
}

void fnDisplay(int queue[], int f, int r)
{
    int i;
    for(i=f; i<=r; i++)
    {
        printf("%d\t", queue[i]);
    }
    printf("\n");
}


