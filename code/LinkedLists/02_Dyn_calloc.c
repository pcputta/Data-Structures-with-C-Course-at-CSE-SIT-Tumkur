#include <stdio.h>
#include <stdlib.h>
int main()
{
    float *fpMarks;
    int iNum, i, iMore;
    
    printf("\nHow many students are there\n");
    scanf("%d",&iNum);
    
    fpMarks = (float*)calloc(iNum, sizeof(float));

    printf("%lu bytes memory allocated\n", sizeof(float)*iNum);
    
    printf("\nEnter %d marks\n", iNum);
    for(i=0;i<iNum;i++)
    {
        scanf("%f",fpMarks+i);
    }
    printf("\nEntered marks\n");
    for(i=0;i<iNum;i++)
    {
        printf("%0.2f\n",*(fpMarks+i));
    }
    
    free(fpMarks);
    return 0;    
}

