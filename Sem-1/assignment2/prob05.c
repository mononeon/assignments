#include <stdio.h>


int main() {
    int n;
    printf("Enter a value for n: ");
    scanf("%d", &n);
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += i*(i+1);
    }
    printf("The sum is: %d\n", sum);
    return 0;
}
