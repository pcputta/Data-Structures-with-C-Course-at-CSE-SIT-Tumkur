#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


#define QUEUE_SIZE 5
#define NAME_LENGTH 30

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
    
    myQueue.iFront = -1; 
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
    if((myQ.iRear+1) % QUEUE_SIZE == myQ.iFront)
        return true;
    else
        return false;
}

bool fnQueueEmpty(QUEUE_T myQ)
{
    if(myQ.iFront == -1)
        return true;
    else
        return false;
}

void fnInsertRear(QUEUE_T *myQ, int iVal)
{
    if(myQ->iRear == -1)
    {
        (myQ->iRear)++;
        (myQ->iFront)++;
    }
    else
        myQ->iRear = (myQ->iRear + 1) % QUEUE_SIZE;

    myQ->Queue[myQ->iRear] = iVal;
}

int fnDeleteFront(QUEUE_T *myQ)
{
    int iElem;
    iElem = myQ->Queue[myQ->iFront];
    
    if(myQ->iFront == myQ->iRear)
    {
        myQ->iFront = myQ->iRear = -1;
    }
    else
    {
        myQ->iFront = (myQ->iFront + 1)%QUEUE_SIZE;
    }
    return iElem;
}

void fnDisplay(QUEUE_T myQ)
{
    int i;
    if(myQ.iFront<=myQ.iRear)
    {
        for(i=myQ.iFront; i<=myQ.iRear; i++)
        {
            printf("%d\t", myQ.Queue[i]);
        }
        printf("\n");    
    }
    else
    {
        for(i=myQ.iFront; i<QUEUE_SIZE; i++)
        {
            printf("%d\t", myQ.Queue[i]);
        }
        for(i=0; i<=myQ.iRear; i++)
        {
            printf("%d\t", myQ.Queue[i]);
        }
        printf("\n");    
    
    }
}


