/*
Write a C program which dynamically allocates memory for two matrices, orders of which is
given by the user, and reads the values of elements of the matrices from the user. The program
creates a third matrix which is obtained by multiplying the two input matrices. Your program should
check for conformity of multiplication of the two matrices given by the user.
*/

#include<stdio.h>
#include<stdlib.h>

void getMatrix(int rows, int cols, int**matrix, const char* name) {
    printf("Enter elements of matrix %s (%d x %d): \n", name, rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
}

void printMatrix(int rows, int cols, int**matrix, const char* name) {
    printf("Matrix %s (%d x %d): \n", name, rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int rows1, cols1, rows2, cols2;

    printf("Enter number of rows and columns of first matrix: ");
    scanf("%d %d", &rows1, &cols1);

    printf("Enter number of rows and columns of second matrix: ");
    scanf("%d %d", &rows2, &cols2);
    
    if (cols1 != rows2) {
        printf("Matrix multiplication not possible\n");
        return 1;
    }

    int** matrix1 = (int**)malloc(rows1 * sizeof(int*));
    int** matrix2 = (int**)malloc(rows2 * sizeof(int*));
    int** result = (int**)malloc(rows1 * sizeof(int*));

    for (int i = 0; i < rows1; i++) {
        *(matrix1 + i) = (int*)malloc(cols1 * sizeof(int));
        *(result + i) = (int*)malloc(cols2 * sizeof(int));
    }

    for (int i = 0; i < rows2; i++) {
        *(matrix2 + i) = (int*)malloc(cols2 * sizeof(int));
    }
    
    getMatrix(rows1, cols1, matrix1, "A");
    getMatrix(rows2, cols2, matrix2, "B");

    printf("\nCalculating the resultant matrix...\n\n");

    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < cols1; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j]; 
            }
        }
    }

    printMatrix(rows1, cols2, result, "Result");

    for (int i = 0; i < rows1; i++) {
        free(*(matrix1 + i));
        free(*(result + i));
    }

    for (int i = 0; i < rows2; i++) {
        free(*(matrix2 + i));
    }

    free(matrix1);
    free(matrix2);
    free(result);

    return 0;
}