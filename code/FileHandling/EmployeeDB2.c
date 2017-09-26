#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct{
    unsigned emp_id;
    char emp_name[25];
    char emp_dept[25];
    unsigned emp_salary, emp_age;
}employee_t;

void fnAddRecord(employee_t, FILE*);
void fnSearchEmpID(employee_t [], int, int);
void fnSearchEmpSal(employee_t [], int, int);
void fnSearchEmpDept(employee_t [], char[], int);
void fnSearchEmpAge(employee_t [], int, int);

int main()
{
    employee_t e1;
    employee_t e[50];
    int iNum, i, id, sal, age;
	char dept[10];
	FILE *fp;

	fp = fopen("emp.dat", "a");

    printf("\nEnter the number of employees\n");
	scanf("%d", &iNum);

    printf("\nEnter details of %d employees\n", iNum);
	for(i=0;i<iNum;i++)
	{
		printf("Employee %d\n", i+1);
		printf("\nID : ");
		scanf("%d",&e1.emp_id);     getchar();
		printf("\nName : ");
		gets(e1.emp_name);     getchar();
		printf("\nDept : ");
		gets(e1.emp_dept);
		printf("\nSalary : ");
		scanf("%d",&e1.emp_salary);
		printf("\nAge : ");
		scanf("%d",&e1.emp_age);

		fnAddRecord(e1,fp);
	}
	fclose(fp);
	fp = fopen("emp.dat", "r");
	i=0;
    while(fscanf(fp,"%d%s%s%d%d",&e[i].emp_id, e[i].emp_name, e[i].emp_dept, &e[i].emp_salary, &e[i].emp_age)!=EOF)
	{
		printf("%d\t%s\t%s\t%d\t%d\n",e[i].emp_id, e[i].emp_name, e[i].emp_dept, e[i].emp_salary, e[i].emp_age);
		i++;
	}
	iNum = i;
	printf("\nEnter the emp_id that you want to search\n");
	scanf("%d",&id);
	fnSearchEmpID(e, id, iNum);

	printf("\nEnter the salary that you want to search\n");
	scanf("%d",&sal);
	fnSearchEmpSal(e, sal, iNum);

	printf("\nEnter the dept that you want to search\n");
	scanf("%s",dept);
	fnSearchEmpDept(e, dept, iNum);

	printf("\nEnter the age that you want to search\n");
	scanf("%d",&age);
	fnSearchEmpAge(e, age, iNum);

	fclose(fp);
    return 0;
}

void fnAddRecord(employee_t emp, FILE *fp)
{
	fprintf(fp,"%d\t%s\t%s\t%d\t%d\n",emp.emp_id, emp.emp_name, emp.emp_dept, emp.emp_salary, emp.emp_age);
}

void fnSearchEmpID(employee_t e[], int id, int n)
{
	int i, iCount = 0;
	for(i=0;i<n;++i)
	{
		if(e[i].emp_id == id)
		{
			printf("%d\t%s\t%s\t%d\t%d\n",e[i].emp_id, e[i].emp_name, e[i].emp_dept, e[i].emp_salary, e[i].emp_age);
			iCount++;
		}
	}
	if(0 == iCount)
		printf("\nNo Records found\n");
}

void fnSearchEmpSal(employee_t e[], int sal, int n)
{
	int i, iCount = 0;
	for(i=0;i<n;++i)
	{
		if(e[i].emp_salary == sal)
		{
			printf("%d\t%s\t%s\t%d\t%d\n",e[i].emp_id, e[i].emp_name, e[i].emp_dept, e[i].emp_salary, e[i].emp_age);
			iCount++;
		}
	}
	if(0 == iCount)
		printf("\nNo Records found\n");
}

void fnSearchEmpDept(employee_t e[], char dept[], int n)
{
	int i, iCount = 0;
	for(i=0;i<n;++i)
	{
		if(!strcmp(e[i].emp_dept, dept))
		{
			printf("%d\t%s\t%s\t%d\t%d\n",e[i].emp_id, e[i].emp_name, e[i].emp_dept, e[i].emp_salary, e[i].emp_age);
			iCount++;
		}
	}
	if(0 == iCount)
		printf("\nNo Records found\n");
}

void fnSearchEmpAge(employee_t e[], int age, int n)
{
	int i, iCount = 0;
	for(i=0;i<n;++i)
	{
		if(e[i].emp_age == age)
		{
			printf("%d\t%s\t%s\t%d\t%d\n",e[i].emp_id, e[i].emp_name, e[i].emp_dept, e[i].emp_salary, e[i].emp_age);
			iCount++;
		}
	}
	if(0 == iCount)
		printf("\nNo Records found\n");
}

