#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


#define QUEUE_SIZE 5

typedef struct
{
    int Queue[QUEUE_SIZE];
    int iFront, iRear;
}QUEUE_T;


void fnInsertRear(QUEUE_T*, int);
int fnDeleteFront(QUEUE_T*);
void fnDisplay(QUEUE_T);
bool fnQueueFull(QUEUE_T);
bool fnQueueEmpty(QUEUE_T);

int main()
{
    QUEUE_T myQueue;
    int iElem, iChoice;
    
    myQueue.iFront = 0; 
    myQueue.iRear = -1;

    
	for(;;)
	{
		printf("\nQueue Operations\n");
		printf("=====================");
		printf("\n1.Qinsert\n2.Qdelete\n3.Qdisplay\n4.Exit\n");
		printf("Enter your choice\n");
		scanf("%d",&iChoice);
		switch(iChoice)
		{
			case 1: if(!fnQueueFull(myQueue))
			        {
			            printf("\nEnter an element : ");
			            scanf("%d", &iElem);
			            fnInsertRear(&myQueue, iElem);
			        }
			        else
			        {
			            printf("\nQueue is Full\n");
			        }

				break;
			case 2: if(!fnQueueEmpty(myQueue))
			        {
			            iElem = fnDeleteFront(&myQueue);
			            printf("\nDeleted element is %d\n", iElem);
			        }
			        else
			        {
			            printf("\nQueue is Empty\n");
			        }

				break;
			case 3: if(!fnQueueEmpty(myQueue))
			        {
			            printf("\nContents of the Queue is \n");
			            fnDisplay(myQueue);
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

bool fnQueueFull(QUEUE_T myQ)
{
    if(myQ.iRear == QUEUE_SIZE-1)
        return true;
    else
        return false;
}

bool fnQueueEmpty(QUEUE_T myQ)
{
    if(myQ.iRear == myQ.iFront-1)
        return true;
    else
        return false;
}

void fnInsertRear(QUEUE_T *myQ, int iVal)
{
    (myQ->iRear)++;
    myQ->Queue[myQ->iRear] = iVal;
}

int fnDeleteFront(QUEUE_T *myQ)
{
    int iElem;
    iElem = myQ->Queue[myQ->iFront];
    
    if(myQ->iFront == myQ->iRear)
    {
        myQ->iFront = 0;
        myQ->iRear = -1;
    }
    else
    {
        myQ->iFront = myQ->iFront + 1;
    }
    return iElem;
}

void fnDisplay(QUEUE_T myQ)
{
    int i;
    for(i=myQ.iFront; i<=myQ.iRear; i++)
    {
        printf("%d\t", myQ.Queue[i]);
    }
    printf("\n");
}


