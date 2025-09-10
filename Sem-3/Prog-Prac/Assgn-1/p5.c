/* 
Problem 5:
Store name and age of number of persons (number provided at run time). 
Collect the data and display data in the ascending order of age. 
Implement without using structure. 
Write functions for memory allocation of the list, sorting and display of data.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Global arrays so comparator can see them
char **g_names;
int  *g_ages;

// Comparator for qsort (ascending by age)
int cmpAge(const void *a, const void *b) {
    int i = *(const int*)a;
    int j = *(const int*)b;
    return g_ages[i] - g_ages[j];
}

// Allocate memory for names (array of char pointers) and ages
void allocateMemory(char ***names, int **ages, int n) {
    *names = (char **)malloc(n * sizeof(char *));
    for (int i = 0; i < n; i++) {
        (*names)[i] = (char *)malloc(50 * sizeof(char)); // each name max 49 chars
    }
    *ages = (int *)malloc(n * sizeof(int));
}

// Accept values
void acceptValues(char **names, int *ages, int n) {
    printf("Enter name and age for %d persons:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%s %d", names[i], &ages[i]);
    }
}

// Sort by age using qsort
void sortByAge(char **names, int *ages, int n) {
    g_names = names;
    g_ages = ages;

    int *idx = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) idx[i] = i;

    qsort(idx, n, sizeof(int), cmpAge);

    // Rearrange arrays into new order
    char **newNames = malloc(n * sizeof(char *));
    int  *newAges   = malloc(n * sizeof(int));

    for (int k = 0; k < n; k++) {
        newNames[k] = names[idx[k]];
        newAges[k]  = ages[idx[k]];
    }

    memcpy(names, newNames, n * sizeof(char*));
    memcpy(ages, newAges, n * sizeof(int));

    free(newNames);
    free(newAges);
    free(idx);
}

// Print values
void printValues(char **names, int *ages, int n) {
    printf("Sorted list (by age):\n");
    for (int i = 0; i < n; i++) {
        printf("%s %d\n", names[i], ages[i]);
    }
}

// Free memory
void freeMemory(char **names, int *ages, int n) {
    for (int i = 0; i < n; i++) {
        free(names[i]);
    }
    free(names);
    free(ages);
}

int main() {
    int n;
    printf("Enter number of persons: ");
    scanf("%d", &n);

    char **names;
    int *ages;

    allocateMemory(&names, &ages, n);
    acceptValues(names, ages, n);
    sortByAge(names, ages, n);
    printValues(names, ages, n);

    freeMemory(names, ages, n);
    return 0;
}