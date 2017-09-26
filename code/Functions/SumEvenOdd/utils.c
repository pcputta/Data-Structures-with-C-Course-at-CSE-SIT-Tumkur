/*Licensed under GNU GPL*/
void fnSumEvenOdd(int iaArray[], int n)
{
    int iOddSum = 0, iEvenSum = 0,i;
    for(i=0;i<n;i++)
    {
        if(0 == iaArray[i]%2)
            iEvenSum += iaArray[i];
        else
            iOddSum += iaArray[i];
    }

    printf("\nThe Sum of Even numbers is %d\n",iEvenSum);
    printf("\nThe Sum of Odd numbers is %d\n",iOddSum);
}
