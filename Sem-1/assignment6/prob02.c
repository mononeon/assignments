#include <stdio.h>
#include <stdlib.h>

void gaussianElimination(float **A, float *B, int n) {
    for (int i = 0; i < n; i++) {
        for (int k = i + 1; k < n; k++) {
            float factor = A[k][i] / A[i][i];
            for (int j = i; j < n; j++) {
                A[k][j] -= factor * A[i][j];
            }
            B[k] -= factor * B[i];
        }
    }

    float *X = (float *)malloc(n * sizeof(float));
    for (int i = n - 1; i >= 0; i--) {
        X[i] = B[i];
        for (int j = i + 1; j < n; j++) {
            X[i] -= A[i][j] * X[j];
        }
        X[i] /= A[i][i];
    }

    printf("Solution:\n");
    for (int i = 0; i < n; i++) {
        printf("X[%d] = %f\n", i, X[i]);
    }
    free(X);
}

int main() {
    FILE *file = fopen("linear_equations.txt", "r");
    if (!file) {
        printf("Error opening file!\n");
        return 1;
    }

    int n;
    fscanf(file, "%d", &n);
    float **A = (float **)malloc(n * sizeof(float *));
    float *B = (float *)malloc(n * sizeof(float));

    for (int i = 0; i < n; i++) {
        A[i] = (float *)malloc(n * sizeof(float));
        for (int j = 0; j < n; j++) {
            fscanf(file, "%f", &A[i][j]);
        }
        fscanf(file, "%f", &B[i]);
    }
    fclose(file);

    gaussianElimination(A, B, n);

    for (int i = 0; i < n; i++) {
        free(A[i]);
    }
    free(A);
    free(B);

    return 0;
}
