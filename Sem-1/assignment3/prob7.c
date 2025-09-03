#include<stdio.h>



int main() {
    printf("Enter order of the matrix: ");
    int n; scanf("%d", &n);
    int mat[n][n];
    printf("Enter values for Matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &mat[i][j]);

    printf("The transpose matrix is: \n");

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", mat[j][i]);
        }
        printf("\n");
    }
    return 0;
}