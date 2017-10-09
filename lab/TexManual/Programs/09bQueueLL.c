#include<stdio.h>									
#include<stdlib.h>

struct node
{
	int Info;
	struct node *link;
};

typedef struct node* NODEPTR;

NODEPTR fnGetNode(void);
void fnFreeNode(NODEPTR);
NODEPTR fnIns_Rear(int, NODEPTR);
NODEPTR fnDelFront(NODEPTR);
void fnDisplay(NODEPTR);

int main()
{
	NODEPTR first = NULL;
	int iChoice,iElem;

	for(;;)
	{
		printf("\nQUEUE OPERATIONS\n");
		printf("====================");
		printf("\n1.Insert Rear\n2.Delete Front\n3.Display\n4.Exit\n");
		printf("\nEnter your choice\n");
		scanf("%d",&iChoice);

		switch(iChoice)
		{
			case 1: printf("\nEnter Element to be inserted\n");
				scanf("%d",&iElem);
				first = fnIns_Rear(iElem,first);
				break;

			case 2: first = fnDelFront(first);
				break;

			case 3: fnDisplay(first);
				break;

			case 4: exit(0);
		}
	}
    return 0;
}

NODEPTR fnGetNode()
{
	NODEPTR newborn;
	newborn = (NODEPTR)malloc(sizeof(struct node));

	if(newborn == NULL)
	{
		printf("\nMemory Overflow");
		exit(0);
	}
	return newborn;
}


void fnFreeNode(NODEPTR x)
{
	free(x);
}


NODEPTR fnIns_Rear(int iElem,NODEPTR first)
{
	NODEPTR temp,cur;

	temp = fnGetNode();
	temp->Info = iElem;
	temp->link = NULL;

    if(first == NULL)
        return temp;
    cur = first;
    while(cur->link != NULL)
    {
        cur = cur->link;
    }
    cur->link = temp;
    return first;
}

NODEPTR fnDelFront(NODEPTR first)
{
	NODEPTR temp;
	if(first == NULL)
	{
		printf("\nQueue is empty cannot delete\n");
		return first;
	}
	temp = first;
	first = first->link;
	printf("\nElement deleted is %d \n",temp->Info);
	fnFreeNode(temp);
	return first;
}

void fnDisplay(NODEPTR first)
{
	NODEPTR curr;
	if(first == NULL)
	{
		printf("\nQueue is empty\n");
		return;
	}

	printf("\nThe contents of Queue are :\n");
	curr = first;
	while(curr != NULL)
	{
		printf("\n%d",curr->Info);
		curr = curr->link;
	}
	printf("\n");
}

/*CPP*/
