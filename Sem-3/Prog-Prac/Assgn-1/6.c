#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 50

struct Person {
    char name[MAX_LEN];
    int age;
};

struct Person* allocate_memory(int n) {
    return (struct Person*) malloc(n * sizeof(struct Person));
}

void accept_data(int n, struct Person *arr) {
    for (int i = 0; i < n; i++) {
        printf("Enter name of person %d: ", i + 1);
        scanf("%s", arr[i].name);
        printf("Enter age of %s: ", arr[i].name);
        scanf("%d", &arr[i].age);
    }
}

void sort_data(int n, struct Person *arr) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i].age > arr[j].age) {
                struct Person temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void display_data(int n, struct Person *arr) {
    printf("\nData in ascending order of age:\n");
    for (int i = 0; i < n; i++) {
        printf("Name: %s, Age: %d\n", arr[i].name, arr[i].age);
    }
}

int main() {
    int n;
    struct Person *arr;

    printf("Enter number of people: ");
    scanf("%d", &n);

    arr = allocate_memory(n);
    accept_data(n, arr);
    sort_data(n, arr);
    display_data(n, arr);

    free(arr);
    return 0;
}
