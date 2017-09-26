#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct{
	int iXcor, iYcor;
}point_t;

int main()
{
	point_t p1, p2;
	double dDistance;
	
	printf("\nCoordinates for point 1\n");
	scanf("%d%d", &p1.iXcor, &p1.iYcor);

	printf("\nCoordinates for point 2\n");
	scanf("%d%d", &p2.iXcor, &p2.iYcor);

	dDistance = sqrt((p2.iXcor - p1.iXcor)*(p2.iXcor - p1.iXcor) + ((p2.iYcor - p1.iYcor)*(p2.iYcor - p1.iYcor)));

	printf("\nDistance between the two points is %lf\n", dDistance);

	return 0;
}







