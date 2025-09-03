#include <stdio.h>

void inputMatrix(int mat[3][3], char name) {
    printf("Enter values for Matrix %c:\n", name);
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            scanf("%d", &mat[i][j]);
}

void printMatrix(int mat[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

void matrixOperations(int matA[3][3], int matB[3][3]) {
    int sum[3][3], diff[3][3], prod[3][3] = {0};
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            sum[i][j] = matA[i][j] + matB[i][j];
            diff[i][j] = matA[i][j] - matB[i][j];
            for (int k = 0; k < 3; k++) {
                prod[i][j] += matA[i][k] * matB[k][j];
            }
        }
    }
    printf("Sum of matrices:\n");
    printMatrix(sum);
    printf("Diff of matrices:\n");
    printMatrix(diff);
    printf("Product of matrices:\n");
    printMatrix(prod);
}

int main() {
    int matA[3][3], matB[3][3];
    inputMatrix(matA, 'A');
    inputMatrix(matB, 'B');
    matrixOperations(matA, matB);
    return 0;
}