#include<stdio.h>										/*CPP*/
#define QUEUE_SIZE 4

int Queue[QUEUE_SIZE],iFront = -1,Rear = -1,Item;

void CircQueInsert()
{
        if((iFront == (Rear+1) % QUEUE_SIZE))
        {
                printf("\nQueue Overflow\n");
                return;
        }
        else
        {
		printf("\nEnter the element to be inserted\n");
                scanf("%d",&Item);
                if(iFront == -1)
                        iFront = Rear = 0;
                else
			Rear = (Rear + 1) % QUEUE_SIZE;
                Queue[Rear] = Item;
        }
        return;

}

int cqdelete()
{
        if(iFront == -1)
        {
                printf("\nQueue Underflow\n");
                return;
	}
        else
        {
                Item = Queue[iFront];
                printf("\nThe item deleted is %d",Queue[iFront]);
                Queue[iFront] = QUEUE_SIZEULL;
                if(iFront == Rear)
                        iFront = Rear = -1;
                else
                        iFront = (iFront+1) % QUEUE_SIZE;
        }
        return;
}

display()
{
        int i;

        if(iFront == -1)
        {
                printf("\nQueue is Empty\n");
        }
        else
        {
                if(iFront <= Rear)
                {
			for(i=iFront;i<=Rear;i++)
                                printf("\n%d",Queue[i]);
                }
                if(iFront > Rear)
                {
                        for(i=iFront;i<=QUEUE_SIZE-1;i++)
                                printf("\n%d",Queue[i]);
                        for(i=0;i<=Rear;i++)
                                printf("\n%d",Queue[i]);
                }
                printf("\n\nFront of the Queue is %d",Queue[iFront]);
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
                        case 1 : CircQueInsert();
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
