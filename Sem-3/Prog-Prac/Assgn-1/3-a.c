#include<stdio.h>
#include<stdlib.h>

int main() {
    int m, n;
    printf("Enter number of rows and columns: ");
    scanf("%d %d", &m, &n);
    int *arr[m];
    for (int i = 0; i < m; i++) {
        arr[i] = (int*) malloc(n * sizeof(int));
    }
    printf("Enter elements:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    printf("Matrix:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < m; i++) {
        free(arr[i]);
    }
    return 0;
}