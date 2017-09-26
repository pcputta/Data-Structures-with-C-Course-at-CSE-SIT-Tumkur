#include <stdio.h>
#include <math.h>

typedef struct
{
    int xCor, yCor;
}POINT_TYPE;


typedef struct
{
    int iRadius;
    POINT_TYPE center;
}CIRCLE_TYPE;

int main()
{
    CIRCLE_TYPE c1, c2;
    int iXdiff, iYdiff;
    double dDist;
    
    printf("Enter the radius of circle 1 : ");
    scanf("%d", &c1.iRadius);
    
    printf("\nEnter the coordinates of center of circle 1 : ");
    scanf("%d%d", &c1.center.xCor, &c1.center.yCor);
    
    printf("Enter the radius of circle 2 : ");
    scanf("%d", &c2.iRadius);
    
    printf("\nEnter the coordinates of center of circle 2 : ");
    scanf("%d%d", &c2.center.xCor, &c2.center.yCor);
    
    iXdiff = c1.center.xCor - c2.center.xCor;
    iYdiff = c1.center.yCor - c2.center.yCor;
    
    dDist = sqrt(iXdiff * iXdiff + iYdiff * iYdiff);

    if(dDist == (c1.iRadius + c2.iRadius))
        printf("\nTwo circles touch each other\n");
    else if(dDist > (c1.iRadius + c2.iRadius))
        printf("\nTwo circles are disjoint\n");
    else
        printf("\nTwo circles intersect one another\n");
    
    return 0;
}
