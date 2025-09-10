/* 
Problem 2:
Implement a one dimensional array of integers where size of the array will be provided 
during runtime. Accept the values for the elements and print those using pointers.
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("Enter size of array: ");
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));  // dynamic allocation

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", arr + i);   // input using pointer arithmetic
    }

    printf("Array elements are:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", *(arr + i));  // output using pointers
    }
    printf("\n");

    free(arr);  // free allocated memory
    return 0;
}