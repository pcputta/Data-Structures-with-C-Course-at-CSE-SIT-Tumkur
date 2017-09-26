/***************************************************************************
*File		: 14Inventory
*Description	: Program to display inventory information
*Author		: Prabodh C P
*Compiler	: gcc compiler, Ubuntu 8.10
*Date		: 7 September 2010
***************************************************************************/

#include<stdio.h>
#include<stdio.h>
#include<stdlib.h>
#include "defs.h"
#include "inventory.h"

/***************************************************************************
*Function	: 	main
*Input parameters:	no parameters
*RETURNS	:	0 on success
***************************************************************************/


int main(void)
{
    struct stItemsInfo list[100];
    int iNum,i;
    printf("\nMemory allocated to stItemsInfo is %d and %d\n",sizeof(struct stItemsInfo),sizeof(float));
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
