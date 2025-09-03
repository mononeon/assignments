#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_LEN 100

// Structure for student
struct Student {
    int roll;
    char name[NAME_LEN];
    float score;
};

// Generic sort function
void sort(struct Student *arr, int n, int (*cmp)(const void*, const void*)) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (cmp(&arr[i], &arr[j]) > 0) {
                struct Student temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

// ---------- Comparison functions ----------
int cmp_roll_asc(const void *a, const void *b) {
    return ((struct Student*)a)->roll - ((struct Student*)b)->roll;
}
int cmp_roll_desc(const void *a, const void *b) {
    return ((struct Student*)b)->roll - ((struct Student*)a)->roll;
}
int cmp_score_asc(const void *a, const void *b) {
    float s1 = ((struct Student*)a)->score;
    float s2 = ((struct Student*)b)->score;
    if (s1 < s2) return -1;
    if (s1 > s2) return 1;
    return 0;
}
int cmp_score_desc(const void *a, const void *b) {
    float s1 = ((struct Student*)a)->score;
    float s2 = ((struct Student*)b)->score;
    if (s1 > s2) return -1;
    if (s1 < s2) return 1;
    return 0;
}

// ---------- Utility ----------
void display_students(struct Student *arr, int n) {
    printf("\nStudent List:\n");
    for (int i = 0; i < n; i++) {
        printf("Roll: %d, Name: %s, Score: %.2f\n",
               arr[i].roll, arr[i].name, arr[i].score);
    }
}

int main() {
    int n;
    printf("Enter number of students: ");
    scanf("%d", &n);

    struct Student *arr = (struct Student*) malloc(n * sizeof(struct Student));
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // Input data
    for (int i = 0; i < n; i++) {
        printf("\nEnter data for student %d:\n", i + 1);
        printf("Roll: ");
        scanf("%d", &arr[i].roll);
        printf("Name: ");
        scanf("%s", arr[i].name);
        printf("Score: ");
        scanf("%f", &arr[i].score);
    }

    // Sorting menu loop
    int choice;
    while (1) {
        printf("\nChoose sorting option:\n");
        printf("1. Roll Ascending\n");
        printf("2. Roll Descending\n");
        printf("3. Score Ascending\n");
        printf("4. Score Descending\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: sort(arr, n, cmp_roll_asc);
                    printf("\nSorted by Roll (Ascending):\n");
                    display_students(arr, n);
                    break;
            case 2: sort(arr, n, cmp_roll_desc);
                    printf("\nSorted by Roll (Descending):\n");
                    display_students(arr, n);
                    break;
            case 3: sort(arr, n, cmp_score_asc);
                    printf("\nSorted by Score (Ascending):\n");
                    display_students(arr, n);
                    break;
            case 4: sort(arr, n, cmp_score_desc);
                    printf("\nSorted by Score (Descending):\n");
                    display_students(arr, n);
                    break;
            case 5: free(arr);
                    printf("Exiting program...\n");
                    return 0;
            default:
                    printf("Invalid choice! Try again.\n");
        }
    }
}
