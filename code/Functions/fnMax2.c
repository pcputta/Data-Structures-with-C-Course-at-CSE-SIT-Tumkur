#include <stdio.h>

float find_max(float, float);	/* the function prototype */
float find_max(float val1, float val2);	/* the function prototype */

int main(void)
{
	float firstnum, secnum, maxnum;

	printf("Enter a number:");
	scanf ("%f", &firstnum);
	printf("\nGreat! Please enter a second number:");
	scanf ("%f", &secnum);

	maxnum = find_max(firstnum,secnum);/*the function is called here*/
	printf("\nThe maximum of the two numbers entered is %f", maxnum);

	return 0;
}


float find_max(float x, float y)
{
	float maxnum;
	if (x >= y)
		maxnum = x;
	else
		maxnum = y;
	return(maxnum);
}

