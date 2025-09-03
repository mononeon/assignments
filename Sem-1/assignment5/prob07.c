#include <stdio.h>
#include <stdlib.h>
 
void bubbleSort(int *arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
 
int main() {
    FILE *input = fopen("input.txt", "r");
    FILE *output = fopen("output.txt", "w");
 
    if (input == NULL || output == NULL) {
        printf("Error opening file.\n");
        return 1;
    }
 
    int *arr = NULL;
    int n = 0, num;
 
    while (fscanf(input, "%d", &num) == 1) {
        arr = realloc(arr, (n + 1) * sizeof(int));
        arr[n++] = num;
    }
 
    bubbleSort(arr, n);
 
    for (int i = 0; i < n; i++) {
        fprintf(output, "%d\n", arr[i]);
    }
 
    free(arr);
    fclose(input);
    fclose(output);
 
    printf("Numbers sorted and written to output.txt.\n");
    return 0;
}