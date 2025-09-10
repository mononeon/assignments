/* 
Problem 4 (Part: Q3b2):
Implement the program of Q.3(b2) (2D array using pointer to pointer with one malloc) 
by breaking it into functions for 
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

// ii) Allocate memory (single malloc for all elements)
int* allocateArray(int rows, int cols) {
    return (int *)malloc(rows * cols * sizeof(int));
}

// iii) Accept values
void acceptValues(int *arr, int rows, int cols) {
    printf("Enter elements:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", arr + i * cols + j);
        }
    }
}

// iv) Print values
void printValues(int *arr, int rows, int cols) {
    printf("Matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", *(arr + i * cols + j));
        }
        printf("\n");
    }
}

int main() {
    int rows, cols;
    getDimensions(&rows, &cols);

    int *arr = allocateArray(rows, cols);

    acceptValues(arr, rows, cols);
    printValues(arr, rows, cols);

    free(arr);  // free allocated memory
    return 0;
}