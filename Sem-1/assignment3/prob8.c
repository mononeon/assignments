#include <stdio.h>
#include <math.h>

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    double numbers[n]; double sum = 0; 
    double mean, variance = 0, stddev;

    printf("Enter the numbers:\n");
    for (int i = 0; i < n; i++) {
        scanf("%lf", &numbers[i]);
        sum += numbers[i];
    }

    mean = sum / n;

    for (int i = 0; i < n; i++) {
        variance += pow(numbers[i] - mean, 2);
    }
    variance /= n;
    stddev = sqrt(variance);

    printf("Standard Deviation: %.8lf\n", stddev);

    return 0;
}