#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_LEN 100

// Structure to hold student record
struct Student {
    int roll;
    char name[NAME_LEN];
    float score;
    struct Student *next;
};

// Function to create a new student node
struct Student* create_student(int roll, char *name, float score) {
    struct Student *newNode = (struct Student*) malloc(sizeof(struct Student));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->roll = roll;
    strcpy(newNode->name, name);
    newNode->score = score;
    newNode->next = NULL;
    return newNode;
}

// Function to add student at end
void add_student(struct Student **head, int roll, char *name, float score) {
    struct Student *newNode = create_student(roll, name, score);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Student *temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    printf("Student added successfully!\n");
}

// Function to delete student by roll number
void delete_student(struct Student **head, int roll) {
    struct Student *temp = *head, *prev = NULL;

    while (temp != NULL && temp->roll != roll) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Student with roll %d not found!\n", roll);
        return;
    }

    if (prev == NULL) {
        *head = temp->next;  // deleting head
    } else {
        prev->next = temp->next;
    }
    free(temp);
    printf("Student with roll %d deleted successfully!\n", roll);
}

// Function to display student list
void display_students(struct Student *head) {
    if (head == NULL) {
        printf("No student records found.\n");
        return;
    }

    printf("\nStudent List:\n");
    struct Student *temp = head;
    while (temp != NULL) {
        printf("Roll: %d, Name: %s, Score: %.2f\n",
               temp->roll, temp->name, temp->score);
        temp = temp->next;
    }
}

// Free the entire list
void free_list(struct Student *head) {
    struct Student *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    struct Student *head = NULL;
    int choice, roll;
    char name[NAME_LEN];
    float score;

    do {
        printf("\n--- Student Record Menu ---\n");
        printf("1. Add Student\n");
        printf("2. Delete Student\n");
        printf("3. Display Students\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter roll: ");
                scanf("%d", &roll);
                printf("Enter name: ");
                scanf("%s", name);   // no spaces in name
                printf("Enter score: ");
                scanf("%f", &score);
                add_student(&head, roll, name, score);
                break;
            case 2:
                printf("Enter roll to delete: ");
                scanf("%d", &roll);
                delete_student(&head, roll);
                break;
            case 3:
                display_students(head);
                break;
            case 4:
                free_list(head);
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 4);

    return 0;
}
