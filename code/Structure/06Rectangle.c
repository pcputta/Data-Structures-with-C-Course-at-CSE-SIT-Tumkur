#include <stdio.h>
#include <stdlib.h>

/*typedef struct {
	int ltXc, ltYc, rtXc, rtYc, lbXc, lbYc, rbXc, rbYc;
}rectangle_t;
*/

typedef struct{
	int iXcor, iYcor;
}point_t;
 
typedef struct{
	point_t lt,rb;
}rectangle_t;


int main()
{
	rectangle_t r1;
	int iLen, iBrd, iArea;

	printf("\nEnter the coordinates of left top corner\n");
	scanf("%d%d", &r1.lt.iXcor, &r1.lt.iYcor);

	printf("\nEnter the coordinates of right bottom corner\n");
	scanf("%d%d", &r1.rb.iXcor, &r1.rb.iYcor);
	
	iLen = abs(r1.rb.iXcor - r1.lt.iXcor);
	iBrd = abs(r1.lt.iYcor - r1.rb.iYcor);

	iArea = iLen * iBrd;

	printf("\nThe length of the rectangle is %d units\n", iLen);
	printf("\nThe breadth of the rectangle is %d units\n", iBrd);
	printf("\nThe area of the rectangle is %d units\n", iArea);




