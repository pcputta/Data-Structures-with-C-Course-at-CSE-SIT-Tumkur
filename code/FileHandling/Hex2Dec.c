#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

int fnConvert(char);

int main(int argc, char **argv)
{
    int iDeciVal = 0, i;
    char acHexVal[50], cDigit;
    
    
    if(argc < 2)    
    {
        printf("\nInvalid Usage");
        printf("Usage Format : ./a.out <Hexadecimal>");
        exit(0);
    }
    
    strcpy(acHexVal, argv[1]);
    
    for(i=0;i<strlen(acHexVal);i++)
    {
        cDigit = acHexVal[i];
        cDigit = toupper(cDigit);
        if((cDigit >= 'A' && cDigit<='F') || (cDigit >= '0' && cDigit<='9'))
        {
            iDeciVal = iDeciVal * 16 + fnConvert(cDigit);
        }
        else
        {
            printf("\nInvalid Input\n");
            exit(0);
        }
    }

    printf("\n%s in decimal is %d\n", acHexVal, iDeciVal);
    return 0;
}

int fnConvert(char cDig)
{
    if(cDig >='A' && cDig <='F')
        return (cDig - 'A' + 10);
    else
        return (cDig - '0');
}
