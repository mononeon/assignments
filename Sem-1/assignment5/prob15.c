#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Contact {
    char name[50];
    char phoneNumbers[5][15];
    int numCount;
};
 
void addContact(struct Contact contacts[], int *count) {
    if (*count >= 100) {
        printf("Directory is full.\n");
        return;
    }
 
    printf("Enter name: ");
    scanf("%s", contacts[*count].name);
 
    printf("Enter number of phone numbers (up to 5): ");
    int numCount;
    scanf("%d", &numCount);
 
    for (int i = 0; i < numCount; i++) {
        printf("Enter phone number %d: ", i + 1);
        scanf("%s", contacts[*count].phoneNumbers[i]);
    }
 
    contacts[*count].numCount = numCount;
    (*count)++;
}
 
void deleteContact(struct Contact contacts[], int *count, char *name) {
    for (int i = 0; i < *count; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            for (int j = i; j < *count - 1; j++) {
                contacts[j] = contacts[j + 1];
            }
            (*count)--;
            printf("Contact deleted.\n");
            return;
        }
    }
    printf("Contact not found.\n");
}
 
void searchContact(struct Contact contacts[], int count, char *name) {
    for (int i = 0; i < count; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            printf("Name: %s\n", contacts[i].name);
            for (int j = 0; j < contacts[i].numCount; j++) {
                printf("Phone Number %d: %s\n", j + 1, contacts[i].phoneNumbers[j]);
            }
            return;
        }
    }
    printf("Contact not found.\n");
}
 
void browseContacts(struct Contact contacts[], int count) {
    for (int i = 0; i < count; i++) {
        printf("Name: %s\n", contacts[i].name);
        for (int j = 0; j < contacts[i].numCount; j++) {
            printf("Phone Number %d: %s\n", j + 1, contacts[i].phoneNumbers[j]);
        }
        printf("\n");
    }
}
 
int main() {
    struct Contact contacts[100];
    int count = 0;
    int choice;
    char name[50];
 
    while (1) {
        printf("1. Add Contact\n");
        printf("2. Delete Contact\n");
        printf("3. Search Contact\n");
        printf("4. Browse Contacts\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
 
        switch (choice) {
            case 1:
                addContact(contacts, &count);
                break;
            case 2:
                printf("Enter name to delete: ");
                scanf("%s", name);
                deleteContact(contacts, &count, name);
                break;
            case 3:
                printf("Enter name to search: ");
                scanf("%s", name);
                searchContact(contacts, count, name);
                break;
            case 4:
                browseContacts(contacts, count);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
 
    return 0;
}
