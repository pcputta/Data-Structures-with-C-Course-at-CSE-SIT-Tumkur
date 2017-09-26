/***************************************************************************
*File		: 15CalStrLen.c
*Description	: Program to calculate length of a string without
*                   using built in function
*Author		: Prabodh C P
*Compiler	: gcc compiler, Ubuntu 10.04
*Date		: 4 July 2012
***************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

int fnMyStrLen(char []);
/***************************************************************************
*Function	: main
*Input parameters: void
*RETURNS	:	0 on success
***************************************************************************/

int main(void)
{
    char acInStr[100];
    int iLen;

	printf("\nEnter the sentence whose length has to be measured\n");
	gets(acInStr);

	for(iLen = 0; acInStr[iLen] != '\0'; iLen++);

	printf("\n Length of the string without using built in function is %d\n",iLen);
	iLen = strlen(acInStr);
	printf("\n Length of the string using built in function is %d\n",iLen);

	iLen = fnMyStrLen(acInStr);	
	printf("\n Length of the string using user defined function is %d\n",iLen);

	return 0;
}

int fnMyStrLen(char str[])
{
	int i;
	for(i = 0; str[i] != '\0'; i++);

	return i;
}
