#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int roll;
    char name[100];
    int scores[5];
    int valid; // 1 = valid, 0 = logically deleted
};

// Function to compute total score
int total_score(struct Student s) {
    int total = 0;
    for (int i = 0; i < 5; i++) total += s.scores[i];
    return total;
}

// Function to check if roll number already exists
int roll_exists(const char *filename, int roll) {
    FILE *fp = fopen(filename, "rb");
    if (!fp) return 0;
    struct Student s;
    while (fread(&s, sizeof(s), 1, fp)) {
        if (s.valid && s.roll == roll) {
            fclose(fp);
            return 1;
        }
    }
    fclose(fp);
    return 0;
}

// Add record
void add_student(const char *filename) {
    struct Student s;
    printf("Enter roll: ");
    scanf("%d", &s.roll);

    if (roll_exists(filename, s.roll)) {
        printf("Roll number already exists! Record not added.\n");
        return;
    }

    printf("Enter name: ");
    scanf("%s", s.name);
    printf("Enter 5 subject scores:\n");
    for (int i = 0; i < 5; i++) scanf("%d", &s.scores[i]);
    s.valid = 1;

    FILE *fp = fopen(filename, "ab");
    fwrite(&s, sizeof(s), 1, fp);
    fclose(fp);
    printf("Record added successfully!\n");
}

// Display all records
void display_students(const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (!fp) {
        printf("No records found.\n");
        return;
    }
    struct Student s;
    printf("\nAll Student Records:\n");
    while (fread(&s, sizeof(s), 1, fp)) {
        if (s.valid) {
            printf("Roll: %d, Name: %s, Total Score: %d\n",
                   s.roll, s.name, total_score(s));
        }
    }
    fclose(fp);
}

// Search by roll
void search_student(const char *filename) {
    int roll;
    printf("Enter roll to search: ");
    scanf("%d", &roll);

    FILE *fp = fopen(filename, "rb");
    if (!fp) {
        printf("No records found.\n");
        return;
    }
    struct Student s;
    int found = 0;
    while (fread(&s, sizeof(s), 1, fp)) {
        if (s.valid && s.roll == roll) {
            printf("Record Found: Roll: %d, Name: %s, Total Score: %d\n",
                   s.roll, s.name, total_score(s));
            found = 1;
            break;
        }
    }
    if (!found) printf("No record found for roll %d.\n", roll);
    fclose(fp);
}

// Edit record
void edit_student(const char *filename) {
    int roll;
    printf("Enter roll to edit: ");
    scanf("%d", &roll);

    FILE *fp = fopen(filename, "rb+");
    if (!fp) {
        printf("No records found.\n");
        return;
    }

    struct Student s;
    int found = 0;
    while (fread(&s, sizeof(s), 1, fp)) {
        if (s.valid && s.roll == roll) {
            found = 1;
            printf("Enter new name: ");
            scanf("%s", s.name);
            printf("Enter 5 new subject scores:\n");
            for (int i = 0; i < 5; i++) scanf("%d", &s.scores[i]);

            fseek(fp, -sizeof(s), SEEK_CUR); // move back one record
            fwrite(&s, sizeof(s), 1, fp);
            printf("Record updated successfully!\n");
            break;
        }
    }
    if (!found) printf("Record not found.\n");
    fclose(fp);
}

// Logical delete
void logical_delete(const char *filename) {
    int roll;
    printf("Enter roll to delete (logical): ");
    scanf("%d", &roll);

    FILE *fp = fopen(filename, "rb+");
    if (!fp) {
        printf("No records found.\n");
        return;
    }

    struct Student s;
    int found = 0;
    while (fread(&s, sizeof(s), 1, fp)) {
        if (s.valid && s.roll == roll) {
            s.valid = 0;
            fseek(fp, -sizeof(s), SEEK_CUR);
            fwrite(&s, sizeof(s), 1, fp);
            printf("Record logically deleted.\n");
            found = 1;
            break;
        }
    }
    if (!found) printf("Record not found.\n");
    fclose(fp);
}

// Physical delete (rewrite file without deleted records)
void physical_delete(const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (!fp) {
        printf("No records found.\n");
        return;
    }
    FILE *temp = fopen("temp.dat", "wb");

    struct Student s;
    while (fread(&s, sizeof(s), 1, fp)) {
        if (s.valid) {
            fwrite(&s, sizeof(s), 1, temp);
        }
    }
    fclose(fp);
    fclose(temp);

    remove(filename);
    rename("temp.dat", filename);

    printf("Physical deletion completed.\n");
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    const char *filename = argv[1];
    int choice;

    while (1) {
        printf("\n--- Student File Menu ---\n");
        printf("1. Add Record\n");
        printf("2. Display All Records\n");
        printf("3. Search Record\n");
        printf("4. Edit Record\n");
        printf("5. Logical Delete\n");
        printf("6. Physical Delete\n");
        printf("7. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: add_student(filename); break;
            case 2: display_students(filename); break;
            case 3: search_student(filename); break;
            case 4: edit_student(filename); break;
            case 5: logical_delete(filename); break;
            case 6: physical_delete(filename); break;
            case 7: printf("Exiting...\n"); return 0;
            default: printf("Invalid choice!\n");
        }
    }
}
