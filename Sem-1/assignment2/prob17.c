#include<stdio.h>

int checkArmstrong(int n){
    int temp = n;
    int digit, sum = 0;
    while(temp!=0){
        digit = temp%10;
        temp/=10;
        sum += digit * digit * digit;
    }
    
    return (n==sum);
}

int main()
{
    int MAX = 500;
    
    printf("The Armstrong numbers less than %d: ", MAX);
    for(int i=1; i<=MAX; i++){
        if (checkArmstrong(i)){
            printf("%d ", i);
        }
    }
    printf("\n");
    
    return 0;
}
