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
NODEPTR fnInsertPosition(int ,int ,NODEPTR);
void fnDisplay(NODEPTR first);
NODEPTR fnReverse(NODEPTR);
NODEPTR fnInsertRear(int ,NODEPTR);
NODEPTR fnDeleteRear(NODEPTR);
NODEPTR fnDeletePosition(int ,NODEPTR);
NODEPTR fnDeleteKey(int ,NODEPTR);

int main()
{
	NODEPTR first = NULL;
	int iElem, iChoice, iPos, iKey;
	for(;;)
	{
		printf("\n1.Insert Front\t2.Delete Front");
		printf("\t\t3.Display\n4.Insert Rear\t5.Delete Rear\t\t6.Insert Element at position");
		printf("\n7.Reverse\t8.Delete Element\t9.Delete at Position\n10.Exit");
		printf("\nEnter your choice\n");
		scanf("%d",&iChoice);
		switch(iChoice)
		{
			case 1: printf("\nEnter a element\n");
			        scanf("%d", &iElem);
			        first = fnInsertFront(iElem, first);
					break;

			case 2: first = fnDeleteFront(first);
					break;

			case 3: fnDisplay(first);
					break;

			case 4: printf("\nEnter a element\n");
			        scanf("%d", &iElem);
			        first = fnInsertRear(iElem, first);
					break;
					
			case 5: first = fnDeleteRear(first);
					break;
					
			case 6: printf("\nEnter element to be inserted : ");
			        scanf("%d", &iElem);
			        printf("\nEnter position : ");
			        scanf("%d", &iPos);
			        first = fnInsertPosition(iElem, iPos, first);
			        break;
			        	                
			case 7: first = fnReverse(first);
			        break;
			        
	        case 8: printf("\nEnter element to be deleted : ");
	                scanf("%d", &iKey);
	                first = fnDeleteKey(iKey, first);
	                break;

	        case 9: printf("\nEnter position to delete element: ");
			        scanf("%d", &iPos);
			        first = fnDeletePosition(iPos, first);
			        break;

			case 10:exit(0);
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

	first = first->link;
    fnFreeNode(temp);
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
    if(first == NULL)
    {
        printf("\nList is Empty\n");
        return first;
    }

    if(first->link == NULL)
    {
        return first;
    }

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

NODEPTR fnInsertRear(int iElem,NODEPTR first)
{
	NODEPTR temp,cur;

	temp = fnGetNode();
	temp->info = iElem;
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

NODEPTR fnDeleteRear(NODEPTR first)
{
	NODEPTR cur, prev;
	if(first == NULL)
	{
	    printf("\nList is Empty cannot delete\n");
	    return first;
	}
	if(first->link == NULL)
	{
        printf("\nElement deleted is %d\n", first->info);	    
        fnFreeNode(first);
        return NULL;
	}

    prev = NULL;
    cur = first;
    while(cur->link != NULL)
    {
        prev = cur;
        cur = cur->link;
    }

    printf("\nElement deleted is %d\n", cur->info);

	prev->link = NULL;
    fnFreeNode(cur);
	return first;
}

NODEPTR fnDeletePosition(int pos,NODEPTR first)
{
	NODEPTR temp,prev,cur;
	int count;

	if(first == NULL)
	{
		printf("\nEmpty List cannot delete\n");
		return first;
	}

	if(pos == 1)
	{
	    temp = first;
		first = first->link;
		printf("\nElement deleted is %d\n", temp->info);
		fnFreeNode(temp);
		return first;
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

    if(cur == NULL)
    {
	    printf("\nInvalid Position");
	    return first;    
    }
	if(count == pos)
	{
		prev->link = cur->link;
		printf("\nElement deleted is %d\n", cur->info);
		fnFreeNode(cur);
		return first;
	}

}

NODEPTR fnDeleteKey(int key,NODEPTR first)
{
	NODEPTR temp,prev,cur;

	if(first == NULL)
	{
		printf("\nEmpty List cannot delete\n");
		return first;
	}

	if(first->info == key)
	{
	    temp = first;
		first = first->link;
		printf("\nElement deleted is %d\n", temp->info);
		fnFreeNode(temp);
		return first;
	}

	prev = NULL;
	cur = first;

	while(cur != NULL && cur->info != key)
	{
		prev = cur;
		cur = cur->link;
	}

    if(cur == NULL)
    {
	    printf("\nKey element not found in the list\n");
	    return first;    
    }
    
	if(cur->info == key)
	{
		prev->link = cur->link;
		printf("\nElement deleted is %d\n", cur->info);
		fnFreeNode(cur);
		return first;
	}

}

