/***************************************************************************
*File		: 12TraceNormalMatrix
*Description	: Program to find trace and normal of a matrix
*Author		: Prabodh C P
*Compiler	: gcc compiler, Ubuntu 10.04
*Date		: 4 July 2012
***************************************************************************/

#include <stdio.h>
#include <stdlib.h>

void fnMatTraceNorm(int [][10],int);

/***************************************************************************
*Function	: 	main
*Input parameters:	no parameters
*RETURNS	:	0 on success
***************************************************************************/

int main(void)
{
    int iaSqMat[10][10],iNum,i,j;


    printf("\nEnter the order of the Square Matrix\n");
    scanf("%d",&iNum);

    printf("\nEnter the values\n");
    for(i=0;i<iNum;i++)
    {
        for(j=0;j<iNum;j++)
        {
            scanf("%d",&iaSqMat[i][j]);
        }
    }

    fnMatTraceNorm(iaSqMat,iNum);


    return 0;
}

void fnMatTraceNorm(int iaMat[][10],int n)
{
    int iTrace=0,iNorm=0,i,j;

//    printf("\nvalue of n = %d\n",n);
    printf("\nMatrix is\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d\t",iaMat[i][j]);
        }
        printf("\n");
    }


    for(i=0;i<n;i++)
    {
        iTrace += iaMat[i][i];
    }

    for(i=n-1;i>=0;i--)
    {
        for(j=0;j<n;j++)
        {
            if(n-1 == i+j)
            {
                iNorm += iaMat[i][j];
            }
        }
    }

    printf("\nThe Trace of the Square Matrix is %d\n",iTrace);
    printf("\nThe Normal of the Square Matrix is %d\n",iNorm);

}




/*
	2	4	5
	6	7	8
	1	2	3



	A00	A01	A02
	A10	A11	A12
	A20	A21	A22
*/
