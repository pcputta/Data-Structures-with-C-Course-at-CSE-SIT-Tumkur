#ifndef UTILS_C_INCLUDED
#define UTILS_C_INCLUDED
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

#endif // UTILS_C_INCLUDED
