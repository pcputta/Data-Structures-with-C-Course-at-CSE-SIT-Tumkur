#include<stdio.h>
#include<stdlib.h>

struct node
{
	int info;
	struct node *llink;
	struct node *rlink;
};

typedef struct node* NODEPTR;

NODEPTR fnSwapNodes(NODEPTR head, int m , int n);
void fnDisplay(NODEPTR head);
NODEPTR fnDelElemPos(NODEPTR head, int iPos);
NODEPTR fnInsertNext(NODEPTR head, int iItem);
NODEPTR fnDeleteFirst(NODEPTR last);
NODEPTR fnInsertFront(NODEPTR head, int iItem);
void fnFreeNode(NODEPTR x);
NODEPTR fnGetNode(void);



int main()
{
	NODEPTR head,last;
	int iChoice, iItem, iKey, iPos, iM, iN;

	head = fnGetNode();
	head->rlink = head;
	head->llink = head;
	head->info = 0;

	for(;;)

	{
		printf("\n1.Insert Front\n2.Insert to the next of a given Node");
		printf("\n3.Delete First Node");
		printf("\n4.Delete a Node whose position is specified");
		printf("\n5.Display\n6.Swap Nodes\n7.Exit\n");

		printf("\nEnter your Choice\n");
		scanf("%d",&iChoice);

		switch(iChoice)
		{
			case 1: printf("\nEnter the iItem to be inserted\n");
				    scanf("%d",&iItem);
				    head = fnInsertFront(head, iItem);
				    break;
		    
			case 2: printf("\nEnter the key value of the node\n");
			        scanf("%d", &iKey);
				    head = fnInsertNext(head, iKey);
				    break;

		    case 3: last = head->llink;
		            head = fnDeleteFirst(last);
		            break;

			case 4: printf("\nEnter the position of the element to be deleted\n");
				    scanf("%d",&iPos);
				    head = fnDelElemPos(head, iPos);
				    break;

			case 5: fnDisplay(head);
    				break;

			case 6: printf("\nEnter the positions m and n of the nodes to be swapped such that m < n\n");
			        scanf("%d%d",&iM, &iN);
			        if(iM > iN)
			        {
			            printf("\nInvalid input\n");
			        }
			        else
			        {
			            head = fnSwapNodes(head, iM, iN);
			        }
    				break;

			case 7: exit(0);
		}
	}
    return 0;
}

NODEPTR fnGetNode(void)
{
	NODEPTR x;
	x = ( NODEPTR ) malloc (sizeof(struct node));
	if(x == NULL)
	{
		printf("\nOut of Memory");
		exit(0);
	}
	return x;
}

void fnFreeNode(NODEPTR x)
{
	free(x);
}

NODEPTR fnInsertFront(NODEPTR head, int iItem)
{
	NODEPTR temp,cur;
	temp = fnGetNode();
	temp = fnGetNode();
	temp->info = iItem;

	cur = head->rlink;

	head->rlink = temp;
	temp->llink = head;
	temp->rlink = cur;
	cur->llink = temp;
	
	head->info += 1;

	return head;

}

NODEPTR fnDeleteFirst(NODEPTR last)
{
    NODEPTR second, first, head;
    
    if(last->rlink == last)
    {
        printf("\nList is Empty");
        return last;
    }
    head = last->rlink;
    first = head->rlink;
    second = first->rlink;
    
    head->rlink = second;
    second->llink = head;
    fnFreeNode(first);
    head->info -= 1;
    
    return head;
}

NODEPTR fnInsertNext(NODEPTR head, int iItem)
{
	NODEPTR temp,cur,next;

	if(head->rlink == head)
	{
		printf("\nList is Empty\n");
		return head;
	}

	cur = head->rlink;

	while(cur != head && iItem != cur->info)
	{
		cur = cur->rlink;
	}
	if(cur == head)
	{
		printf("\nSpecified Node not found\n");
		return head;
	}

	next = cur->rlink;

	printf("\nEnter the item to be inserted to the next of %d\n",iItem);

	temp = fnGetNode();
	scanf("%d",&temp->info);

	cur->rlink = temp;
	temp->llink = cur;
	next->llink = temp;
	temp->rlink = next;
	head->info += 1;

	return head;

}

NODEPTR fnDelElemPos(NODEPTR head, int iPos)
{

	NODEPTR prev,cur,next;
	int count = 1;
	
	if(head->rlink == head)
	{
		printf("\nList is Empty\n");
		return head;
	}

	cur = head->rlink;

	while(cur != head && count != iPos)
	{
		cur = cur->rlink;
		count++;
	}

    if(count == iPos)
    {
	    prev = cur->llink;
	    next = cur->rlink;

	    prev->rlink = next;
	    next->llink = prev;
	    head->info -= 1;

	    fnFreeNode(cur);    
    }

	if(cur == head)
	{
		printf("\nItem not found\n");
		return head;
	}

	return head;
}

void fnDisplay(NODEPTR head)
{
	NODEPTR temp;
	if(head->rlink == head)
	{
		printf("\nList is empty\n");
		return;
	}

	printf("Contents of the List is\n");
	for(temp = head->rlink; temp != head; temp = temp->rlink)
		printf("%d\t",temp->info);

	printf("\n");
	printf("\nThere are %d nodes in the list", head->info);	
	printf("\n");
	

}


NODEPTR fnSwapNodes(NODEPTR head, int m , int n)
{
    int temp, count = 1;
    NODEPTR cur, mpos, npos;
    cur = head->rlink;

    while(cur != head && count != m) 
    {
        cur = cur->rlink;
        count++;
    }

    if(cur != head)
    {
        mpos = cur;
    }
    else
    {
        printf("\nNode #%d does not exist\n", m);
        return head;
    }

    while(cur != head && count != n) 
    {
        cur = cur->rlink;
        count++;
    }
    if(cur != head)
    {
        npos = cur;
    }
    else
    {
        printf("\nNode #%d does not exist\n", n);
        return head;
    }
    
    temp = mpos->info;
    mpos->info = npos->info;
    npos->info = temp;
    
    return head;
}

