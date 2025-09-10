/* 
Problem 6:
Implement Q.5 using structure.

That is, store name and age of number of persons (number provided at run time). 
Collect the data and display it in the ascending order of age. 
This time, use a structure to represent each person.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// structure for person
struct Person {
    char name[50];
    int age;
};

// Allocate memory for n persons
struct Person* allocateMemory(int n) {
    return (struct Person*)malloc(n * sizeof(struct Person));
}

// Accept values
void acceptValues(struct Person *list, int n) {
    printf("Enter name and age for %d persons:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%s %d", list[i].name, &list[i].age);
    }
}

// Comparator for qsort (ascending order by age)
int comparePersons(const void *a, const void *b) {
    const struct Person *p1 = (const struct Person *)a;
    const struct Person *p2 = (const struct Person *)b;
    return p1->age - p2->age;  // positive if p1->age > p2->age
}

// Sort persons by age using qsort
void sortByAge(struct Person *list, int n) {
    qsort(list, n, sizeof(struct Person), comparePersons);
}

// Print persons
void printValues(struct Person *list, int n) {
    printf("Sorted list (by age):\n");
    for (int i = 0; i < n; i++) {
        printf("%s %d\n", list[i].name, list[i].age);
    }
}

int main() {
    int n;
    printf("Enter number of persons: ");
    scanf("%d", &n);

    struct Person *list = allocateMemory(n);

    acceptValues(list, n);
    sortByAge(list, n);
    printValues(list, n);

    free(list);
    return 0;
}