#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct{
	unsigned emp_id;
	char emp_name[25];
	char emp_dept[25];
	unsigned emp_salary, emp_age;
}employee_t;

/* FUNCTION PROTOTYPES */
void fnAddRecord(void);
void fnSearchEmpID(int);
void fnSearchEmpSal(int);
void fnSearchEmpDept(char[]);
void fnSearchEmpAge(int);
void fnDisplayAllRecords(void);

int main()
{
	int id, sal, age, iChoice;
	char dept[10];

	for(;;)
	{
		printf("\n1.Add Record\n2.Display Records\n3.Search Employee by ID\n");
		printf("4.Search Employee by Dept\n5.Search Employee by salary\n");
		printf("6.Search Employee by Age\n7.Exit");
		printf("\nEnter your choice : ");
		scanf("%d",&iChoice);

		switch(iChoice)
		{
	        case 1: fnAddRecord();
	                break;

	        case 2: printf("\n Employee Details \n");
	                fnDisplayAllRecords();
	                break;

	        case 3: printf("\nEnter the emp_id that you want to search\n");
	                scanf("%d",&id);
	                fnSearchEmpID(id);
	                break;

	        case 4: printf("\nEnter the dept that you want to search\n");
	                scanf("%s",dept);
	                fnSearchEmpDept(dept);
	                break;

	        case 5: printf("\nEnter the salary that you want to search\n");
	                scanf("%d",&sal);
	                fnSearchEmpSal(sal);
	                break;

	        case 6: printf("\nEnter the age that you want to search\n");
	                scanf("%d",&age);
	                fnSearchEmpAge(age);
	                break;
	                
	        case 7: exit(0);
		}
	}
	return 0;
}

void fnDisplayAllRecords()
{
	int iCount = 0;
	employee_t ep;
	FILE *fp;

	fp = fopen("emp.dat", "r");
	if(fp==NULL)
	{
		printf("\nFile does not exist\n");
		return;
	}
	printf("\nID\tName\tDept\tSalary\tAge\n");
	while(fscanf(fp,"%d%s%s%d%d",&ep.emp_id, ep.emp_name, ep.emp_dept, &ep.emp_salary, &ep.emp_age)!=EOF)
	{
		printf("%d\t%s\t%s\t%d\t%d\n",ep.emp_id, ep.emp_name, ep.emp_dept, ep.emp_salary, ep.emp_age);
		iCount++;
	}
	if(0 == iCount)
		printf("\nNo Records found\n");
	fclose(fp);
}

void fnAddRecord()
{
	FILE *fp;
	employee_t emp;

	printf("\nEnter Employee details\n");
	printf("\nID : ");
	scanf("%d", &emp.emp_id);     getchar();
	printf("\nName : ");
	scanf("%s", emp.emp_name);
	printf("\nDept : ");
	scanf("%s", emp.emp_dept);
	printf("\nSalary : ");
	scanf("%d", &emp.emp_salary);
	printf("\nAge : ");
	scanf("%d", &emp.emp_age);

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
	if(fp==NULL)
	{
		printf("\nFile does not exist\n");
		return;
	}
	printf("\nID\tName\tDept\tSalary\tAge\n");
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
	if(fp==NULL)
	{
		printf("\nFile does not exist\n");
		return;
	}
	printf("\nID\tName\tDept\tSalary\tAge\n");
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
	if(fp==NULL)
	{
		printf("\nFile does not exist\n");
		return;
	}
	printf("\nID\tName\tDept\tSalary\tAge\n");
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
	if(fp==NULL)
	{
		printf("\nFile does not exist\n");
		return;
	}
	printf("\nID\tName\tDept\tSalary\tAge\n");
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

