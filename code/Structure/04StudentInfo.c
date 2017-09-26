#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STRSIZ 40

typedef struct {
	char acName[STRSIZ];
	int iAge;
	char acUsn[10];
	int iM1,iM2,iM3;
	float fPercent;
}student_t;

int main()
{
	student_t s[100];
	int iNum, i;

	printf("\nEnter the no. of students\n");
	scanf("%d", &iNum);

	printf("\nEnter students info\n");
	for(i=0;i<iNum;i++)
	{
		printf("\nName : ");
		gets(s[i].acName);
		printf("\nAge : ");
		scanf("%d", &s[i].iAge);
		printf("\nUSN : ");
		gets(s[i].acUsn);
		printf("\nMarks 1 : ");
		scanf("%d", &s[i].iM1);
		printf("\nMarks 2 : ");
		scanf("%d", &s[i].iM2);		
		printf("\nMarks 3 : ");
		scanf("%d", &s[i].iM3);

		s[i].fPercent = (s[i].iM1 + s[i].iM2 + s[i].iM3)/3.0;

	}

	return 0;
}
