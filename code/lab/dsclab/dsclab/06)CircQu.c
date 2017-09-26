#include<stdio.h>										/*CPP*/
//#include<conio.h>

#define N 4

int Queue[N],Front = -1,Rear = -1,Item;

cqinsert()
{
        if((Front == (Rear+1) % N))
        {
                printf("\nQueue Overflow\n");
                return;
        }
        else
        {
		printf("\nEnter the element to be inserted\n");
                scanf("%d",&Item);
                if(Front == -1)
                        Front = Rear = 0;
                else
			Rear = (Rear + 1) % N;
                Queue[Rear] = Item;
        }
        return;

}

int cqdelete()
{
        if(Front == -1)
        {
                printf("\nQueue Underflow\n");
                return;
	}
        else
        {
                Item = Queue[Front];
                printf("\nThe item deleted is %d",Queue[Front]);
                Queue[Front] = NULL;
                if(Front == Rear)
                        Front = Rear = -1;
                else
                        Front = (Front+1) % N;
        }
        return;
}

display()
{
        int i;

        if(Front == -1)
        {
                printf("\nQueue is Empty\n");
        }
        else
        {
                if(Front <= Rear)
                {
			for(i=Front;i<=Rear;i++)
                                printf("\n%d",Queue[i]);
                }
                if(Front > Rear)
                {
                        for(i=Front;i<=N-1;i++)
                                printf("\n%d",Queue[i]);
                        for(i=0;i<=Rear;i++)
                                printf("\n%d",Queue[i]);
                }
                printf("\n\nFront of the Queue is %d",Queue[Front]);
                printf("\nRear of the Queue is %d",Queue[Rear]);
        }
	return;
}

main()
{
        int ch;
  //      clrscr();
        for(;;)
        {
                printf("\nCIRCULAR QUEUE\n");
                printf("==================");
                printf("\n1.CQinsert\n2.CQdelete\n3.CQdisplay\n4.Exit\n");
                printf("\nEnter your choice\n");
		scanf("%d",&ch);

                switch(ch)
                {
                        case 1 : cqinsert();
                                 break;
                        case 2 : cqdelete();
                                 break;
                        case 3 : display();
                                 break;
                        case 4 : exit(0);
                        default: printf("\nWrong Choice\n");
                }
        }
}








         /*CPP*/
