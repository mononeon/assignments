/* 
Problem 7:
Maintain a list to store roll, name and score of students. 
As and when required student record may be added or deleted. 
Also, the list has to be displayed. 
Design suitable functions for different operations.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100  // maximum number of students

// structure for student
struct Student {
    int roll;
    char name[50];
    int score;
};

// Add a student (only if space available and roll unique)
void addStudent(struct Student *list, int *n) {
    if (*n >= MAX) {
        printf("Error: Student list is full.\n");
        return;
    }

    int roll;
    char name[50];
    int score;

    printf("Enter roll, name, score: ");
    scanf("%d %s %d", &roll, name, &score);

    // check for unique roll
    for (int i = 0; i < *n; i++) {
        if (list[i].roll == roll) {
            printf("Error: Roll %d already exists.\n", roll);
            return;
        }
    }

    // add student
    list[*n].roll = roll;
    strcpy(list[*n].name, name);
    list[*n].score = score;
    (*n)++;

    printf("Student added successfully.\n");
}

// Delete a student by roll
void deleteStudent(struct Student *list, int *n, int roll) {
    int index = -1;
    for (int i = 0; i < *n; i++) {
        if (list[i].roll == roll) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        printf("Student with roll %d not found.\n", roll);
        return;
    }

    // shift students left
    for (int i = index; i < *n - 1; i++) {
        list[i] = list[i + 1];
    }

    (*n)--;
    printf("Student with roll %d deleted.\n", roll);
}

// Display list
void displayStudents(struct Student *list, int n) {
    if (n == 0) {
        printf("No students in the list.\n");
        return;
    }

    printf("Current student list:\n");
    for (int i = 0; i < n; i++) {
        printf("Roll: %d, Name: %s, Score: %d\n", list[i].roll, list[i].name, list[i].score);
    }
}

int main() {
    struct Student list[MAX];  // fixed array
    int n = 0;                 // current count
    int choice;

    do {
        printf("\nMenu:\n1. Add Student\n2. Delete Student\n3. Display\n4. Exit\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent(list, &n);
                break;
            case 2: {
                int roll;
                printf("Enter roll to delete: ");
                scanf("%d", &roll);
                deleteStudent(list, &n, roll);
                break;
            }
            case 3:
                displayStudents(list, n);
                break;
            case 4:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}