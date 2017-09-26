/*#include <libexplain/putw.h>*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    FILE *fp;
    int iaArr[10], iNum, i, iVal;
    printf("\nEnter how many values you want to generate\n");
    scanf("%d", &iNum);

    fp = fopen("values.dat", "w");

    srand(time(NULL));
    for(i=0;i<iNum;i++)
    {
//        iVal = rand()%100;
        iaArr[i] = (int)getw(fp);
    }

/*    srand(time(NULL));*/
    for(i=0;i<iNum;i++)
    {
		scanf("%d", &iVal);
		putw(iVal, fp);
		fputc('#',fp);
/*		if (putw(iVal, fp) < 0)*/
/*		{*/
/*			int err = errno;*/
/*			fprintf(stderr, "%s\n", explain_errno_putw(err, value, fp)); */
/*			exit(EXIT_FAILURE);*/
/*		}*/


    }

    fclose(fp);
    return 0;
}

