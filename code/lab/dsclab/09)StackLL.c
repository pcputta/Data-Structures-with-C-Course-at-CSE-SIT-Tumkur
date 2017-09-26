#include<stdio.h>						/*CPP*/
//#include<conio.h>
#include<stdlib.h>

struct node
{
	int Info;
	struct node *link;
};

typedef struct node* NODE;




NODE getnode()
{
	NODE newborn;
	newborn = (NODE)malloc(sizeof(struct node));

	if(newborn == NULL)
	{
		printf("\nMemory Overflow");
		exit(0);
	}
	return newborn;
}

void freenode(NODE x)
{
	free(x);
}


NODE push(int item,NODE first)  /*Insert front*/
{
        NODE temp;

        temp = getnode();

        temp->Info = item;

        temp->link = first;

        return temp;
}

NODE pop(NODE first)            /*Delete front*/
{
	NODE temp;
	if(first == NULL)
	{
		printf("\nStack is empty cannot delete\n");
		return first;
	}
	temp = first;

	first = first->link;

	printf("\nElement deleted is %d \n",temp->Info);
	freenode(temp);

	return first;

}



void display(NODE first)
{
	NODE curr;
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


main()
{
	NODE first = NULL;
	int choice,ch,item;
//	clrscr();


	for(;;)
	{
		printf("\nSTACK OPERATIONS");
		printf("\n1.PUSH\n2.POP\n3.DISPLAY\n4.EXIT\n");
		printf("\nEnter your choice\n");
		scanf("%d",&ch);

		switch(ch)
		{
			case 1: printf("\nEnter Element to be pushed onto Stack\n");
				scanf("%d",&item);
				first = push(item,first);
				break;

			case 2: first = pop(first);
				break;

			case 3: display(first);
				break;

			case 4: return;
		}
	}

}														/*CPP*/
