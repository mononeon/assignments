#include <stdio.h>

int main() {
    int n;
    long long sum = 0;

    // Prompt user to input the value of n
    printf("Enter the value of n: ");
    scanf("%d", &n);

    // Compute the sum of factorials
    for (int i = 1; i <= n; i++) {
        long long factorial = 1;
        for (int j = 1; j <= i; j++) {
            factorial *= j; // Compute i!
        }
        sum += factorial;
    }

    printf("The sum of the series is: %lld\n", sum);
    return 0;
}
