#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char **argv)
//int main(int argc, char *argv[])
{
    int i,j;
    char temp[40];
    
    printf("\n%d CmdLine arguments have been passed\n", argc);
    for(i=1;i<argc;i++)
    {
/*        strcpy(temp, argv[i]);*/
        for(j=strlen(argv[i])-1; j>=0; --j)
        {
/*            printf("%c", temp[j]);*/
            printf("%c", argv[i][j]);
            fflush(stdout);
            sleep(1);
            
        }
        printf("\n");
//        printf("CmdLine Arg %d is %s , length = %lu\n", i+1, argv[i], strlen(argv[i]));
    }
    return 0;
}


