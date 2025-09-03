#include <stdio.h>
#include <stdlib.h>

void newtonForwardDifference(float *x, float *y, int n, float xp) {
    float **diffTable = (float **)malloc(n * sizeof(float *));
    for (int i = 0; i < n; i++) {
        diffTable[i] = (float *)malloc(n * sizeof(float));
        diffTable[i][0] = y[i];
    }
    
    for (int j = 1; j < n; j++) {
        for (int i = 0; i < n - j; i++) {
            diffTable[i][j] = diffTable[i + 1][j - 1] - diffTable[i][j - 1];
        }
    }
    
    float h = x[1] - x[0];
    float p = (xp - x[0]) / h;
    float result = y[0], term = 1;
    
    for (int i = 1; i < n; i++) {
        term *= (p - (i - 1)) / i;
        result += term * diffTable[0][i];
    }
    
    printf("Interpolated value at x = %f (Forward Difference): %f\n", xp, result);
    
    for (int i = 0; i < n; i++) free(diffTable[i]);
    free(diffTable);
}

void newtonBackwardDifference(float *x, float *y, int n, float xp) {
    float **diffTable = (float **)malloc(n * sizeof(float *));
    for (int i = 0; i < n; i++) {
        diffTable[i] = (float *)malloc(n * sizeof(float));
        diffTable[i][0] = y[i];
    }
    
    for (int j = 1; j < n; j++) {
        for (int i = n - 1; i >= j; i--) {
            diffTable[i][j] = diffTable[i][j - 1] - diffTable[i - 1][j - 1];
        }
    }
    
    float h = x[1] - x[0];
    float p = (xp - x[n - 1]) / h;
    float result = y[n - 1], term = 1;
    
    for (int i = 1; i < n; i++) {
        term *= (p + (i - 1)) / i;
        result += term * diffTable[n - 1][i];
    }
    
    printf("Interpolated value at x = %f (Backward Difference): %f\n", xp, result);
    
    for (int i = 0; i < n; i++) free(diffTable[i]);
    free(diffTable);
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
    
    if (xp <= x[n / 2]) {
        newtonForwardDifference(x, y, n, xp);
    } else {
        newtonBackwardDifference(x, y, n, xp);
    }
    
    free(x);
    free(y);
    
    return 0;
}
