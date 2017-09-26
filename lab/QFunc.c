/*Licensed under GNU GPL*/
/***************************************************************************
*Function	: 	fnQInsert
*Description:   inserts an element at the rear of the queue
*Input parameters: a structure queue
*RETURNS	:	updated queue
***************************************************************************/

QUEUE fnQInsert(QUEUE stQueue)
{
	int iItem;
	if(fnQFull(stQueue))
	printf("\nQueue Overflow\n");
	else
	{
		printf("\nEnter the  element\n");
		scanf("%d",&iItem);
		stQueue.iRear++;
		stQueue.iaItems[stQueue.iRear] = iItem;

	}
	return stQueue;
}

/***************************************************************************
*Function	: 	fnQDelete
*Description:   deletes an element from the front of the queue
*Input parameters: a structure queue
*RETURNS	:	updated queue
***************************************************************************/

QUEUE fnQDelete(QUEUE stQueue)
{
	if(fnQEmpty(stQueue))
	printf("\nQueue Underflow\n");
	else
	if(stQueue.iRear == stQueue.iFront)
	{
		printf("\nItem deleted is %d\n",stQueue.iaItems[stQueue.iFront]);
		stQueue.iRear=-1;
		stQueue.iFront=0;
	}
	else
	{
		printf("\nItem deleted is %d\n",stQueue.iaItems[stQueue.iFront++]);
	}
	return stQueue;
}

/***************************************************************************
*Function	: 	fnQDisplay
*Description:   displays elements of the queue
*Input parameters: a structure queue
*RETURNS	:	nothing
***************************************************************************/
void fnQDisplay(QUEUE stQueue)
{
	int i;
	if(fnQEmpty(stQueue))
	printf("\nQueue Empty\n");
	else
	{
		printf("\nContents of Queue are:\n");
		for(i=stQueue.iFront;i<=stQueue.iRear;i++)
		printf("%d\t",stQueue.iaItems[i]);
	}
}
/***************************************************************************
*Function	: 	fnQFull
*Description:   checks wheteher the queue is full or not
*Input parameters: a structure queue
*RETURNS	:	1 if the queue is full or 0 otherwise
***************************************************************************/
int fnQFull(QUEUE stQueue)
{
	if(stQueue.iRear == SIZE-1)
		return 1;
	else
		return 0;
}

/***************************************************************************
*Function	: 	fnQEmpty
*Description:   checks wheteher the queue is empty or not
*Input parameters: a structure queue
*RETURNS	:	1 if the queue is empty or 0 otherwise
***************************************************************************/
int fnQEmpty(QUEUE stQueue)
{
	if(stQueue.iRear == stQueue.iFront-1)
		return 1;
	else
		return 0;
}
