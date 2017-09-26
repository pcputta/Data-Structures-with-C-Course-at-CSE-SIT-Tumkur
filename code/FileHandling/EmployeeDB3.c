#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct{
    unsigned emp_id;
    char emp_name[25];
    char emp_dept[25];
    unsigned emp_salary, emp_age;
}employee_t;

void fnAddRecord(employee_t);
void fnSearchEmpID(int);
void fnSearchEmpSal(int);
void fnSearchEmpDept(char[]);
void fnSearchEmpAge(int);
void fnDisplayAllRecords();

int main()
{
    employee_t e1;
    employee_t e[50];
    int iNum, i, id, sal, age;
	char dept[10];
	FILE *fp;

    printf("\nEnter the number of employees\n");
	scanf("%d", &iNum);

    printf("\nEnter details of %d employees\n", iNum);
	for(i=0;i<iNum;i++)
	{
		printf("Employee %d\n", i+1);
		printf("\nID : ");
		scanf("%d",&e1.emp_id);     getchar();
		printf("\nName : ");
		gets(e1.emp_name);     
		printf("\nDept : ");
		gets(e1.emp_dept);
		printf("\nSalary : ");
		scanf("%d",&e1.emp_salary);
		printf("\nAge : ");
		scanf("%d",&e1.emp_age);

		fnAddRecord(e1);
	}

	printf("\n Employee Details \n");
	fnDisplayAllRecords();

	printf("\nEnter the emp_id that you want to search\n");
	scanf("%d",&id);
	fnSearchEmpID(id);

	printf("\nEnter the salary that you want to search\n");
	scanf("%d",&sal);
	fnSearchEmpSal(sal);

	printf("\nEnter the dept that you want to search\n");
	scanf("%s",dept);
	fnSearchEmpDept(dept);

	printf("\nEnter the age that you want to search\n");
	scanf("%d",&age);
	fnSearchEmpAge(age);

    return 0;
}

void fnDisplayAllRecords()
{
	int iCount = 0;
	employee_t ep;
	FILE *fp;

	fp = fopen("emp.dat", "r");
	while(fscanf(fp,"%d%s%s%d%d",&ep.emp_id, ep.emp_name, ep.emp_dept, &ep.emp_salary, &ep.emp_age)!=EOF)
	{	
		printf("%d\t%s\t%s\t%d\t%d\n",ep.emp_id, ep.emp_name, ep.emp_dept, ep.emp_salary, ep.emp_age);
		iCount++;
	}
	if(0 == iCount)
		printf("\nNo Records found\n");
	fclose(fp);
}

void fnAddRecord(employee_t emp)
{
	FILE *fp;
	fp = fopen("emp.dat", "a");
	fprintf(fp,"%d\t%s\t%s\t%d\t%d\n",emp.emp_id, emp.emp_name, emp.emp_dept, emp.emp_salary, emp.emp_age);
	fclose(fp);
}

void fnSearchEmpID(int id)
{
	int iCount = 0;
	employee_t ep;
	FILE *fp;

	fp = fopen("emp.dat", "r");
	while(fscanf(fp,"%d%s%s%d%d",&ep.emp_id, ep.emp_name, ep.emp_dept, &ep.emp_salary, &ep.emp_age)!=EOF)
	{	
		if(ep.emp_id == id)
		{
			printf("%d\t%s\t%s\t%d\t%d\n",ep.emp_id, ep.emp_name, ep.emp_dept, ep.emp_salary, ep.emp_age);
			iCount++;
		}
	}
	if(0 == iCount)
		printf("\nNo Records found\n");
	fclose(fp);
}

void fnSearchEmpSal(int sal)
{
	int iCount = 0;
	employee_t ep;
	FILE *fp;

	fp = fopen("emp.dat", "r");
	while(fscanf(fp,"%d%s%s%d%d",&ep.emp_id, ep.emp_name, ep.emp_dept, &ep.emp_salary, &ep.emp_age)!=EOF)
	{	
		if(ep.emp_salary == sal)
		{
			printf("%d\t%s\t%s\t%d\t%d\n",ep.emp_id, ep.emp_name, ep.emp_dept, ep.emp_salary, ep.emp_age);
			iCount++;
		}
	}
	if(0 == iCount)
		printf("\nNo Records found\n");
	fclose(fp);
}

void fnSearchEmpDept(char dept[])
{
	int iCount = 0;
	employee_t ep;
	FILE *fp;


	fp = fopen("emp.dat", "r");
	while(fscanf(fp,"%d%s%s%d%d",&ep.emp_id, ep.emp_name, ep.emp_dept, &ep.emp_salary, &ep.emp_age)!=EOF)
	{	
		if(!strcmp(ep.emp_dept, dept))
		{
			printf("%d\t%s\t%s\t%d\t%d\n",ep.emp_id, ep.emp_name, ep.emp_dept, ep.emp_salary, ep.emp_age);
			iCount++;
		}
	}
	if(0 == iCount)
		printf("\nNo Records found\n");
}

void fnSearchEmpAge(int age)
{
	int iCount = 0;
	employee_t ep;
	FILE *fp;

	fp = fopen("emp.dat", "r");
	while(fscanf(fp,"%d%s%s%d%d",&ep.emp_id, ep.emp_name, ep.emp_dept, &ep.emp_salary, &ep.emp_age)!=EOF)
	{	
		if(ep.emp_age == age)
		{
			printf("%d\t%s\t%s\t%d\t%d\n",ep.emp_id, ep.emp_name, ep.emp_dept, ep.emp_salary, ep.emp_age);
			iCount++;
		}
	}
	if(0 == iCount)
		printf("\nNo Records found\n");
}

