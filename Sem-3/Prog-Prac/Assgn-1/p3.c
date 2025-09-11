/* 
Problem 3: Implement a two dimensional array of integers using
a) Array of pointers
b1) Pointer to pointer (two mallocs)
b2) Pointer to pointer (single malloc)
c) Pointer to an array
*/

#include <stdio.h>
#include <stdlib.h>

// (a) Array of pointers
void method_array_of_pointers() {
    int rows, cols;
    printf("Enter rows and cols: ");
    scanf("%d %d", &rows, &cols);

    int *arr[rows];  // array of pointers
    for (int i = 0; i < rows; i++) {
        arr[i] = (int *)malloc(cols * sizeof(int));
    }

    printf("Enter elements:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    printf("Matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < rows; i++) free(arr[i]);
}

// (b1) Pointer to pointer (two mallocs)
void method_pointer_to_pointer_two_mallocs() {
    int rows, cols;
    printf("Enter rows and cols: ");
    scanf("%d %d", &rows, &cols);

    int **arr = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        arr[i] = (int *)malloc(cols * sizeof(int));
    }

    printf("Enter elements:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    printf("Matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < rows; i++) free(arr[i]);
    free(arr);
}

// (b2) Pointer to pointer (single malloc)
void method_pointer_to_pointer_single_malloc() {
    int rows, cols;
    printf("Enter rows and cols: ");
    scanf("%d %d", &rows, &cols);

    int *arr = (int *)malloc(rows * cols * sizeof(int));

    printf("Enter elements:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", arr + i * cols + j);
        }
    }

    printf("Matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", *(arr + i * cols + j));
        }
        printf("\n");
    }

    free(arr);
}

// (c) Pointer to an array
void method_pointer_to_array() {
    int rows, cols;
    printf("Enter rows and cols: ");
    scanf("%d %d", &rows, &cols);

    int (*arr)[cols] = malloc(rows * sizeof(*arr));

    printf("Enter elements:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    printf("Matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    free(arr);
}

int main() {
    int choice;
    while (1) {
        printf("\nMenu:\n");
        printf("1. Array of pointers\n");
        printf("2. Pointer to pointer (two mallocs)\n");
        printf("3. Pointer to pointer (single malloc)\n");
        printf("4. Pointer to an array\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: method_array_of_pointers(); break;
            case 2: method_pointer_to_pointer_two_mallocs(); break;
            case 3: method_pointer_to_pointer_single_malloc(); break;
            case 4: method_pointer_to_array(); break;
            case 5: exit(0);
            default: printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}
