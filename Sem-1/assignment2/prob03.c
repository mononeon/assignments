#include<stdio.h>

int main(){
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    int reverse = 0;
    while(n>0){
        reverse*= 10; reverse += n%10; n/=10;
    }
    printf("Reverse of the number: %d\n", reverse);
}