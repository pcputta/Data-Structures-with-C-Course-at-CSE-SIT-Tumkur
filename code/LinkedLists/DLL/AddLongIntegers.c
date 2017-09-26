#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct NODE{
    int info;
    struct NODE *link;
};

typedef struct NODE* NODEPTR;

NODEPTR allocNode();
NODEPTR buildList(NODEPTR, char[]);
NODEPTR insFront(NODEPTR, int);
NODEPTR insRear(NODEPTR, int);
void showNumber(NODEPTR);
NODEPTR addInt(NODEPTR, NODEPTR);

int main()
{
    char value1[100], value2[100];
    NODEPTR h1,h2,h3;
    h1 = allocNode();
    h1->link = h1;
    h1->info = 0;
    h2 = allocNode();
    h2->link = h2;
    h2->info = 0;

    printf("\nEnter the first long integer\n");
    scanf("%s",value1);
    h1 = buildList(h1, value1);
    printf("\nEnter the second long integer\n");
    scanf("%s",value2);
    h2 = buildList(h2, value2);

    h3 = addInt(h1,h2);

    printf("\nFirst Value : \t ");
    showNumber(h1);

    printf("\nSecond Value : \t ");
    showNumber(h2);

    printf("\nSum is : \t");
    showNumber(h3);

    return 0;
}

NODEPTR buildList(NODEPTR head, char value[])
{
    int i;

    for(i=0;value[i]!='\0';i++)
    {
        head = insFront(head, value[i]-'0');
    }
    return head;
}

void showNumber(NODEPTR head)
{
    int *number, i=0;
    NODEPTR cur;

    number = (int*)malloc(head->info*sizeof(int));
    cur = head->link;
    while(cur!=head)
    {
        number[i] = cur->info;
        cur = cur->link;
        i++;
    }
    for(--i;i>=0;i--)
    {
        printf("%d",number[i]);
    }
    printf("\n");
}

NODEPTR addInt(NODEPTR h1, NODEPTR h2)
{
    NODEPTR p,q,h3;
    int sum,digit,carry=0;

    h3 = allocNode();
    h3->link = h3;
    h3->info = 0;

    p = h1->link;
    q = h2->link;
    while(p != h1 && q != h2)
    {
        sum = p->info + q->info + carry;
        digit = sum%10;
        carry = sum/10;

        h3 = insRear(h3,digit);
        p = p->link;
        q = q->link;
    }
    while(p != h1)
    {
        sum = p->info + carry;
        digit = sum%10;
        carry = sum/10;

        h3 = insRear(h3,digit);
        p = p->link;
    }
    while(q != h2)
    {
        sum = q->info + carry;
        digit = sum%10;
        carry = sum/10;

        h3 = insRear(h3,digit);
        q = q->link;
    }
    if(carry > 0)
    {
        h3 = insRear(h3,carry);
    }
    return h3;
}

NODEPTR allocNode()
{
    NODEPTR newborn;
    newborn = (NODEPTR) malloc(sizeof(struct NODE));
    if(newborn == NULL)
    {
        printf("\nInsufficient Heap Memory\n");
        exit(0);
    }
    return newborn;
}

NODEPTR insFront(NODEPTR head, int val)
{
    NODEPTR temp, first;
    temp = allocNode();
    temp->info = val;
    first = head->link;
    head->link = temp;
    temp->link = first;
    (head->info)++;
    return head;
}

NODEPTR insRear(NODEPTR head, int val)
{
    NODEPTR temp, cur;
    temp = allocNode();
    temp->info = val;
    (head->info)++;

    cur = head->link;
    while(cur->link !=  head)
    {
        cur = cur->link;
    }
    cur->link = temp;
    temp->link = head;
    return head;
}

