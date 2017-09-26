#include<stdio.h>									/*CPP*/
//#include<conio.h>
#define N 5
struct queue
{
	int Items[N];
	int Front;
	int Rear;
}q;

void qinsert()
{
	int item;
	if(qfull())
	printf("\nQueue Overflow\n");
	else
	{
		printf("\nEnter the  element\n");
		scanf("%d",&item);
		q.Rear++;
		q.Items[q.Rear] = item;

	}
}

void qdelete()
{
	if(qempty())
	printf("\nQueue Underflow\n");
	else
	if(q.Rear == q.Front)
	{
		printf("\nItem deleted is %d\n",q.Items[q.Front]);
		q.Rear=-1;
		q.Front=0;
	}
	else
	{
		printf("\nItem deleted is %d\n",q.Items[q.Front++]);
	}
}

void qdisplay()
{
	int i;
	if(qempty())
	printf("\nQueue Empty\n");
	else
	{
		printf("\nContents of Queue are:\n");
		for(i=q.Front;i<=q.Rear;i++)
		printf("%d\t",q.Items[i]);
	}
}

int qfull()
{
	if(q.Rear == N-1)
		return 1;
	else
		return 0;
}

int qempty()
{
	if(q.Rear == q.Front-1)
		return 1;
	else
		return 0;
}


main()
{
	int ch;
	q.Front = 0;
	q.Rear = -1;
//	clrscr();
	for(;;)
	{
                printf("\nQueue Operations\n");
                printf("=====================");

		printf("\n1.Qinsert\n2.Qdelete\n3.Qdisplay\n4.Exit\n");
		printf("Enter your choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: qinsert();

				break;
			case 2: qdelete();

				break;
			case 3: qdisplay();

				break;
			case 4: exit(0);
			default: printf("\nWrong Choice\n");
				break;
		}
	}
}





/*CPP*/
