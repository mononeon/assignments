#include <stdio.h>
#include <stdlib.h>

void newtonDividedDifference(float *x, float *y, int n, float xp) {
    float **divDiff = (float **)malloc(n * sizeof(float *));
    for (int i = 0; i < n; i++) {
        divDiff[i] = (float *)malloc(n * sizeof(float));
        divDiff[i][0] = y[i];
    }

    for (int j = 1; j < n; j++) {
        for (int i = 0; i < n - j; i++) {
            divDiff[i][j] = (divDiff[i+1][j-1] - divDiff[i][j-1]) / (x[i+j] - x[i]);
        }
    }

    float result = divDiff[0][0];
    float term = 1;
    for (int i = 1; i < n; i++) {
        term *= (xp - x[i-1]);
        result += divDiff[0][i] * term;
    }

    printf("Interpolated value at x = %f: %f\n", xp, result);

    for (int i = 0; i < n; i++) {
        free(divDiff[i]);
    }
    free(divDiff);
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
    
    newtonDividedDifference(x, y, n, xp);
    
    free(x);
    free(y);
    
    return 0;
}
