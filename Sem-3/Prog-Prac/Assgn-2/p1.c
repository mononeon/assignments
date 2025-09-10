/*
Write a program to store student information in a file and to do the following operations. Information includes roll, name, and score in five subjects. User may like to add record (ensure roll number is unique), display all records showing roll, name and total score. User may search for the record against a roll. User
may edit the details of a record. User may delete a record. Deletion may be logical (by some means indicate it is an invalid record and to be avoided in processing) and physical (file will not have the record).	
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SUBJECTS 5

struct Student {
    int roll;
    char name[50];
    int marks[SUBJECTS];
    int valid; // 1 = valid, 0 = logically deleted
};

// Function prototypes
void addRecord(FILE *fp);
void displayRecords(FILE *fp);
void searchRecord(FILE *fp);
void editRecord(FILE *fp);
void logicalDeleteRecord(FILE *fp);
void physicalDeleteRecords(const char *filename);
int rollExists(FILE *fp, int roll);

// Merge sort helpers for sorting by total score
void merge(struct Student *arr, int left, int mid, int right);
void mergeSort(struct Student *arr, int left, int right);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s filename\n", argv[0]);
        return 1;
    }

    const char *filename = argv[1];
    FILE *fp;
    int choice;

    do {
        printf("\nMenu:\n");
        printf("1. Add Record\n");
        printf("2. Display All Records\n");
        printf("3. Search Record\n");
        printf("4. Edit Record\n");
        printf("5. Logical Delete Record\n");
        printf("6. Physical Delete Records\n");
        printf("7. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                fp = fopen(filename, "ab+");
                if (!fp) { perror("Error opening file"); break; }
                addRecord(fp);
                fclose(fp);
                break;

            case 2:
                fp = fopen(filename, "rb");
                if (!fp) { perror("Error opening file"); break; }
                displayRecords(fp);
                fclose(fp);
                break;

            case 3:
                fp = fopen(filename, "rb");
                if (!fp) { perror("Error opening file"); break; }
                searchRecord(fp);
                fclose(fp);
                break;

            case 4:
                fp = fopen(filename, "rb+");
                if (!fp) { perror("Error opening file"); break; }
                editRecord(fp);
                fclose(fp);
                break;

            case 5:
                fp = fopen(filename, "rb+");
                if (!fp) { perror("Error opening file"); break; }
                logicalDeleteRecord(fp);
                fclose(fp);
                break;

            case 6:
                physicalDeleteRecords(filename);
                break;

            case 7:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 7);

    return 0;
}

// Check if roll exists
int rollExists(FILE *fp, int roll) {
    struct Student s;
    rewind(fp);
    while (fread(&s, sizeof(s), 1, fp) == 1)
        if (s.valid && s.roll == roll) return 1;
    return 0;
}

// Add new student
void addRecord(FILE *fp) {
    struct Student s;
    printf("Enter roll number: ");
    scanf("%d", &s.roll);

    if (rollExists(fp, s.roll)) {
        printf("Roll number already exists!\n");
        return;
    }

    printf("Enter name: ");
    scanf("%s", s.name);

    printf("Enter marks for %d subjects: ", SUBJECTS);
    for (int i = 0; i < SUBJECTS; i++) scanf("%d", &s.marks[i]);

    s.valid = 1;
    fseek(fp, 0, SEEK_END);
    fwrite(&s, sizeof(s), 1, fp);
    printf("Record added successfully.\n");
}

// Merge sort functions
void merge(struct Student *arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    struct Student *L = malloc(n1 * sizeof(struct Student));
    struct Student *R = malloc(n2 * sizeof(struct Student));
    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int i = 0; i < n2; i++) R[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        int totalL = 0, totalR = 0;
        for (int t = 0; t < SUBJECTS; t++) { totalL += L[i].marks[t]; totalR += R[j].marks[t]; }
        if (totalL >= totalR) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
    free(L); free(R);
}

void mergeSort(struct Student *arr, int left, int right) {
    if (left >= right) return;
    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

// Display all valid records sorted by total score
void displayRecords(FILE *fp) {
    struct Student s;
    int count = 0;
    rewind(fp);
    while (fread(&s, sizeof(s), 1, fp) == 1) if (s.valid) count++;
    if (count == 0) { printf("No records to display.\n"); return; }

    struct Student *arr = malloc(count * sizeof(struct Student));
    rewind(fp); int idx = 0;
    while (fread(&s, sizeof(s), 1, fp) == 1) if (s.valid) arr[idx++] = s;

    mergeSort(arr, 0, count - 1);

    printf("\nRoll\tName\tTotal\n");
    printf("-------------------------\n");
    for (int i = 0; i < count; i++) {
        int total = 0;
        for (int j = 0; j < SUBJECTS; j++) total += arr[i].marks[j];
        printf("%d\t%s\t%d\n", arr[i].roll, arr[i].name, total);
    }
    free(arr);
}

// Search record by roll
void searchRecord(FILE *fp) {
    int roll; printf("Enter roll to search: "); scanf("%d", &roll);
    struct Student s; int found = 0, total;
    rewind(fp);
    while (fread(&s, sizeof(s), 1, fp) == 1) {
        if (s.valid && s.roll == roll) {
            total = 0; for (int i = 0; i < SUBJECTS; i++) total += s.marks[i];
            printf("Roll: %d, Name: %s, Total: %d\n", s.roll, s.name, total);
            found = 1; break;
        }
    }
    if (!found) printf("Record not found.\n");
}

// Edit record
void editRecord(FILE *fp) {
    int roll; printf("Enter roll to edit: "); scanf("%d", &roll);
    struct Student s; long pos; int found = 0;
    rewind(fp);
    while (fread(&s, sizeof(s), 1, fp) == 1) {
        if (s.valid && s.roll == roll) { found = 1; pos = ftell(fp) - sizeof(s); break; }
    }
    if (!found) { printf("Record not found.\n"); return; }

    printf("Enter new name: "); scanf("%s", s.name);
    printf("Enter new marks for %d subjects: ", SUBJECTS);
    for (int i = 0; i < SUBJECTS; i++) scanf("%d", &s.marks[i]);

    fseek(fp, pos, SEEK_SET);
    fwrite(&s, sizeof(s), 1, fp);
    printf("Record updated successfully.\n");
}

// Logical delete
void logicalDeleteRecord(FILE *fp) {
    int roll; printf("Enter roll to logically delete: "); scanf("%d", &roll);
    struct Student s; long pos; int found = 0;
    rewind(fp);
    while (fread(&s, sizeof(s), 1, fp) == 1) {
        if (s.valid && s.roll == roll) { found = 1; pos = ftell(fp) - sizeof(s); break; }
    }
    if (!found) { printf("Record not found.\n"); return; }
    s.valid = 0;
    fseek(fp, pos, SEEK_SET);
    fwrite(&s, sizeof(s), 1, fp);
    printf("Record logically deleted.\n");
}

// Physical delete: remove logically deleted records
void physicalDeleteRecords(const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (!fp) { perror("Error opening file"); return; }
    FILE *temp = fopen("temp.dat", "wb");
    if (!temp) { perror("Error creating temp file"); fclose(fp); return; }

    struct Student s;
    while (fread(&s, sizeof(s), 1, fp) == 1) if (s.valid) fwrite(&s, sizeof(s), 1, temp);

    fclose(fp); fclose(temp);
    remove(filename); rename("temp.dat", filename);
    printf("Physically deleted all logically removed records.\n");
}
