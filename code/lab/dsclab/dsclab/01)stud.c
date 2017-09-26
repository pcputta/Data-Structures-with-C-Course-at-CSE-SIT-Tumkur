#include<stdio.h>
#include<stdlib.h>
//#include<conio.h>

struct student
{
	int usn;
	char name[26];
	int sub1;
	int sub2;
	int sub3;
};

struct student Std;
FILE *fp;

main()
{
	int ch;
//	clrscr();
	printf("Student Database Program\n");
	while(1)
	{
		printf("\n\tThe Student Database Menu");
		printf("\n\t============================");
		printf("\n\t 1. Add Record");
		printf("\n\t 2. Search Record");
		printf("\n\t 3. Display All");
		printf("\n\t 4. Exit");
		printf("\n\t Enter your choice : ");
		scanf("%d",&ch);

		switch(ch)
		{
			case 1: add_record();
					break;
			case 2:	search_record();
					break;
			case 3: display_all();
					break;
			case 4: exit(0);

			default: printf("\nWrong choice");
		}

	}

}


add_record()
{
	printf("Enter the USN of the Student: ");
	scanf("%d",&Std.usn);
	if(Std.usn < 1)
	{
		printf("\n Not a valid USN");
		getchar();
		return;
	}
	printf("\nEnter the Name : ");
	scanf("%s",Std.name);
	printf("\nEnter the  Marks of Subject[1] : ");
	scanf("%d",&Std.sub1);
	printf("\nEnter the  Marks of Subject[2] : ");
	scanf("%d",&Std.sub2);
	printf("\nEnter the  Marks of Subject[3] : ");
	scanf("%d",&Std.sub3);

	if(Std.sub1<0 || Std.sub2<0 || Std.sub3<0)
	{
		printf("\nMarks cannot be negative");
		
		getchar();
		return;
	}

	fp = fopen("student.dat","a+");
	fprintf(fp,"%d %s %d %d %d ",Std.usn,Std.name,Std.sub1,Std.sub2,Std.sub3);

	fclose(fp);
	return;

}

search_record()
{
	int flag=0,item;
	char name[26];
	printf("\nEnter the USN of the student :");
	scanf("%d",&item);
	fp=fopen("student.dat","r");
	if(fp==NULL)
	{
		printf("\nFile cannot be opened or doesn't exist\n");
		getchar();
		return;
	}

	while(fscanf(fp,"%d %s %d %d %d",&Std.usn,Std.name,&Std.sub1,&Std.sub2,&Std.sub3)!=EOF)
	{
		if(item == Std.usn)
		{
			printf("\n USN	     Name	Sub1	Sub2	Sub3");
			printf("\n===================================================\n");
			printf("%4d %12s %8d %8d %8d",Std.usn,Std.name,Std.sub1,Std.sub2,Std.sub3);
			printf("\n\n");
			flag = 1;
		}
	}

	if(flag == 0)
	printf("\n\t Requested Record not found !\n");
	fclose(fp);
	return;

}

display_all()
{
	fp=fopen("student.dat","r");
	if(fp==NULL)
	{
		printf("\nFile cannot be opened or does not exist.\n");
		getchar();
		return;
	}
	printf("\n USN	     Name	Sub1	Sub2	Sub3");
	printf("\n===================================================\n");
	while(fscanf(fp,"%d %s %d %d %d",&Std.usn,Std.name,&Std.sub1,&Std.sub2,&Std.sub3)!=EOF)
	{
		printf("\n%4d %12s %8d %8d %8d",Std.usn,Std.name,Std.sub1,Std.sub2,Std.sub3);
	}
	printf("\n\n");
	return;

}










