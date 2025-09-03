#include<stdio.h>
int main()
{
    int len = 10;
    int a[len];
    printf("Enter %d Numbers: \n", len);
    for(int i=0; i<len; i++)
        scanf("%d", &a[i]);
    int countPositive = 0; int countNegative = 0; int countZero = 0;
    for(int i=0; i<len; i++)
    {
        if(a[i]<0)
            countNegative++;
        else if(a[i]>0)
            countPositive++;
        else
            countZero++;
    }
    printf("\nOccurrence of");
    printf("\nPositive Numbers = %d times", countPositive);
    printf("\nNegative Numbers = %d times", countNegative);
    printf("\nZero = %d times\n", countZero);
    return 0;
}
