#include <stdio.h>

int is_prime(int num) {
    if (num < 2) return 0;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return 0;
    }
    return 1;
}

int main() {
    int n;

    // Prompt user to input the number
    printf("Enter a number: ");
    scanf("%d", &n);

    printf("Prime factors of %d are:\n", n);

    for (int i = 2; i <= n; i++) {
        if (n % i == 0 && is_prime(i)) {
            printf("%d ", i);
        }
    }

    printf("\n");
    return 0;
}
