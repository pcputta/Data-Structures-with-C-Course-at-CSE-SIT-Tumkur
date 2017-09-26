#include<stdio.h>									/*CPP*/
//#include<conio.h>

#define N 3

int Qu[3][N];
int Fr[3] = {0,0,0};
int Re[3] = {-1,-1,-1};

int Item,Prio;

pqinsert(int Prio)
{
	if(Re[Prio] == N-1)
		printf("\nQueue Overflow\n");
	else
	{
		printf("\nEnter the item\n");
		scanf("%d",&Item);
		Re[Prio]++;
		Qu[Prio][Re[Prio]] = Item;
	}
	return;
}

void pqdelete()
{
	int i;
	for(i=0;i<3;i++)
	{
		if(Re[i] == Fr[i] - 1)
		{
			printf("\nQueue %d is Empty\n",i+1);
		}
		/*else
		if(Re[i] == Fr[i])
		{
			printf("\nDeleted element is %d of Queue %d\n",Qu[i][Fr[i]],i+1);
			Fr[i] = 0;
			Re[i] = -1;
		} */
		else
		{
			printf("\nDeleted element is %d of Queue %d\n",Qu[i][Fr[i]],i+1);
			Fr[i]++;
			return;
		}
	}
}

void display()
{
	int i,j;
	for(i=0;i<3;i++)
	{
		if(Re[i] == Fr[i] - 1)
			printf("\nNo Elements in Queue %d\n",i+1);
		else
		{
			printf("\nQueue %d\n",i+1);
			for(j=Fr[i];j<=Re[i];j++)
			printf("\%d\t",Qu[i][j]);
			printf("\n");
			printf("\nFront of Queue is %d",Qu[i][Fr[i]]);
			printf("\nRear of Queue is %d\n",Qu[i][Re[i]]);

		}

	}

	printf("\nPress any key......\n");
	getchar();
	getchar();
	return;
}

main()
{
    int ch;

    while(1)
    {
        printf("\nPRIORITY QUEUE\n");
        printf("==================");
        printf("\n1.PQinsert\n2.PQdelete\n3.PQdisplay\n4.Exit\n");
        printf("\nEnter your choice\n");
        scanf("%d",&ch);

        switch(ch)
        {
	        case 1: printf("\nEnter the priority number between 1 & 3:\n");
		        scanf("%d",&Prio);
		        if((Prio > 0) && (Prio < 4))
			        pqinsert(Prio-1);
		        else
			        printf("\nWrong Priority\n");
		        break;

	        case 2: pqdelete();
		        break;
	        case 3: display();
		        break;
	        case 4: exit(0);
        }
    }
}





/*CPP*/
