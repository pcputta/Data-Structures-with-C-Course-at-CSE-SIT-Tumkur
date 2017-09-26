#include<stdio.h>										/*CPP*/
//#include<conio.h>

#define N 5

int q[N],Front=0,Rear=-1,Ch;

void qinsert()
{
	int item;
	if(qfull())
	printf("\nQueue Overflow\n");
	else
	{
		printf("\nEnter the  element\n");
		scanf("%d",&item);
		q[++Rear] = item;
	}
}

void qdelete()
{
	if(qempty())
	printf("\nQueue Underflow\n");
	else
	if(Rear==Front)
	{
		printf("\nItem deleted is %d\n",q[Front]);
		Rear=-1;
		Front=0;
	}
	else
	{
		printf("\nItem deleted is %d\n",q[Front++]);
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
		for(i=Front;i<=Rear;i++)
		printf("%d\t",q[i]);
	}
}

int qfull()
{
	if(Rear == N-1)
		return 1;
	else
		return 0;
}

int qempty()
{
	if(Rear == Front-1)
		return 1;
	else
		return 0;
}


main()
{
//	clrscr();

	for(;;)
	{
		printf("\nQueue Operations\n");
		printf("=====================");
		printf("\n1.Qinsert\n2.Qdelete\n3.Qdisplay\n4.Exit\n");
		printf("Enter your choice\n");
		scanf("%d",&Ch);
		switch(Ch)
		{
			case 1: qinsert();

				break;
			case 2: qdelete();

				break;
			case 3: qdisplay();

				break;
			case 4: exit(0);
			default: printf("\nInvalid choice\n");

				break;
		}
	}
}




/*CPP*/
