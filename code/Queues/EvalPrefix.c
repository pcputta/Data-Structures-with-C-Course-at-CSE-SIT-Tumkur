    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    
    void fnPush(int [], int*, int);
    int fnPop(int [], int*);

    int main()
    {
        int iaStack[50], i, iRes, iOp1, iOp2, iTop = -1;
        char acPrefix[50], cSymb;
        
        
        
        
        printf("\nEnter a valid Prefix Expression \n");
        scanf("%s", acPrefix);
        
        for(i=strlen(acPrefix)-1; i>=0; --i)
        {
            cSymb = acPrefix[i];
            
            if(isdigit(cSymb))
            {
                fnPush(iaStack, &iTop, cSymb - '0');
            }
            else
            {
                iOp1 = fnPop(iaStack, &iTop);
                iOp2 = fnPop(iaStack, &iTop);
                switch(cSymb)
                {
                    case '+':   iRes = iOp1 + iOp2; break;
                    case '-':   iRes = iOp1 - iOp2; break;
                    case '*':   iRes = iOp1 * iOp2; break;
                    case '/':   iRes = iOp1 / iOp2; break;
                }
                fnPush(iaStack, &iTop, iRes);
            }
        }
        
        iRes = fnPop(iaStack, &iTop);
        printf("\nValue of %s is %d\n", acPrefix, iRes);
        return 0;        
    }
    
    void fnPush(int iaArr[], int *t, int val)
    {
        *t = *t + 1;
        iaArr[*t] = val;
    }
    
    int fnPop(int iaArr[], int *t)
    {
        int iElem;
        iElem = iaArr[*t];
        *t = *t - 1;
    }
    
    
