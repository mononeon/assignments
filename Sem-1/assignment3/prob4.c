#include<stdio.h>

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int element;
    printf("Enter the elements: ");
    scanf("%d", &element);
    int min = element, max = element;
    for (int i = 1; i < n; i++) {
        scanf("%d", &element);
        if (element < min) min = element;
        if (element > max) max = element;
    }

    printf("The range of elements is: %d\n", max - min);

}