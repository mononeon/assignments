/* 
Problem 4:
Implement the programs in Q.2 and 3 breaking it into functions for:
i) Getting the dimensions from user,
ii) Dynamic memory allocation,
iii) Accepting the values, and
iv) Printing the values.
*/

#include <stdio.h>
#include <stdlib.h>

/* ---------------------- 1D Array Functions ---------------------- */

// i) Get size from user
int getSize() {
    int n;
    printf("Enter size of array: ");
    scanf("%d", &n);
    return n;
}

// ii) Allocate memory
int* allocateArray1D(int n) {
    return (int *)malloc(n * sizeof(int));
}

// iii) Accept values
void acceptValues1D(int *arr, int n) {
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", arr + i);
    }
}

// iv) Print values
void printValues1D(int *arr, int n) {
    printf("Array elements are:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", *(arr + i));
    }
    printf("\n");
}

/* ---------------------- 2D Array Functions ---------------------- */

// i) Get dimensions
void getDimensions(int *rows, int *cols) {
    printf("Enter rows and cols: ");
    scanf("%d %d", rows, cols);
}

// ii) Allocate memory (array of pointers)
int** allocateArray2D(int rows, int cols) {
    int **arr = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        arr[i] = (int *)malloc(cols * sizeof(int));
    }
    return arr;
}

// iii) Accept values
void acceptValues2D(int **arr, int rows, int cols) {
    printf("Enter elements:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
}

// iv) Print values
void printValues2D(int **arr, int rows, int cols) {
    printf("Matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

// Free allocated memory
void freeArray2D(int **arr, int rows) {
    for (int i = 0; i < rows; i++) {
        free(arr[i]);
    }
    free(arr);
}

/* ---------------------- Main Menu ---------------------- */
int main() {
    int choice;
    while (1) {
        printf("\nMenu:\n");
        printf("1. Implement 1D Array\n");
        printf("2. Implement 2D Array\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            int n = getSize();
            int *arr = allocateArray1D(n);
            acceptValues1D(arr, n);
            printValues1D(arr, n);
            free(arr);
        } 
        else if (choice == 2) {
            int rows, cols;
            getDimensions(&rows, &cols);
            int **arr = allocateArray2D(rows, cols);
            acceptValues2D(arr, rows, cols);
            printValues2D(arr, rows, cols);
            freeArray2D(arr, rows);
        } 
        else if (choice == 3) {
            printf("Exiting program...\n");
            exit(0);
        } 
        else {
            printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}
