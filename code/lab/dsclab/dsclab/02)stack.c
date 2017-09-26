#include <stdio.h>									/*CPP*/
//#include <conio.h>

#define ST_LIM 8
int Top = -1;
int s[ST_LIM];

void push()
{
	int item;
	if(Top == ST_LIM - 1)
	{
		printf("\nStack Overflow\n");

	}
	else
	{
		printf("\nEnter the element to be pushed\n");
		scanf("%d",&item);
		s[++Top] = item;
	}
}

void pop()
{
	if(Top == - 1)
	{
		printf("\nStack Underflow\n");
	}
	else
	{
		printf("\nPopped element is %d\n",s[Top]);
		--Top;
	}
}

void display()
{
	int i;
	if(Top == - 1)
	{
		printf("\nStack is Empty\n");
	}
	else
	{
		printf("\nContents of Stack are\n");
		for(i=Top;i>=0;i--)
		printf("%d\n",s[i]);
	}
}


main()
{
	int choice;
//	clrscr();
	while(1)
	{
                printf("\nSTACK OPERATIONS\n");
                printf("====================");
		printf("\n1.PUSH\n2.POP\n3.DISPLAY\n4.EXIT\n");
		printf("Enter your choice\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: push();
			        break;
			case 2: pop();
			        break;
			case 3: display();
			        break;
			case 4: exit(1);
			default: printf("\nWrong choice\n");
		}
	}
}




/*CPP*/
