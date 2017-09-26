typedef struct{
	char name[30];
	char USN[10];
	int m1,m2,m3;
	int total;
}student_t;

void fnDispHigh(student_t [], int);

void fnDispHigh(student_t s[], int iNum)
{
	int max_total = 0, iMaxPos = 0;
	for(i=0;i<iNum;i++)
	{
		if(s[i].total > max_total)
		{
			max_total = s[i].total;
			iMaxPos = i;
		}
	}

	printf("\nThe details of highest scoring student is\n");



}

