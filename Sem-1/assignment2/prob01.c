#include <stdio.h>


int main() {
    int n;
    printf("Enter a value for n: ");
    scanf("%d", &n);
    printf("Integers divisible by %d between 1 and 100:\n", n);
    for (int i = 1; i <= 100; i++) {
        if (i % n == 0) {
            printf("%d ", i);
        }
    }
    return 0;
}
