#include<stdio.h>
#include<stdlib.h>

struct node
{
	int info;
	struct node *llink;
	struct node *rlink;
};
typedef struct node* NODEPTR;

NODEPTR fnGetNode(void);
void fnFreeNode(NODEPTR x);
NODEPTR fnInsertFront(NODEPTR head, int iItem);
NODEPTR fnDeleteFront(NODEPTR head);
NODEPTR fnInsertRear(NODEPTR head, int iItem);
NODEPTR fnDeleteRear(NODEPTR head);
void fnDisplay(NODEPTR head);

int main()
{
	NODEPTR head;
	int iChoice, iItem;

	head = fnGetNode();
	head->rlink = head;
	head->llink = head;

	for(;;)
	{
		printf("\n1.Insert Front\n2.Insert Rear");
		printf("\n3.Delete Front\n4.Delete Rear");
		printf("\n5.Display\n6.Exit\n");
		printf("\nEnter your Choice\n");
		scanf("%d",&iChoice);

		switch(iChoice)
		{
			case 1: printf("\nEnter the iItem to be inserted\n");
				    scanf("%d",&iItem);
				    head = fnInsertFront(head, iItem);
				    break;
		    
			case 2: printf("\nEnter the iItem to be inserted\n");
				    scanf("%d",&iItem);
				    head = fnInsertRear(head, iItem);
				    break;

		    case 3: head = fnDeleteFront(head);
		            break;

			case 4: head = fnDeleteRear(head);
				    break;

			case 5: fnDisplay(head);
    				break;
    				
			case 6: exit(0);
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
	return head;
}

NODEPTR fnInsertRear(NODEPTR head, int iItem)
{
	NODEPTR temp,cur;
	temp = fnGetNode();
	temp = fnGetNode();
	temp->info = iItem;

	cur = head->llink;
	head->llink = temp;
	temp->rlink = head;
	temp->llink = cur;
	cur->rlink = temp;
	return head;
}

NODEPTR fnDeleteFront(NODEPTR head)
{
    NODEPTR second, first;    
    if(head->rlink == head)
    {
        printf("\nList is Empty\n");
        return head;
    }
    first = head->rlink;
    second = first->rlink;
    
    head->rlink = second;
    second->llink = head;
    printf("\nElement deleted is %d\n", first->info);
    fnFreeNode(first);    
    return head;
}

NODEPTR fnDeleteRear(NODEPTR head)
{
    NODEPTR secondLast, last;    
    if(head->rlink == head)
    {
        printf("\nList is Empty\n");
        return head;
    }
    last = head->llink;
    secondLast = last->llink;
    
    head->llink = secondLast;
    secondLast->rlink = head;
    printf("\nElement deleted is %d\n", last->info);
    fnFreeNode(last);    
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
}

