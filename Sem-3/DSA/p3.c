/* Q3_array.c : Union of two sorted lists (arrays) using basic operations */
#include <stdio.h>

void printUnion(int L1[], int n1, int L2[], int n2) {
    int i = 0, j = 0;

    printf("Union: ");
    while (i < n1 && j < n2) {
        if (L1[i] < L2[j]) {
            printf("%d ", L1[i]);
            i++;
        }
        else if (L2[j] < L1[i]) {
            printf("%d ", L2[j]);
            j++;
        }
        else { // equal
            printf("%d ", L1[i]);
            i++;
            j++;
        }
    }

    // Add remaining elements
    while (i < n1) {
        printf("%d ", L1[i]);
        i++;
    }
    while (j < n2) {
        printf("%d ", L2[j]);
        j++;
    }
    printf("\n");
}

int main() {
    int n1, n2;

    printf("Enter size of L1: ");
    scanf("%d", &n1);
    int L1[n1];
    printf("Enter %d sorted elements of L1: ", n1);
    for (int i = 0; i < n1; i++) scanf("%d", &L1[i]);

    printf("Enter size of L2: ");
    scanf("%d", &n2);
    int L2[n2];
    printf("Enter %d sorted elements of L2: ", n2);
    for (int i = 0; i < n2; i++) scanf("%d", &L2[i]);

    printUnion(L1, n1, L2, n2);

    return 0;
}
