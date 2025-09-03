#include<stdio.h>
#include<stdlib.h>

int main() {
    int m, n;
    printf("Enter number of rows and columns: ");
    scanf("%d %d", &m, &n);
    int *arr = (int*) malloc(m * n * sizeof(int));
    printf("Enter elements:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", (arr + i * n + j));
        }
    }
    printf("Matrix:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", arr[i * n + j]);
        }
        printf("\n");
    }
    free(arr);
    return 0;
}