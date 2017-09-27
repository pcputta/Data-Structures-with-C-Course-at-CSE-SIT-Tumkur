#include <stdio.h>
#include <stdlib.h>
struct node
{
	int info;
	struct node *link;
};

typedef struct node* NODEPTR;

NODEPTR fnGetNode(void);
NODEPTR fnInsertOrder(int ,NODEPTR);
NODEPTR fnInsertRear(int ,NODEPTR);
NODEPTR fnUnion(NODEPTR ,NODEPTR);
NODEPTR fnIntersection(NODEPTR ,NODEPTR);
void fnDisplay(NODEPTR first);

int main()
{
	NODEPTR list1 , list2, list3, list4;
	list1 = list2 = list3 = list4 = NULL;	
	int iElem, iChoice;
	for(;;)
	{
		printf("\n1.Insert into List 1\n2.Insert into List 2\n3.Display");
		printf("\n4.Union\n5.Intersection\n6.Exit\n");
		printf("Enter your choice\n");
		scanf("%d",&iChoice);
		switch(iChoice)
		{
			case 1: printf("\nEnter a element\n");
			        scanf("%d", &iElem);
			        list1 = fnInsertOrder(iElem, list1);
					break;

			case 2: printf("\nEnter a element\n");
			        scanf("%d", &iElem);
			        list2 = fnInsertOrder(iElem, list2);
					break;

			case 3: printf("\nList 1 Contents\n");
                    fnDisplay(list1);
                    printf("\nList 2 Contents\n");
			        fnDisplay(list2);
					break;

			case 4: printf("\nList 1 Contents\n");
                    fnDisplay(list1);
                    printf("\nList 2 Contents\n");
			        fnDisplay(list2);
			        list3 = fnUnion(list1, list2);
    			    printf("\nUnion\n");
			        fnDisplay(list3);
					break;
					
			case 5: printf("\nList 1 Contents\n");
                    fnDisplay(list1);
                    printf("\nList 2 Contents\n");
			        fnDisplay(list2);
			        list4 = fnIntersection(list1, list2);
    			    printf("\nIntersection\n");
			        fnDisplay(list4);
					break;
			case 6: exit(0);
		}
	}
	return 0;
}

NODEPTR fnGetNode(void)
{
	NODEPTR newNode;
	newNode = ( NODEPTR ) malloc (sizeof(struct node));
	if(newNode == NULL)
	{
		printf("\nOut of Memory");
		exit(0);
	}
	return newNode;
}

NODEPTR fnIntersection(NODEPTR l1,NODEPTR l2)
{
	NODEPTR t1, t2, t3;
	t1 = l1;
	while(t1 != NULL)
	{
	    t2 = l2;
	    while(t2 != NULL)
	    {
	        if(t1->info == t2->info)
	            t3 = fnInsertRear(t1->info, t3);
            t2 = t2->link;
	    }
	    t1 = t1->link;
	}
	return t3;
}


NODEPTR fnUnion(NODEPTR l1,NODEPTR l2)
{
	NODEPTR t1, t2, t3;
	t1 = l1;
	t2 = l2;
	while(t1 != NULL && t2 != NULL)
	{
        if(t1->info < t2->info)
	    {
            t3 = fnInsertRear(t1->info, t3);
            t1 = t1->link;
	    }
	    else if(t1->info > t2->info)
	    {
            t3 = fnInsertRear(t2->info, t3);
            t2 = t2->link;
	    } 
	    else
	    {
	        t2 = t2->link;
	    }
	    
	}
	while(t1 != NULL)
	{
	    t3 = fnInsertRear(t1->info, t3);
	    t1 = t1->link;
	}
	while(t2 != NULL)
	{
	    t3 = fnInsertRear(t2->info, t3);
	    t2 = t2->link;
	}
	return t3;
}


NODEPTR fnInsertOrder(int elem, NODEPTR first)
{
	NODEPTR temp,prev,cur;

	temp = fnGetNode();
	temp->info = elem;
	temp->link = NULL;

	if(first == NULL)
    	return temp;
	
	if(elem <= first->info)
	{
	    temp->link = first;
	    return temp;
	}

	prev = NULL;
	cur = first;

	while(cur != NULL && elem > cur->info)
	{
		prev = cur;
		cur = cur->link;
	}
	prev->link = temp;
	temp->link = cur;
	return first;
}

void fnDisplay(NODEPTR first)
{
	NODEPTR temp;

	if(first == NULL)
	{
		printf("\nList is Empty\n");
		return;
	}

	printf("==================================\n");
	for(temp = first; temp != NULL; temp = temp->link)
    	printf("%4d",temp->info);
	printf("\n==================================\n");
}

NODEPTR fnInsertRear(int iElem, NODEPTR first)
{
	NODEPTR temp,cur;
	temp = fnGetNode();
	temp->info = iElem;
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

