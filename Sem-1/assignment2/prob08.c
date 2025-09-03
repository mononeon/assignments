#include <stdio.h>

int sumOfFactors(int num) {
    int sum = 0;
    for (int i = 1; i <= num; i++) {
        if (num % i == 0) {
            sum += i;
        }
    }
    return sum;
}

int main() {
    int n, total_sum = 0;

    // Prompt user to input the value of n
    printf("Enter the value of n: ");
    scanf("%d", &n);

    // Compute the sum of the series
    for (int i = 1; i <= n; i++) {
        total_sum += sumOfFactors(i); // Calculate i@
    }

    printf("The sum of the series is: %d\n", total_sum);
    return 0;
}
