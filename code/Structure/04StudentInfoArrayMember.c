#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STRSIZ 40

typedef struct {
	char acName[STRSIZ];
	int iAge;
	char acUsn[11];
	int iMarks[3];
	float fPercent;
}STUDENT_TYPE;

int main()
{
	STUDENT_TYPE s[100];
	int iNum, i;

	printf("\nEnter the no. of students\n");
	scanf("%d", &iNum);
	getchar();
	

	printf("\nEnter students info\n");
	for(i=0;i<iNum;i++)
	{
		printf("\nName : ");
		gets(s[i].acName);
		printf("\nAge : ");
		scanf("%d", &s[i].iAge);
		getchar();
		printf("\nUSN : ");
		gets(s[i].acUsn);
		printf("\nMarks 1 : ");
		scanf("%d", &s[i].iMarks[0]);
		printf("\nMarks 2 : ");
		scanf("%d", &s[i].iMarks[1]);		
		printf("\nMarks 3 : ");
		scanf("%d", &s[i].iMarks[2]);
		getchar();

		s[i].fPercent = (s[i].iMarks[0] + s[i].iMarks[1] + s[i].iMarks[2])/3.0;

	}

	printf("%15s%4s%12s%4s%4s%4s%5s\n", "Name", "Age", "USN", "M1", "M2", "M3", "PER");
	for(i=0;i<iNum;i++)
	{
		printf("%15s%4d%12s%4d%4d%4d%5.2f\n",s[i].acName, s[i].iAge, s[i].acUsn, s[i].iMarks[0], s[i].iMarks[1], s[i].iMarks[2], s[i].fPercent);	
	}
	return 0;
}
