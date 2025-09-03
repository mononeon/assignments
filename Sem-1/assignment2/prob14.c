#include <stdio.h>
#include <math.h>

int main() {
    double number, base, result;

    // Prompt user to input the number
    printf("Enter a number: ");
    scanf("%lf", &number);

    // Prompt user to input the base
    printf("Enter the log base: ");
    scanf("%lf", &base);

    if (base <= 0 || base == 1 || number <= 0) {
        printf("Invalid input.\n");
    } else {
        result = log(number) / log(base); // Change of base formula
        printf("Logarithm of %.2lf with base %.2lf is: %.5lf\n", number, base, result);
    }

    return 0;
}
