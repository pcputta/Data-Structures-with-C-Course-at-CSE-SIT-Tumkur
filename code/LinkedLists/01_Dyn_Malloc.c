#include <stdio.h>
#include <stdlib.h>
int main()
{
    float *fPtr;
    int *iPtr;

    fPtr = (float*)malloc(sizeof(float));    
    iPtr = (int*)malloc(sizeof(int));    

    printf("\nEnter a float value\n");
    scanf("%f",fPtr);

    printf("\nEnter a float value\n");
    scanf("%d",iPtr);
    
    printf("\nFloat value = %f\n", *fPtr);
    printf("\nInteger value = %d\n", *iPtr);
    
    free(fPtr);
    free(iPtr);
    
    return 0;    
}

