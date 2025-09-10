/* 
Problem 1:
Write a program that will have an integer variable and a pointer (say, p) pointing to it. 
Also have a pointer to pointer pointing to p. Take the value for the integer variable 
and print it using p, and pp.
*/

#include <stdio.h>

int main() {
    int x;         // integer variable
    int *p;        // pointer to integer
    int **pp;      // pointer to pointer

    printf("Enter an integer: ");
    scanf("%d", &x);

    p = &x;
    pp = &p;

    printf("Using p = %d\n", *p);
    printf("Using pp = %d\n", **pp);

    return 0;
}