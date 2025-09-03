/*
A positive integer is entered through the keyboard, write a C function to find the binary
equivalent of this number using recursion.
*/

#include <stdio.h>

int decimalToBinary(int n) {
    int result=0;
    result = n&1;
    if (n == 0) return 0;
    if (n == 1) return 1;
    return ( ( decimalToBinary(n>>1) * 10 ) + result );
}

int main() { 	 
    printf("Enter decimal integer: ");
    int n;  scanf("%d",&n);
    int result = decimalToBinary(n);
	printf("Binary equivalent of the number is: %d\n", result); 
	return 0; 
}
