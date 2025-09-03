#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 50

void allocate_memory(int n, int **ages, char ***names) {
    *ages = (int*) malloc(n * sizeof(int));
    *names = (char**) malloc(n * sizeof(char*));
    for (int i = 0; i < n; i++) {
        (*names)[i] = (char*) malloc(MAX_LEN * sizeof(char));
    }
}

void accept_data(int n, int *ages, char **names) {
    for (int i = 0; i < n; i++) {
        printf("Enter name of person %d: ", i + 1);
        scanf("%s", names[i]);
        printf("Enter age of %s: ", names[i]);
        scanf("%d", &ages[i]);
    }
}

void sort_data(int n, int *ages, char **names) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (ages[i] > ages[j]) {
                int temp = ages[i];
                ages[i] = ages[j];
                ages[j] = temp;
                char tempName[MAX_LEN];
                strcpy(tempName, names[i]);
                strcpy(names[i], names[j]);
                strcpy(names[j], tempName);
            }
        }
    }
}

void display_data(int n, int *ages, char **names) {
    printf("\nData in ascending order of age:\n");
    for (int i = 0; i < n; i++) {
        printf("Name: %s, Age: %d\n", names[i], ages[i]);
    }
}

int main() {
    int n, *ages; char **names;

    printf("Enter number of people: ");
    scanf("%d", &n);

    allocate_memory(n, &ages, &names);
    accept_data(n, ages, names);
    sort_data(n, ages, names);
    display_data(n, ages, names);

    for (int i = 0; i < n; i++) {
        free(names[i]);
    }
    free(names);
    free(ages);

    return 0;
}
