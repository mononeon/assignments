/* 
Problem 8:
Consider an array that stores roll, name, and score of number of students. 
Develop a function to sort the array. 
User of sort() will develop the comparison function for sorting on roll/score 
and ascending or descending order and reuse the same sort() function.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for student
struct Student {
    int roll;
    char name[50];
    int score;
};

// Merge two sorted arrays
void merge(struct Student *arr, int left, int mid, int right,
           int (*cmp)(const void *, const void *)) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    struct Student *L = malloc(n1 * sizeof(struct Student));
    struct Student *R = malloc(n2 * sizeof(struct Student));

    memcpy(L, arr + left, n1 * sizeof(struct Student));
    memcpy(R, arr + mid + 1, n2 * sizeof(struct Student));

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (cmp(&L[i], &R[j]) <= 0)
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];

    free(L);
    free(R);
}

// Recursive mergesort
void mergeSort(struct Student *arr, int left, int right,
               int (*cmp)(const void *, const void *)) {
    if (left >= right) return;

    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid, cmp);
    mergeSort(arr, mid + 1, right, cmp);
    merge(arr, left, mid, right, cmp);
}

// Sort function using mergesort
void sort(struct Student *arr, int n, int (*cmp)(const void *, const void *)) {
    mergeSort(arr, 0, n - 1, cmp);
}

// Comparison functions
int cmpRollAsc(const void *a, const void *b) {
    return ((struct Student *)a)->roll - ((struct Student *)b)->roll;
}

int cmpRollDesc(const void *a, const void *b) {
    return ((struct Student *)b)->roll - ((struct Student *)a)->roll;
}

int cmpScoreAsc(const void *a, const void *b) {
    return ((struct Student *)a)->score - ((struct Student *)b)->score;
}

int cmpScoreDesc(const void *a, const void *b) {
    return ((struct Student *)b)->score - ((struct Student *)a)->score;
}

// Print function
void printStudents(struct Student *arr, int n) {
    printf("Student list:\n");
    for (int i = 0; i < n; i++) {
        printf("Roll: %d, Name: %s, Score: %d\n", arr[i].roll, arr[i].name, arr[i].score);
    }
}

int main() {
    int n;
    printf("Enter number of students: ");
    scanf("%d", &n);

    struct Student *arr = (struct Student *)malloc(n * sizeof(struct Student));

    printf("Enter roll, name, score for %d students:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d %s %d", &arr[i].roll, arr[i].name, &arr[i].score);
    }

    int choice;
    printf("Sort by:\n1. Roll Asc\n2. Roll Desc\n3. Score Asc\n4. Score Desc\nEnter choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1: sort(arr, n, cmpRollAsc); break;
        case 2: sort(arr, n, cmpRollDesc); break;
        case 3: sort(arr, n, cmpScoreAsc); break;
        case 4: sort(arr, n, cmpScoreDesc); break;
        default: printf("Invalid choice\n"); free(arr); return 0;
    }

    printStudents(arr, n);
    free(arr);
    return 0;
}