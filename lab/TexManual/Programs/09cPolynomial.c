#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct polynomial{
    int coeff;
    int exponent;
    struct polynomial *link;
};
typedef struct polynomial *NODEPTR;

NODEPTR fnGetNode(void);
NODEPTR fnInsertRear(int, int, NODEPTR);
void fnDisplay(NODEPTR first);
NODEPTR fnAddPoly(NODEPTR, NODEPTR);
int evalPoly(NODEPTR, int);

int main()
{
    NODEPTR poly1, poly2, poly3;
    int i, iX, iRes, iDegree, iaCoeff[10];
    poly1 = poly2 = poly3 = NULL;

    printf("\nEnter the degree of polynomial 1\n");
    scanf("%d", &iDegree);
    printf("\nEnter the coefficients\n");
    for(i=iDegree;i>=0;i--)
    {
        scanf("%d", &iaCoeff[i]);
        poly1 = fnInsertRear(iaCoeff[i], i, poly1);
    }
    printf("\nEnter the degree of polynomial 2\n");
    scanf("%d", &iDegree);
    printf("\nEnter the coefficients\n");
    for(i=iDegree;i>=0;i--)
    {
        scanf("%d", &iaCoeff[i]);
        poly2 = fnInsertRear(iaCoeff[i], i, poly2);
    }
    poly3 = fnAddPoly(poly1, poly2);
    
    printf("Polynomial 1   :\t");
    fnDisplay(poly1);
    printf("Polynomial 2   :\t");
    fnDisplay(poly2);
    printf("Polynomial Sum :\t");
    fnDisplay(poly3);
    printf("\nEnter the value of x\n");
    scanf("%d", &iX);
    iRes = evalPoly(poly3, iX);
    printf("\nValue of the polynomial sum for x = %d is %d\n", iX, iRes);    
    return 0;
}

NODEPTR fnInsertRear(int iCoeff, int iExp, NODEPTR first)
{
	NODEPTR temp,cur;
	temp = fnGetNode();
	temp->coeff = iCoeff;
	temp->exponent = iExp;
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

NODEPTR fnGetNode(void)
{
	NODEPTR newNode;
	newNode = ( NODEPTR ) malloc (sizeof(struct polynomial));
	if(newNode == NULL)
	{
		printf("\nOut of Memory");
		exit(0);
	}
	return newNode;
}

void fnDisplay(NODEPTR first)
{
    NODEPTR cur;
    for(cur = first; cur->link != NULL; cur = cur->link)
    {
//      printf(" (%d)x^(%d) +",cur->coeff,cur->exponent);
        printf(" (%d)x^%d +",cur->coeff,cur->exponent);
    }
    printf(" %d\n", cur->coeff);
}

NODEPTR fnAddPoly(NODEPTR poly1, NODEPTR poly2)
{
    NODEPTR tracker1, tracker2,poly3 = NULL;
    tracker1 = poly1;
    tracker2 = poly2;
    while(tracker1 != NULL && tracker2 != NULL)
    {
        if(tracker1->exponent > tracker2->exponent)
        {
            poly3 = fnInsertRear(tracker1->coeff, tracker1->exponent, poly3);
            tracker1 = tracker1->link;
        }
        else if(tracker1->exponent == tracker2->exponent)
        {
            poly3 = fnInsertRear(tracker1->coeff + tracker2->coeff, tracker1->exponent, poly3);
            tracker1 = tracker1->link;
            tracker2 = tracker2->link;
        }
        else
        {
            poly3 = fnInsertRear(tracker2->coeff, tracker2->exponent, poly3);
            tracker2 = tracker2->link;
        }
    }
    return poly3;
}

int evalPoly(NODEPTR list, int x)
{
    int iSum = 0;
    NODEPTR cur = list;
    while(cur!=NULL)
    {
        iSum += (cur->coeff * (int)pow(x, cur->exponent));
        cur = cur->link;
    }
    return iSum;
}

