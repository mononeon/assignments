/* 
Problem 4 (Part: Q3):
Implement the program of Q.3 (2D array) by breaking it into functions for 
i) getting the dimensions from user,
ii) dynamic memory allocation,
iii) accepting the values, and 
iv) printing the values.
*/

#include <stdio.h>
#include <stdlib.h>

// i) Get dimensions
void getDimensions(int *rows, int *cols) {
    printf("Enter rows and cols: ");
    scanf("%d %d", rows, cols);
}

// ii) Allocate memory (array of pointers)
int** allocateArray(int rows, int cols) {
    int **arr = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        arr[i] = (int *)malloc(cols * sizeof(int));
    }
    return arr;
}

// iii) Accept values
void acceptValues(int **arr, int rows, int cols) {
    printf("Enter elements:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
}

// iv) Print values
void printValues(int **arr, int rows, int cols) {
    printf("Matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

// Free allocated memory
void freeArray(int **arr, int rows) {
    for (int i = 0; i < rows; i++) {
        free(arr[i]);
    }
    free(arr);
}

int main() {
    int rows, cols;
    getDimensions(&rows, &cols);

    int **arr = allocateArray(rows, cols);

    acceptValues(arr, rows, cols);
    printValues(arr, rows, cols);

    freeArray(arr, rows);
    return 0;
}