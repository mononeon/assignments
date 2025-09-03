#include <stdio.h>

int is_prime(int num) {
    if (num < 2) return 0; // Numbers less than 2 are not prime
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return 0; // Divisible by another number
    }
    return 1;
}

int main() {
    printf("Prime numbers between 1 and 100 are:\n");
    for (int i = 1; i <= 100; i++) {
        if (is_prime(i)) {
            printf("%d ", i);
        }
    }
    printf("\n");
    return 0;
}
