/* 
Problem 3(b2):
Implement a two dimensional array of integers using pointer to pointer 
with a single malloc statement.
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    int rows, cols;
    printf("Enter rows and cols: ");
    scanf("%d %d", &rows, &cols);

    int *arr = (int *)malloc(rows * cols * sizeof(int));  // one block for all elements

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
    return 0;
}