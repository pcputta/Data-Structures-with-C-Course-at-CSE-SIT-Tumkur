#include<stdio.h>
#define LENGTH 50

typedef struct{
	char cName[LENGTH];
	char cUSN[10];
	int iAge, iSemester;
	double dCGPA;
} student_t;

int main(void)
{
	student_t s1,s2,s3;

	s1.iAge = 22;

	printf("........");
	gets(s1.cName);

	printf("....Age.....");
	scanf("%d", &s1.iAge);



	
