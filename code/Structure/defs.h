#ifndef DEFS_H_INCLUDED
#define DEFS_H_INCLUDED

struct stDateOfPurchase
{
    int dd,mm,yy;
};
//typedef struct stDateOfPurchase DOP;
struct stItemsInfo
{
    int iItemno;
    float fPrice;
    struct stDateOfPurchase stDate;
    //DOP stDate;
};

#endif // DEFS_H_INCLUDED
