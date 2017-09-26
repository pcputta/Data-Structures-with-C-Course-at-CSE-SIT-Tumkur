#include <string.h>
#include <stdio.h>
#include <conio.h>


union address
{
	char a[20];
	char b[20];
	char c[20];
	char d[20];
};
//typedef address addr;
union address ad1;

int read()
{
	char *a,*b,*c;
	char s[30];

	printf("\nEnter the string\n");
	gets(s);
	printf("\n");
	puts(s);

	a=strtok(s,".");
	if(a)
		strcpy(ad1.a,a);
	printf("\nString is %s\n",ad1.a);

	a=strtok(NULL,".");
	if(a)
		strcpy(ad1.b,a);
	printf("\nString is %s\n",ad1.b);


	a=strtok(NULL,".");
	if(a)
		strcpy(ad1.c,a);
	printf("\nString is %s\n",ad1.c);

	a=strtok(NULL,".");
	if(a)
		strcpy(ad1.d,a);
	printf("\nString is %s\n",ad1.d);


	return 0;
}



int main()
{
	clrscr();
	read();
	getch();
	return 0;
}




