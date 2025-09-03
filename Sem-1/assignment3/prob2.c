#include <stdio.h>

void duplicateCheck(int arr[], int n) {
    int unique[n], k = 0;
    int isDuplicate;
    for (int i = 0; i < n; i++) {
        isDuplicate = 0;
        for (int j = 0; j < k; j++) {
            if (arr[i] == unique[j]) {
                isDuplicate = 1;
                break;
            }
        }
        if (!isDuplicate) {
            unique[k++] = arr[i];
        }
    }
    printf("Array without duplicate elements in reverse: ");
    for (int i = k - 1; i >= 0; i--) {
        printf("%d ", unique[i]);
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    duplicateCheck(arr, n);
    return 0;
}