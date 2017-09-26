#include<stdio.h>
#include<stdlib.h>
//#include<conio.h>

struct node
{
	int Info;

	struct node *llink;
	struct node *rlink;
};

typedef struct node* NODE;

NODE getnode(void)
{
	NODE x;
	x = ( NODE ) malloc (sizeof(struct node));
	if(x == NULL)
	{
		printf("\nOut of Memory");
		exit(0);
	}
	return x;
}

void freenode(NODE x)
{
	free(x);
}

NODE ins_front(int item,NODE head)
{
	NODE temp,cur;
	temp = getnode();
	temp = getnode();
	temp->Info = item;

	cur = head->rlink;

	head->rlink = temp;
	temp->llink = head;
	temp->rlink = cur;
	cur->llink = temp;

	return head;

}

NODE ins_left(int item,NODE head)
{
	NODE temp,cur,prev;

	if(head->rlink == head)
	{
		printf("\nList is Empty\n");
		return head;
	}

	cur = head->rlink;

	while(cur != head && item != cur->Info)
	{
		cur = cur->rlink;
	}
	if(cur == head)
	{
		printf("\nSpecified Node not found\n");
		return head;
	}

	prev = cur->llink;

	printf("\nEnter the item to be inserted to the left of %d\n",item);

	temp = getnode();
	scanf("%d",&temp->Info);

	prev->rlink = temp;
	temp->llink = prev;
	cur->llink = temp;
	temp->rlink = cur;

	return head;

}

NODE del_item(int item,NODE head)
{

	NODE prev,cur,next;
	if(head->rlink == head)
	{
		printf("\nList is Empty\n");
		return head;
	}

	cur = head->rlink;

	while(cur != head && item != cur->Info)
	{
		cur = cur->rlink;
	}

	if(cur == head)
	{
		printf("\nItem not found\n");
		return head;
	}

	prev = cur->llink;
	next = cur->rlink;

	prev->rlink = next;
	next->llink = prev;

	freenode(cur);
	return head;
}

void display(NODE head)
{
	NODE temp;
	if(head->rlink == head)
	{
		printf("\nDequeue is empty\n");
		return;
	}

	printf("Contents of the List is\n");
	for(temp = head->rlink; temp != head; temp = temp->rlink)
		printf("%d\t",temp->Info);

	printf("\n");

}

main()
{
	NODE head;
	int ch,item;

//	clrscr();

	head = getnode();
	head->rlink = head;
	//head->llink = head;

	for(;;)
	{
		printf("\n1.Insert Front\n2.Insert to the left of a given Node");
		printf("\n3.Delete a Node whose info field is specified");
		printf("\n4.Display\n5.Exit\n");

		printf("\nEnter your Choice\n");
		scanf("%d",&ch);

		switch(ch)
		{
			case 1: printf("\nEnter the item to be inserted\n");
				scanf("%d",&item);
				head = ins_front(item,head);
				break;

			case 2: printf("\nEnter the key value of the node\n");
				scanf("%d",&item);
				head = ins_left(item,head);
				break;

			case 3: printf("\nEnter the item to be deleted\n");
				scanf("%d",&item);
				head = del_item(item,head);
				break;

			case 4: display(head);
				break;

			case 5: exit(0);

		}

	}

}











