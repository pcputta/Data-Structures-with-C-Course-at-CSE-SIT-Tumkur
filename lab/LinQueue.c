/***************************************************************************
*File		: LinearQueue
*Description	: Program to implement a Linear Queue of intrgers
*Author		: Prabodh C P
*Compiler	: gcc compiler4.4.3, Ubuntu 10.04
*Date		: 11 July 2012
***************************************************************************/
#include<stdio.h>									/*CPP*/
#include<stdlib.h>
#include "queue.h"
#include "QFunc.c"

/***************************************************************************
*Function	: 	main
*Input parameters:	no parameters
*RETURNS	:	0 on success
***************************************************************************/
int main(void)
{
    QUEUE stQueue;
	int iChoice;
	stQueue.iFront = 0;
	stQueue.iRear = -1;
	for(;;)
	{
                printf("\nQueue Operations\n");
                printf("=====================");

		printf("\n1.Qinsert\n2.Qdelete\n3.Qdisplay\n4.Exit\n");
		printf("Enter your choice\n");
		scanf("%d",&iChoice);
		switch(iChoice)
		{
			case 1: stQueue = fnQInsert(stQueue);

				break;
			case 2: stQueue = fnQDelete(stQueue);

				break;
			case 3: fnQDisplay(stQueue);

				break;
			case 4: exit(0);
			default: printf("\nWrong Choice\n");
				break;
		}
	}
	return 0;
}



/*CPP*/
