#include<stdio.h>									/*CPP*/
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


NODE ins_rear(int item,NODE first)
{
	NODE temp,cur;

	temp = getnode();

	temp->Info = item;

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

NODE del_front(NODE first)
{
	NODE temp;
	if(first == NULL)
	{
		printf("\nQueue is empty cannot delete\n");
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


main()
{
	NODE first = NULL;
	int choice,ch,item;
//	clrscr();


	for(;;)
	{
		printf("\nQUEUE OPERATIONS\n");
		printf("====================");
		printf("\n1.Insert Rear\n2.Delete Front\n3.Display\n4.Exit\n");
		printf("\nEnter your choice\n");
		scanf("%d",&ch);

		switch(ch)
		{
			case 1: printf("\nEnter Element to be inserted\n");
				scanf("%d",&item);
				first = ins_rear(item,first);
				break;

			case 2: first = del_front(first);
				break;

			case 3: display(first);
				break;

			case 4: return;
		}
	}

}


/*CPP*/
