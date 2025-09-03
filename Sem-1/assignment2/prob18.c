
#include <stdio.h>


int digitSquareSum(int n)
{
    int squareSum = 0;
    while (n) {
        squareSum += (n % 10) * (n % 10);
        n /= 10;
    }
    return squareSum;
}


int isHappynumber(int n)
{
    for(int i=0; i<100; i++){
        n = digitSquareSum(n);
        if (n==1){
            return 1;
        }
    }
    return 0;
}

int main()
{
    int MAX = 100;
    printf("The first %d Happy Numbers are: ", MAX);
    int count = 0, i=1;
    while(count<MAX){
        if (isHappynumber(i)){
            printf("%d ", i);
            count++;
        }
        i++;
    }
    
}
