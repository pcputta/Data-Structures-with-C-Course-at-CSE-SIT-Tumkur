
#include <stdio.h>
#include <stdlib.h>

#define PI 3.1416

typedef struct{
	int iRadius;
	double dCirc, dArea;
}circle_t;

int main()
{
	circle_t c1;
	circle_t *pc;

	pc = &c1;

	printf("\nEnter the radius of the circle\n");
	scanf("%d", &pc->iRadius);			//&c1.iRadius

	pc->dCirc = 2 * PI * pc->iRadius;
//	c1.dCirc = 2 * PI * c1.iRadius;

	pc->dArea = PI * pc->iRadius * pc->iRadius;
//	c1.dArea = PI * c1.iRadius * c1.iRadius;

	printf("\nCircle Details\nRadius = %d\n",pc->iRadius);
//	printf("\nCircle Details\nRadius = %d\n",c1.iRadius);
	printf("\nCircumference = %lf\nArea = %lf\n",pc->dCirc,pc->dArea);
//	printf("\nCircumference = %lf\nArea = %lf\n",c1.dCirc,c1.dArea);
	return 0;
}
