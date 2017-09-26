#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef union{
	bool hasPhone;
	char PhNo[12];
}telephone_t;

typedef struct{
	int iDNo;
	char st_name[20];
	char city[20];
	int PIN;
	telephone_t ph;
}address_t;

int main()
{
	address_t addr1, addr2;
	char option;
	printf("\nEnter the first address\n");
	printf("\nDoor No		: ");	scanf("%d", &addr1.iDNo);
	printf("\nStreet Name	: ");	scanf("%s", addr1.st_name);
	printf("\nCity		: ");	scanf("%s", addr1.city);
	printf("\nPIN		: ");	scanf("%d", &addr1.PIN);	getchar();
	printf("\nPhone	(Y/N)	: ");	scanf("%c", &option);
	if(option == 'Y' || option == 'y')
	{
		printf("\nEnter Phone No: ");	scanf("%s",addr1.ph.PhNo);
	}
	else
	{
		addr1.ph.hasPhone = false;
	}
	
	printf("\nAddress Details : ");
	
	printf("\nDoor No		: %d", addr1.iDNo);
	printf("\nStreet Name	: %s", addr1.st_name);
	printf("\nCity		: %s", addr1.city);
	printf("\nPIN		: %d", addr1.PIN);	
	if(addr1.ph.hasPhone != false)
		printf("\nPhone		: %s\n", addr1.ph.PhNo);
	printf("\n");
	return 0;	
}
