#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct{
    unsigned emp_id;
    char emp_name[25];
    char emp_dept[25];
    unsigned emp_salary, emp_age;
}employee_t;

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
            case 1:
                    fnAddRecord();
                    break;

            case 2:
                    printf("\n Employee Details \n");
                    fnDisplayAllRecords();
                    break;

            case 3:
                    printf("\nEnter the emp_id that you want to search\n");
                    scanf("%d",&id);
                    fnSearchEmpID(id);
                    break;

            case 4:
                    printf("\nEnter the dept that you want to search\n");
                    scanf("%s",dept);
                    fnSearchEmpDept(dept);
                    break;

            case 5:
                    printf("\nEnter the salary that you want to search\n");
                    scanf("%d",&sal);
                    fnSearchEmpSal(sal);
                    break;

            case 6:
                    printf("\nEnter the age that you want to search\n");
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
	employee_t sEmp;
	FILE *fp;

	fp = fopen("emp.dat", "r");
	if(fp==NULL)
	{
	    printf("\nFile does not exist\n");
	    return;
	}
	while(fscanf(fp,"%d%s%s%d%d",&sEmp.emp_id, sEmp.emp_name, sEmp.emp_dept, &sEmp.emp_salary, &sEmp.emp_age)!=EOF)
	{
		printf("%d\t%s\t%s\t%d\t%d\n",sEmp.emp_id, sEmp.emp_name, sEmp.emp_dept, sEmp.emp_salary, sEmp.emp_age);
		iCount++;
	}
	if(0 == iCount)
		printf("\nNo Records found\n");
	fclose(fp);
}

void fnAddRecord()
{
	FILE *fp;
	employee_t wEmp;

    printf("\nEnter Employee details\n");
    printf("\nID : ");
    scanf("%d",&wEmp.emp_id);     getchar();
    printf("\nName : ");
    //gets(wEmp.emp_name);
    fgets(wEmp.emp_name, 25, stdin);
    printf("\nDept : ");
    //gets(wEmp.emp_dept);
    fgets(wEmp.emp_dept, 25, stdin);
    printf("\nSalary : ");
    scanf("%d",&wEmp.emp_salary);
    printf("\nAge : ");
    scanf("%d",&wEmp.emp_age);

	fp = fopen("emp.dat", "a");
	fprintf(fp,"%d\t%s\t%s\t%d\t%d\n",wEmp.emp_id, wEmp.emp_name, wEmp.emp_dept, wEmp.emp_salary, wEmp.emp_age);
	fclose(fp);
}

void fnSearchEmpID(int id)
{
	int iCount = 0;
	employee_t sEmp;
	FILE *fp;

	fp = fopen("emp.dat", "r");
	if(fp==NULL)
	{
	    printf("\nFile does not exist\n");
	    return;
	}
	while(fscanf(fp,"%d%s%s%d%d",&sEmp.emp_id, sEmp.emp_name, sEmp.emp_dept, &sEmp.emp_salary, &sEmp.emp_age)!=EOF)
	{
		if(sEmp.emp_id == id)
		{
			printf("%d\t%s\t%s\t%d\t%d\n",sEmp.emp_id, sEmp.emp_name, sEmp.emp_dept, sEmp.emp_salary, sEmp.emp_age);
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
	employee_t sEmp;
	FILE *fp;

	fp = fopen("emp.dat", "r");
	if(fp==NULL)
	{
	    printf("\nFile does not exist\n");
	    return;
	}
	while(fscanf(fp,"%d%s%s%d%d",&sEmp.emp_id, sEmp.emp_name, sEmp.emp_dept, &sEmp.emp_salary, &sEmp.emp_age)!=EOF)
	{
		if(sEmp.emp_salary == sal)
		{
			printf("%d\t%s\t%s\t%d\t%d\n",sEmp.emp_id, sEmp.emp_name, sEmp.emp_dept, sEmp.emp_salary, sEmp.emp_age);
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
	employee_t sEmp;
	FILE *fp;


	fp = fopen("emp.dat", "r");
	if(fp==NULL)
	{
	    printf("\nFile does not exist\n");
	    return;
	}
	while(fscanf(fp,"%d%s%s%d%d",&sEmp.emp_id, sEmp.emp_name, sEmp.emp_dept, &sEmp.emp_salary, &sEmp.emp_age)!=EOF)
	{
		if(!strcmp(sEmp.emp_dept, dept))
		{
			printf("%d\t%s\t%s\t%d\t%d\n",sEmp.emp_id, sEmp.emp_name, sEmp.emp_dept, sEmp.emp_salary, sEmp.emp_age);
			iCount++;
		}
	}
	if(0 == iCount)
		printf("\nNo Records found\n");
}

void fnSearchEmpAge(int age)
{
	int iCount = 0;
	employee_t sEmp;
	FILE *fp;

	fp = fopen("emp.dat", "r");
	if(fp==NULL)
	{
	    printf("\nFile does not exist\n");
	    return;
	}
	while(fscanf(fp,"%d%s%s%d%d",&sEmp.emp_id, sEmp.emp_name, sEmp.emp_dept, &sEmp.emp_salary, &sEmp.emp_age)!=EOF)
	{
		if(sEmp.emp_age == age)
		{
			printf("%d\t%s\t%s\t%d\t%d\n",sEmp.emp_id, sEmp.emp_name, sEmp.emp_dept, sEmp.emp_salary, sEmp.emp_age);
			iCount++;
		}
	}
	if(0 == iCount)
		printf("\nNo Records found\n");
}

