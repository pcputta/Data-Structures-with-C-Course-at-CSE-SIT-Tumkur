#include<stdio.h>
#include<stdlib.h>
//#include<conio.h>

FILE *fp;

main()
{
	int n=0,i,j,k;
	char a[30][30],temp[30],ptr,ch;
//	clrscr();

	fp=fopen("in.dat","r");
	if(fp==NULL)
	{
		printf("\nFile cannot be opened or doesn't exist");
		getchar();
		exit(0);
	}

	while(fscanf(fp,"%s",a[n++]) != EOF);
	fclose(fp);
	n--;
	printf("\n\t\t Sorting strigs by insetion sort. ");
	printf("\n\t\t====================================");
	for(j=1;j<n;j++)
	{
		printf("\n\n The Sorted Array is : ");
		strcpy(temp,a[j]);
		i=j-1;
		while((i>=0) && (strcmp(temp,a[i]) < 0))
		{
			strcpy(a[i+1],a[i]);
			i--;
		}
		strcpy(a[i+1],temp);
		for(k=0;k<=j;k++)
		printf("\n %s",a[k]);
		printf("\nPress any key.....");
		getchar();
	}
	printf("\n\n The Final sorted array is \n");
	for(j=0;j<n;j++)
		printf("\n%s",a[j]);

	fopen("out.dat","w");
	for(i=0;i<n;i++)
			fprintf(fp,"%s\n",a[i]);

	fclose(fp);
	getchar();
	return;

}









