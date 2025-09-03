#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define EPSILON 0.0001
#define MAX_ITER 100

void jacobiMethod(float **A, float *B, float *X, int n) {
    float *X_new = (float *)malloc(n * sizeof(float));
    int iter = 0;
    while (iter < MAX_ITER) {
        for (int i = 0; i < n; i++) {
            float sum = B[i];
            for (int j = 0; j < n; j++) {
                if (i != j) {
                    sum -= A[i][j] * X[j];
                }
            }
            X_new[i] = sum / A[i][i];
        }
        int done = 1;
        for (int i = 0; i < n; i++) {
            if (fabs(X_new[i] - X[i]) > EPSILON) {
                done = 0;
            }
            X[i] = X_new[i];
        }
        if (done) break;
        iter++;
    }
    printf("Jacobi Method converged in %d iterations.\n", iter);
    free(X_new);
}

void gaussSeidelMethod(float **A, float *B, float *X, int n) {
    int iter = 0;
    while (iter < MAX_ITER) {
        int done = 1;
        for (int i = 0; i < n; i++) {
            float sum = B[i];
            for (int j = 0; j < n; j++) {
                if (i != j) {
                    sum -= A[i][j] * X[j];
                }
            }
            float newX = sum / A[i][i];
            if (fabs(newX - X[i]) > EPSILON) {
                done = 0;
            }
            X[i] = newX;
        }
        if (done) break;
        iter++;
    }
    printf("Gauss-Seidel Method converged in %d iterations.\n", iter);
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
    float *X = (float *)malloc(n * sizeof(float));

    for (int i = 0; i < n; i++) {
        A[i] = (float *)malloc(n * sizeof(float));
        for (int j = 0; j < n; j++) {
            fscanf(file, "%f", &A[i][j]);
        }
        fscanf(file, "%f", &B[i]);
        X[i] = 0;
    }
    fclose(file);

    jacobiMethod(A, B, X, n);
    gaussSeidelMethod(A, B, X, n);

    for (int i = 0; i < n; i++) {
        free(A[i]);
    }
    free(A);
    free(B);
    free(X);

    return 0;
}
