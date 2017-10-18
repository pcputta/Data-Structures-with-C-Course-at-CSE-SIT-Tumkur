#include <stdio.h>
#include <stdlib.h>
struct node
{
	int info;
	struct node *link;
};

typedef struct node* NODEPTR;

NODEPTR fnGetNode(void);
void fnFreeNode(NODEPTR x);
NODEPTR fnInsertFront(int ,NODEPTR);
NODEPTR fnDeleteFront(NODEPTR);
NODEPTR fnInsertPosition(int ,int ,NODEPTR);
void fnDisplay(NODEPTR first);
NODEPTR fnReverse(NODEPTR);
NODEPTR fnInsertRear(int ,NODEPTR);
NODEPTR fnDeleteRear(NODEPTR);
NODEPTR fnDeletePosition(int ,NODEPTR);
NODEPTR fnDeleteKey(int ,NODEPTR);
NODEPTR fnConcatenate(NODEPTR, NODEPTR);


int main()
{
	NODEPTR last = NULL;
	int iElem, iChoice, iPos, iKey;
	for(;;)
	{
		printf("\n1.Insert Front\t2.Delete Front");
		printf("\t\t3.Display\n4.Insert Rear\t5.Delete Rear\t\t6.Insert Element at position");
		printf("\n7.Reverse\t8.Delete Element\t9.Delete at Position\n10.Exit");
		printf("\nEnter your choice\n");
		scanf("%d",&iChoice);
		switch(iChoice)
		{
			case 1: printf("\nEnter a element\n");
			        scanf("%d", &iElem);
			        last = fnInsertFront(iElem, last);
					break;

			case 2: last = fnDeleteFront(last);
					break;

			case 3: fnDisplay(last);
					break;

			case 4: printf("\nEnter a element\n");
			        scanf("%d", &iElem);
			        first = fnInsertRear(iElem, first);
					break;
					
			case 5: first = fnDeleteRear(first);
					break;
					
			case 6: printf("\nEnter element to be inserted : ");
			        scanf("%d", &iElem);
			        printf("\nEnter position : ");
			        scanf("%d", &iPos);
			        first = fnInsertPosition(iElem, iPos, first);
			        break;
			        	                
			case 7: first = fnReverse(first);
			        break;
			        
	        case 8: printf("\nEnter element to be deleted : ");
	                scanf("%d", &iKey);
	                first = fnDeleteKey(iKey, first);
	                break;

	        case 9: printf("\nEnter position to delete element: ");
			        scanf("%d", &iPos);
			        first = fnDeletePosition(iPos, first);
			        break;

			case 10:exit(0);
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

void fnFreeNode(NODEPTR x)
{
	free(x);
}

NODEPTR fnInsertFront(int elem,NODEPTR last)
{
	NODEPTR temp, first;
	temp = fnGetNode();
	temp->info = elem;
	if(last == NULL)
	{
	    last = temp;
	    last->link = last;
	    return last;
	}
    first = last->link;
    last->link = temp;
	temp->link = first;

	return last;
}

//  last = fnDeleteFront(last);
NODEPTR fnDeleteFront(NODEPTR last)
{
	NODEPTR first;
	if(last == NULL)
	{
	    printf("\nList is Empty cannot delete\n");
	    return last;
	}
	if(last->link == last)
	{
	    printf("\nElement deleted is %d\n", last->info);
	    fnFreeNode(last);
	    return NULL;
	}

    first = last->link;
    printf("\nElement deleted is %d\n", first->info);

	last = first->link;
    fnFreeNode(first);
	return last;
}

NODEPTR fnInsertPosition(int elem,int pos,NODEPTR first)
{
	NODEPTR temp,prev,cur;
	int count;

	temp = fnGetNode();
	temp->info = elem;
	temp->link = NULL;

	if(first == NULL && pos == 1)
    	return temp;

	if(first == NULL)
	{
		printf("\nInvalid Position");
		return first;
	}

	if(pos == 1)
	{
		temp->link = first;
		return temp;
	}


	count = 1;
	prev = NULL;
	cur = first;

	while(cur != NULL && count != pos)
	{
		prev = cur;
		cur = cur->link;
		count++;
	}

	if(count == pos)
	{
		prev->link = temp;
		temp->link = cur;
		return first;
	}

	printf("\nInvalid Position");
	return first;
}

void fnDisplay(NODEPTR last)
{
	NODEPTR temp;

	if(last == NULL)
	{
		printf("\nList is Empty\n");
		return;
	}

	printf("\nList Contents\n");
	printf("==================================\n");
	for(temp = last->link; temp != last; temp = temp->link)
    	printf("%4d",temp->info);
	printf("%4d",temp->info);
	printf("\n==================================\n");
	printf("\n\n");

}

NODEPTR fnReverse(NODEPTR first)
{
    NODEPTR cur, prev, next;
    if(first == NULL)
    {
        printf("\nList is Empty\n");
        return first;
    }

    if(first->link == NULL)
    {
        return first;
    }

    prev = first;
    cur = first->link;
    next = cur->link;
    prev->link = NULL;
    while(cur->link!=NULL)
    {
        cur->link = prev;
        prev = cur;
        cur = next;
        next = next->link;
    }
    cur->link = prev;
    return cur;
}

//  last = fnInsertRear(elem, last);
NODEPTR fnInsertRear(int iElem,NODEPTR last)
{
	NODEPTR temp, first;
	temp = fnGetNode();
	temp->info = elem;
	if(last == NULL)
	{
	    last = temp;
	    last->link = last;
	    return last;
	}
    first = last->link;
    last->link = temp;
	temp->link = first;

	return temp;
}

NODEPTR fnDeleteRear(NODEPTR last)
{
	NODEPTR newLast;
	if(last == NULL)
	{
	    printf("\nList is Empty cannot delete\n");
	    return last;
	}
	if(last->link == NULL)
	{
        printf("\nElement deleted is %d\n", last->info);	    
        fnFreeNode(last);
        return NULL;
	}

    newLast = last->link;
    while(newLast->link != last)
    {
        newLast = newLast->link;
    }

    printf("\nElement deleted is %d\n", last->info);

    newLast->link = last->link;
    fnFreeNode(last);
	return newLast;
}

NODEPTR fnDeletePosition(int pos,NODEPTR first)
{
	NODEPTR temp,prev,cur;
	int count;

	if(first == NULL)
	{
		printf("\nEmpty List cannot delete\n");
		return first;
	}

	if(pos == 1)
	{
	    temp = first;
		first = first->link;
		printf("\nElement deleted is %d\n", temp->info);
		fnFreeNode(temp);
		return first;
	}

	count = 1;
	prev = NULL;
	cur = first;

	while(cur != NULL && count != pos)
	{
		prev = cur;
		cur = cur->link;
		count++;
	}

    if(cur == NULL)
    {
	    printf("\nInvalid Position");
	    return first;    
    }
	if(count == pos)
	{
		prev->link = cur->link;
		printf("\nElement deleted is %d\n", cur->info);
		fnFreeNode(cur);
		return first;
	}

}

NODEPTR fnDeleteKey(int key,NODEPTR last)
{
	NODEPTR temp,prev,cur;

	if(last == NULL)
	{
		printf("\nEmpty List cannot delete\n");
		return last;
	}
	
	if(last->link == last && last->info == key)
	{
		printf("\nElement deleted is %d\n", last->info);	
		fnFreeNode(last);
		return NULL;
	}

    first = last->link;
	prev = last;
	cur = first;

	while(cur->link != first && cur->info != key)
	{
		prev = cur;
		cur = cur->link;
	}

	if(cur->info == key && cur != last)
	{
		prev->link = cur->link;
		printf("\nElement deleted is %d\n", cur->info);
		fnFreeNode(cur);
		return last;
	}

	if(cur->info == key && cur == last)
	{
		prev->link = cur->link;
		printf("\nElement deleted is %d\n", cur->info);
		fnFreeNode(cur);
		return prev;
	}

    if(cur->link == first)
    {
	    printf("\nKey element not found in the list\n");
	    return last;    
    }
}


//  last3 = fnConcatenate(last1, last2);
NODEPTR fnConcatenate(NODEPTR last1, NODEPTR last2)
{
    NODEPTR last3, first1, first2;
    
    if(last1 == NULL && last2 == NULL)
    {
        return NULL;
    }
    if(last1 == NULL)
    {
        return last2;
    }
    if(last2 == NULL)
    {
        return last1;
    }
    first1 = last1->link;
    first2 = last2->link;
    
    last1->link = first2;
    last2->link = first1;
    return last2;
}
