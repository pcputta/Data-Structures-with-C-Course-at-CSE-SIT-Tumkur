#include <stdio.h>
#include <stdlib.h>
struct node
{
	int info;
	struct node *link;
};

typedef struct node* NODEPTR;

NODEPTR fnGetNode(void);
void fnFreeNode(NODEPTR x);
NODEPTR fnInsertFront(int ,NODEPTR);
NODEPTR fnDeleteFront(NODEPTR);
NODEPTR fnDeletePosition(int, NODEPTR);
NODEPTR fnInsertPosition(int ,int ,NODEPTR);
void fnDisplay(NODEPTR first);
NODEPTR fnReverse(NODEPTR);

int main()
{
	NODEPTR first = NULL;
	int iElem, iChoice, iPos;
	for(;;)
	{
		printf("\n1.Insert Front\n2.Delete Front\n3.Insert At Position");
		printf("\n4.Display\n5.Reverse\n6.Exit\n");
		printf("Enter your choice\n");
		scanf("%d",&iChoice);
		switch(iChoice)
		{
			case 1: printf("\nEnter a element\n");
			        scanf("%d", &iElem);
			        first = fnInsertFront(iElem, first);
					break;

			case 2: first = fnDeleteFront(first);
					break;
					
			case 3: printf("\nEnter a element\n");
			        scanf("%d", &iElem);
			        printf("\nEnter the position\n");
			        scanf("%d", &iPos);
			        first = fnInsertPosition(iElem, iPos, first);
					break;
					
			case 4: fnDisplay(first);
					break;
					
			case 5: first = fnReverse(first);
					break;
			case 6: exit(0);
		}
	}
	return 0;
}

NODEPTR fnGetNode(void)
{
	NODEPTR newNode;
	newNode = ( NODEPTR ) malloc (sizeof(struct node));
	if(newNode == NULL)
	{
		printf("\nOut of Memory");
		exit(0);
	}
	return newNode;
}

void fnFreeNode(NODEPTR x)
{
	free(x);
}

NODEPTR fnInsertFront(int elem,NODEPTR first)
{
	NODEPTR temp;
	temp = fnGetNode();
	temp->info = elem;
	temp->link = first;
	first = temp;
	return first;

}

NODEPTR fnDeleteFront(NODEPTR first)
{
	NODEPTR temp;
	if(first == NULL)
	{
	    printf("\nList is Empty cannot delete\n");
	    return first;
	}

    temp = first;
    printf("\nElement deleted is %d\n", temp->info);
    fnFreeNode(temp);
	first = first->link;
	return first;
}

NODEPTR fnInsertPosition(int elem,int pos,NODEPTR first)
{
	NODEPTR temp,prev,cur;
	int count;

	temp = fnGetNode();
	temp->info = elem;
	temp->link = NULL;

	if(first == NULL && pos == 1)
    	return temp;

	if(first == NULL)
	{
		printf("\nInvalid Position");
		return first;
	}

	if(pos == 1)
	{
		temp->link = first;
		return temp;
	}

	count = 1;
	prev = NULL;
	cur = first;

	while(cur != NULL && count != pos)
	{
		prev = cur;
		cur = cur->link;
		count++;
	}

	if(count == pos)
	{
		prev->link = temp;
		temp->link = cur;
		return first;
	}

	printf("\nInvalid Position");
	return first;
}


void fnDisplay(NODEPTR first)
{
	NODEPTR temp;

	if(first == NULL)
	{
		printf("\nList is Empty\n");
		return;
	}

	printf("\nList Contents\n");
	printf("==================================\n");
	for(temp = first; temp != NULL; temp = temp->link)
    	printf("%4d",temp->info);
	printf("\n==================================\n");
	printf("\n\n");

}

NODEPTR fnReverse(NODEPTR first)
{
    NODEPTR cur, prev, next;
    prev = first;
    cur = first->link;
    next = cur->link;
    prev->link = NULL;
    while(cur->link!=NULL)
    {
        cur->link = prev;
        prev = cur;
        cur = next;
        next = next->link;
    }
    cur->link = prev;
    return cur;
}
