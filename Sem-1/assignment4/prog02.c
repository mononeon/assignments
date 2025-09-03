/*
Write a recursive function which returns the sum of individual digits of a number passed as
argument.
*/

#include <stdio.h> 
int digitSum(int n){
    int result = n%10;
    if (n == 0) return 0;
    return ( digitSum(n/10) + result );
}
int main() 
{  	 
    printf("Enter decimal integer: ");
    int n;  scanf("%d",&n);
    int result = digitSum(n);
	printf("Digit sum is: %d\n", result); 
	return 0; 
}
