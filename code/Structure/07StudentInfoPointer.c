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
	student_t *sp;
	int iNum, i;

	printf("\nEnter the no. of students\n");
	scanf("%d", &iNum);

	sp = s;

	printf("\nEnter students info\n");
	for(i=0;i<iNum;i++,sp++)
	{
		printf("\nName : ");
		gets(sp->acName);
		printf("\nAge : ");
		scanf("%d", &sp->iAge);
		printf("\nUSN : ");
		gets(sp->acUsn);
		printf("\nMarks 1 : ");
		scanf("%d", &sp->iM1);
		printf("\nMarks 2 : ");
		scanf("%d", &sp->iM2);		
		printf("\nMarks 3 : ");
		scanf("%d", &sp->iM3);

		sp->fPercent = (sp->iM1 + sp->iM2 + sp->iM3)/3.0;

	}

	return 0;
}
