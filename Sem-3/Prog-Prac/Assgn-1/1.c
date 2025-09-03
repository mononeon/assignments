#include<stdio.h>

int main() {
    int x, *p, **pp;
    printf("Enter an integer: ");
    scanf("%d", &x);
    p = &x;
    pp = &p;
    printf("Using p = %d\n", *p);
    printf("Using pp = %d\n", **pp);
    return 0;
}