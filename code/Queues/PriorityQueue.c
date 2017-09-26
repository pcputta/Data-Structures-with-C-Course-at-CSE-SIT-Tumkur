#include <stdio.h>
#include <stdlib.h>

#define QUEUE_SIZE 5

typedef struct 
{
    int Queue[3][QUEUE_SIZE];
    int iFront[3], iRear[3];
}QUEUE_T;

void fnPqInsert(QUEUE_T* ,int, int);
int fnPqDelete(QUEUE_T*);
void fnDisplay(QUEUE_T);

int main()
{
    QUEUE_T myQueue;
    int iChoice, iElem, iPrio, i;

    for(i=0;i<3;i++)
    {
        myQueue.iFront[i]=0;  
        myQueue.iRear[i]=-1;  
    }    
    while(1)
    {
        printf("\nPRIORITY QUEUE\n");
        printf("==================");
        printf("\n1.PQinsert\n2.PQdelete\n3.PQdisplay\n4.Exit\n");
        printf("\nEnter your choice\n");
        scanf("%d",&iChoice);

        switch(iChoice)
        {
	        case 1: printf("\nEnter the priority number between 1 & 3:\n");
		            scanf("%d",&iPrio);
		            if((iPrio > 0) && (iPrio < 4))
		            {
		                printf("\nEnter the element to be inserted");
		                scanf("%d", &iElem);
	                    fnPqInsert(&myQueue, iPrio-1, iElem);
		            }
		            else
			            printf("\nWrong Priority\n");
		            break;

	        case 2: iElem = fnPqDelete(&myQueue);
	                printf("\nElement deleted is %d\n", iElem);
    		        break;

	        case 3: fnDisplay(myQueue);
    		        break;

	        case 4: exit(0);
        }
    }
    return 0;
}

void fnPqInsert(QUEUE_T *myQ, int iPrior, int iItem)
{
    if(myQ->iRear[iPrior] == QUEUE_SIZE -1)
    {
        printf("\nQueue is full\n");
        return;
    }    
    (myQ->iRear[iPrior])++;
    myQ->Queue[iPrior][myQ->iRear[iPrior]] = iItem;
}

int fnPqDelete(QUEUE_T *myQ)
{
    int i, iElem;
    for(i=0;i<3;i++)
    {
        if(myQ->iFront[i] == myQ->iRear[i]+1)
        {
            printf("\nQueue %d is empty\n", i+1);
        }
        else
        {
            iElem = myQ->Queue[i][myQ->iFront[i]];
            (myQ->iFront[i])++;
            return iElem;
        }
    }
}

void fnDisplay(QUEUE_T myQ)
{
    int i,j;
    for(i=0;i<3;i++)
    {
        if(myQ.iFront[i] == myQ.iRear[i]+1)
        {
            printf("\nQueue %d is empty\n", i+1);
        }
        else
        {
            printf("\nQueue %d\n", i+1);
            for(j=myQ.iFront[i];j<=myQ.iRear[i];j++)
            {
                printf("%d\t", myQ.Queue[i][j]);
            }
            printf("\n");
        }
    }
}

