	#include <stdio.h>
	#include <stdlib.h>
	#include <math.h>
	void 

	int main()
	{
	    double daArr[10], dMean = 0.0, dVar = 0.0, dSd;
	    int i,iNum;
	    printf("\nEnter no of elements in the Array\n");
	    scanf("%d",&iNum);

	    printf("\nEnter %d elements in the Array\n",iNum);
	    for(i=0;i<iNum;++i)
	    {
		scanf("%lf",&daArr[i]);
		dMean += daArr[i];
	    }
	//    dMean /= iNum;
	    dMean = dMean / iNum;

	    for(i=0;i<iNum;++i)
	    {
		dVar += (daArr[i] - dMean) * (daArr[i] - dMean);
	    }
	//    dVar /= iNum;
	    dVar = dVar / iNum;
	    dSd = sqrt(dVar);

	    printf("\nElements of Array A:\n");
	    for(i=0;i<iNum;++i)
	    {
		printf("%lf\t",daArr[i]);
	    }
	    printf("\n");
	    printf("\nMean = %lf\n",dMean);
	    printf("\nVariance = %lf\n",dVar);
	    printf("\nStandard Deviation = %lf\n",dSd);
	    return 0;
	}

