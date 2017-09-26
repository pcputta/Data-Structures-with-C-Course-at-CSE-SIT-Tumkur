#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

int main(int argc, char **argv)
{
    bool isValid = true;
    int i, idigCount=0;
    char ch;
    
    if(argc < 2)
    {
        printf("\nInvalid Usage");
        printf("Usage Format : ./a.out <passwd>");
        exit(0);
    }
    
    if(strlen(argv[1])<8)
    {
        isValid = false;
    }
    
    if(isValid)
    {
        for(i=0;argv[1][i] != '\0'; i++)
        {
            ch = argv[1][i];
            if(!isalnum(ch))
            {
                isValid = false;
                break;
            }
        }
    }

    if(isValid)
    {
        for(i=0;argv[1][i] != '\0'; i++)
        {
            ch = argv[1][i];
            if(isdigit(ch))
            {
                idigCount++;
            }
        }
        if(idigCount <2)
        {
            isValid = false;
        }
    }

    if(isValid)
        printf("%s is a valid password", argv[1]);
    else
        printf("%s is not a valid password", argv[1]);

    return 0;
}
