#include<stdio.h>
int main()
{
    int n = 0;
    printf("Enter number of Fibonacci Numbers to be printed: \n");
    scanf("%d", &n);
    int a = 0; int b = 1; int temp = 0;
    printf("%d", a);
    for(int i=1; i<n; i++){
        printf(" %d", b);
        temp = a;
        a = b; b = temp+b;
    }
    printf("\n");
    
    return 0;
}
