/* 
Problem 4 (Part: Q2):
Implement the program of Q.2 (1D array) by breaking it into functions for 
i) getting the dimensions from user,
ii) dynamic memory allocation,
iii) accepting the values, and 
iv) printing the values.
*/

#include <stdio.h>
#include <stdlib.h>

// i) Get size from user
int getSize() {
    int n;
    printf("Enter size of array: ");
    scanf("%d", &n);
    return n;
}

// ii) Allocate memory
int* allocateArray(int n) {
    return (int *)malloc(n * sizeof(int));
}

// iii) Accept values
void acceptValues(int *arr, int n) {
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", arr + i);
    }
}

// iv) Print values
void printValues(int *arr, int n) {
    printf("Array elements are:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", *(arr + i));
    }
    printf("\n");
}

int main() {
    int n = getSize();
    int *arr = allocateArray(n);

    acceptValues(arr, n);
    printValues(arr, n);

    free(arr);  // free memory
    return 0;
}