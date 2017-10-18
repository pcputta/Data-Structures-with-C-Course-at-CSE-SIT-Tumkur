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
NODEPTR fnInsertRear(int ,NODEPTR);
NODEPTR fnDeleteRear(NODEPTR);
void fnDisplay(NODEPTR first);
NODEPTR fnInsertPosition(int ,int ,NODEPTR);
NODEPTR fnDeletePosition(int ,NODEPTR);
NODEPTR fnDeleteKey(int ,NODEPTR);
NODEPTR fnReverse(NODEPTR);

int main()
{
    int iElem, iChoice, iPos, iKey;
//	NODEPTR first = NULL;
    NODEPTR head;
    head = fnGetNode();
    head->link = NULL;
    head->info = 0;

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
			        head = fnInsertFront(iElem, head);
					break;

			case 2: head = fnDeleteFront(head);
					break;

			case 3: fnDisplay(head);
					break;

			case 4: printf("\nEnter a element\n");
			        scanf("%d", &iElem);
			        head = fnInsertRear(iElem, head);
					break;
					
			case 5: head = fnDeleteRear(head);
					break;
					
			case 6: printf("\nEnter element to be inserted : ");
			        scanf("%d", &iElem);
			        printf("\nEnter position : ");
			        scanf("%d", &iPos);
			        head = fnInsertPosition(iElem, iPos, head);
			        break;
			        	                
			case 7: head = fnReverse(head);
			        break;
			        
	        case 8: printf("\nEnter element to be deleted : ");
	                scanf("%d", &iKey);
	                head = fnDeleteKey(iKey, head);
	                break;

	        case 9: printf("\nEnter position to delete element: ");
			        scanf("%d", &iPos);
			        head = fnDeletePosition(iPos, head);
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

NODEPTR fnInsertFront(int elem,NODEPTR head)
{
	NODEPTR temp;
	temp = fnGetNode();
	temp->info = elem;
	
	temp->link = head->link;
	head->link = temp;
	(head->info)++;
	
	return head;
}

NODEPTR fnDeleteFront(NODEPTR head)
{
	NODEPTR first;
	if(head->link == NULL)
	{
	    printf("\nList is Empty cannot delete\n");
	    return head;
	}

    first = head->link;
    printf("\nElement deleted is %d\n", first->info);

	head->link = first->link;
	(head->info)--;
    fnFreeNode(first);
	return head;
}

NODEPTR fnInsertPosition(int elem,int pos,NODEPTR head)
{
	NODEPTR temp,prev,cur;
	int count;

	temp = fnGetNode();
	temp->info = elem;
	temp->link = NULL;

	if(head->link == NULL && pos == 1)
	{
	    head->link = temp;
	    (head->info)++;
	    return head;
	}
    

	if(head->link == NULL)
	{
		printf("\nInvalid Position");
		return head;
	}

	if(pos == 1)
	{
	    temp->link = head->link;
		head->link = temp;
		(head->info)++;
		return head;
	}


	count = 1;
	prev = head;
	cur = head->link;

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
		(head->info)++;
		return head;
	}

	printf("\nInvalid Position");
	return head;
}

void fnDisplay(NODEPTR head)
{
	NODEPTR temp;
	if(head->link == NULL)
	{
		printf("\nList is Empty\n");
		return;
	}
	printf("\nList has %d nodes\n", head->info);
	printf("\nList Contents\n");
	printf("==================================\n");
	for(temp = head->link; temp != NULL; temp = temp->link)
    	printf("%4d",temp->info);
	printf("\n==================================\n");
	printf("\n\n");

}

NODEPTR fnReverse(NODEPTR head)
{
    NODEPTR cur, prev, next, first;
    if(head->link == NULL)
    {
		printf("\nList is Empty\n");
		return head;
    }
    first = head->link;
    if(first->link == NULL)
    {
        return head;
    }
    prev = head->link;
    cur = prev->link;
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
    head->link = cur;
    return head;
}

NODEPTR fnInsertRear(int iElem,NODEPTR head)
{
	NODEPTR temp,cur;

	temp = fnGetNode();
	temp->info = iElem;
	temp->link = NULL;

    (head->info)++;
    if(head->link == NULL)
    {
        head->link = temp;
        return head;
    }

    cur = head->link;
    while(cur->link != NULL)
    {
        cur = cur->link;
    }    
    cur->link = temp;
    return head;
}

NODEPTR fnDeleteRear(NODEPTR head)
{
	NODEPTR cur, prev;
	if(head->link == NULL)
	{
	    printf("\nList is Empty cannot delete\n");
	    return head;
	}

    prev = head;
    cur = head->link;
    while(cur->link != NULL)
    {
        prev = cur;
        cur = cur->link;
    }

    printf("\nElement deleted is %d\n", cur->info);

	prev->link = NULL;
    fnFreeNode(cur);
    (head->info)--;
	return head;
}

NODEPTR fnDeletePosition(int pos,NODEPTR head)
{
	NODEPTR temp,prev,cur;
	int count;

	if(head->link == NULL)
	{
		printf("\nEmpty List cannot delete\n");
		return head;
	}
	if(pos == 1)
	{
	    temp = head->link;
		head->link = temp->link;
		printf("\nElement deleted is %d\n", temp->info);
		fnFreeNode(temp);
		(head->info)--;
		return head;
	}

	count = 1;
	prev = head;
	cur = head->link;

	while(cur != NULL && count != pos)
	{
		prev = cur;
		cur = cur->link;
		count++;
	}
    if(cur == NULL)
    {
    	printf("\nInvalid Position");
    	return head;
    }

	if(count == pos)
	{
		prev->link = cur->link;
		printf("\nElement deleted is %d\n", cur->info);
		fnFreeNode(cur);
		(head->info)--;
		return head;
	}
}

NODEPTR fnDeleteKey(int key,NODEPTR head)
{
	NODEPTR prev,cur,first;

	if(head->link == NULL)
	{
		printf("\nEmpty List cannot delete\n");
		return head;
	}
    first = head->link;
	if(first->info == key)
	{
		head->link = first->link;
		printf("\nElement deleted is %d\n", first->info);
		fnFreeNode(first);
		(head->info)--;
		return head;
	}

	prev = head;
	cur = head->link;

	while(cur != NULL && cur->info != key)
	{
		prev = cur;
		cur = cur->link;
	}

    if(cur == NULL)
    {
    	printf("\nKey element not found in the list\n");
    	return head;
    }
    
	if(cur->info == key)
	{
		prev->link = cur->link;
		printf("\nElement deleted is %d\n", cur->info);
		fnFreeNode(cur);
		(head->info)--;
		return head;
	}
}

