#include <stdio.h>
#include <stdlib.h>

float lagrangeInterpolation(float *x, float *y, int n, float xp) {
    float result = 0.0;
    for (int i = 0; i < n; i++) {
        float term = y[i];
        for (int j = 0; j < n; j++) {
            if (i != j) {
                term *= (xp - x[j]) / (x[i] - x[j]);
            }
        }
        result += term;
    }
    return result;
}

int main() {
    FILE *file = fopen("data_points.txt", "r");
    if (!file) {
        printf("Error opening file!\n");
        return 1;
    }

    int n;
    fscanf(file, "%d", &n);
    float *x = (float *)malloc(n * sizeof(float));
    float *y = (float *)malloc(n * sizeof(float));
    
    for (int i = 0; i < n; i++) {
        fscanf(file, "%f %f", &x[i], &y[i]);
    }
    fclose(file);
    
    float xp;
    printf("Enter interpolation point: ");
    scanf("%f", &xp);
    
    float result = lagrangeInterpolation(x, y, n, xp);
    printf("Interpolated value at x = %f: %f\n", xp, result);
    
    free(x);
    free(y);
    
    return 0;
}
