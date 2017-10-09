#include<stdio.h>						/*CPP*/
#include<stdlib.h>

struct node
{
	int Info;
	struct node *link;
};

typedef struct node* NODEPTR;

NODEPTR fnGetNode(void);
void fnFreeNode(NODEPTR x);
NODEPTR fnPush(int ,NODEPTR);
NODEPTR fnPop(NODEPTR);
void fnDisplay(NODEPTR first);

int main(void)
{
	NODEPTR first = NULL;
	int iChoice,iElem;


	for(;;)
	{
		printf("\nSTACK OPERATIONS");
		printf("\n1.PUSH\n2.POP\n3.DISPLAY\n4.EXIT\n");
		printf("\nEnter your iChoice\n");
		scanf("%d",&iChoice);

		switch(iChoice)
		{
			case 1: printf("\nEnter Element to be pushed onto Stack\n");
				scanf("%d",&iElem);
				first = fnPush(iElem,first);
				break;

			case 2: first = fnPop(first);
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


NODEPTR fnPush(int iElem,NODEPTR first)  /*Insert front*/
{
        NODEPTR temp;

        temp = fnGetNode();

        temp->Info = iElem;

        temp->link = first;

        return temp;
}

NODEPTR fnPop(NODEPTR first)            /*Delete front*/
{
	NODEPTR temp;
	if(first == NULL)
	{
		printf("\nStack is empty cannot delete\n");
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
		printf("\nStack is empty\n");
		return;
	}

	printf("\nThe contents of Stack are :\n");
	curr = first;
	while(curr != NULL)
	{
		printf("\n%d",curr->Info);
		curr = curr->link;
	}
	printf("\n");
}



