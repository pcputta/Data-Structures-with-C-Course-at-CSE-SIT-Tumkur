/***************************************************************************
*File		: 14Inventory
*Description	: Program to display inventory information
*Author		: Prabodh C P
*Compiler	: gcc compiler, Ubuntu 8.10
*Date		: 7 September 2010
***************************************************************************/

#include<stdio.h>
#include<stdlib.h>

struct stDateOfPurchase
{
    int dd,mm,yy;
};

struct stItemsInfo
{
    int iItemno;
    float fPrice;
    struct stDateOfPurchase stDate;
};


struct stItemsInfo fnGetItemInfo(void);
void fnPutItemInfo(struct stItemsInfo);

/***************************************************************************
*Function	: 	main
*Input parameters:	no parameters
*RETURNS	:	0 on success
***************************************************************************/


int main(void)
{
    struct stItemsInfo list[100];
    int iNum,i;
    printf("\nEnter the number of Items\n");
    scanf("%d",&iNum);

    for(i=0;i<iNum;i++)
    {
        list[i] = fnGetItemInfo();
    }

    printf("\n========================================");
    printf("\nItem No\t||   Price\t|| Purchase Date\n");
    printf("========================================\n");
    for(i=0;i<iNum;i++)
    {
        fnPutItemInfo(list[i]);
        printf("\n");
    }

    return 0;
}

struct stItemsInfo fnGetItemInfo(void)
{
    struct stItemsInfo temp;
    printf("\nEnter Item Info\n");
    printf("\nItem no: ");
    scanf("%d",&temp.iItemno);
    printf("\nPrice: ");
    scanf("%f",&temp.fPrice);
    printf("\nDate of purchase\n");
    printf("\nDay: ");
    scanf("%d",&temp.stDate.dd);
    printf("\nMonth: ");
    scanf("%d",&temp.stDate.mm);
    printf("\nYear: ");
    scanf("%d",&temp.stDate.yy);
    return temp;

}

void fnPutItemInfo(struct stItemsInfo temp)
{
    printf("%4d\t|| %7.2f\t|| %02d/%02d/%02d",temp.iItemno,temp.fPrice,temp.stDate.dd,temp.stDate.mm,temp.stDate.yy);
}
