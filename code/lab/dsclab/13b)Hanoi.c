#include <stdio.h>										/*CPP*/
//#include <conio.h>
int Count = 0;
void towers(int, char, char, char);

main()
{

	int n;

//	clrscr();

	printf("\nTOWER OF HANOI\n");
	printf("==================");
	printf("\nEnter number of disks\n");
	scanf("%d",&n);

	towers(n,'A','C','B');
	printf("\nTotal number of steps required to shift all disks is %d",Count);
	getchar();

}

void towers( int n, char frompeg, char topeg, char auxpeg)
{
     Count++;

	if(n == 1)/*If single disk make move and exit*/
	{
		printf("\n%s%c%s%c\n","move disk 1 from peg ",frompeg," to peg ",topeg);
		return;
	}/*end if*/

	/*move top n-1 disks from A to B using C as auxilary*/
	towers(n-1,frompeg,auxpeg,topeg);

	printf("\n%s%d%s%c%s%c\n","move disk ",n," from peg ",frompeg," to peg ",topeg);

	/*move top n-1 disks from B to C using A as auxilary*/
	towers(n-1,auxpeg,topeg,frompeg);
}



/*CPP*/
