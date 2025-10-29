#include <stdio.h>

double tax(double income, double rate) {
    if(rate <= 0) rate = 0.10; // default 10%
    return income * rate;
}

int main() {
    printf("Tax (default 10%%): %.2f\n", tax(50000, 0));
    printf("Tax (20%%): %.2f\n", tax(50000, 0.20));
    return 0;
}
