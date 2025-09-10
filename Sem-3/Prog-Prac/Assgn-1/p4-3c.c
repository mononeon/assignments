/* 
Problem 4 (Part: Q3c):
Implement the program of Q.3(c) (2D array using pointer to an array) 
by breaking it into functions for 
i) getting the dimensions from user,
ii) dynamic memory allocation,
iii) accepting the values, and 
iv) printing the values.
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_COLS 100   // fixed maximum columns

// i) Get dimensions
void getDimensions(int *rows, int *cols) {
    printf("Enter rows and cols (<= %d): ", MAX_COLS);
    scanf("%d %d", rows, cols);
    if (*cols > MAX_COLS) {
        printf("Too many columns! Max = %d\n", MAX_COLS);
        exit(1);
    }
}

// ii) Allocate memory (pointer to an array)
int (*allocateArray(int rows))[MAX_COLS] {
    return malloc(rows * sizeof(int[MAX_COLS]));
}

// iii) Accept values
void acceptValues(int rows, int cols, int (*arr)[MAX_COLS]) {
    printf("Enter elements:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
}

// iv) Print values
void printValues(int rows, int cols, int (*arr)[MAX_COLS]) {
    printf("Matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int rows, cols;
    getDimensions(&rows, &cols);

    int (*arr)[MAX_COLS] = allocateArray(rows);

    acceptValues(rows, cols, arr);
    printValues(rows, cols, arr);

    free(arr);  // free allocated memory
    return 0;
}