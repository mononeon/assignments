/* Q2_array.c : Intersection of two sorted lists (arrays) using basic operations */
#include <stdio.h>

void printIntersection(int L1[], int n1, int L2[], int n2) {
    int i = 0, j = 0;

    printf("Intersection: ");
    while (i < n1 && j < n2) {
        if (L1[i] < L2[j]) {
            i++;
        }
        else if (L2[j] < L1[i]) {
            j++;
        }
        else { // equal elements → part of intersection
            printf("%d ", L1[i]);
            i++;
            j++;
        }
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

    printIntersection(L1, n1, L2, n2);

    return 0;
}
