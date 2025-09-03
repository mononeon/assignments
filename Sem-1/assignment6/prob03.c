#include <stdio.h>
#include <stdlib.h>

void gaussJordanElimination(float **A, float *B, int n) {
    for (int i = 0; i < n; i++) {
        float pivot = A[i][i];
        for (int j = 0; j < n; j++) {
            A[i][j] /= pivot;
        }
        B[i] /= pivot;
        
        for (int k = 0; k < n; k++) {
            if (k != i) {
                float factor = A[k][i];
                for (int j = 0; j < n; j++) {
                    A[k][j] -= factor * A[i][j];
                }
                B[k] -= factor * B[i];
            }
        }
    }

    printf("Solution:\n");
    for (int i = 0; i < n; i++) {
        printf("X[%d] = %f\n", i, B[i]);
    }
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

    gaussJordanElimination(A, B, n);

    for (int i = 0; i < n; i++) {
        free(A[i]);
    }
    free(A);
    free(B);

    return 0;
}
