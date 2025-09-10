/* ADT List using Linked List */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

// Create from file
void createList(char *filename) {
    FILE *fp = fopen(filename, "r");
    if (!fp) {
        printf("Error opening file!\n");
        return;
    }
    int val;
    struct Node *tail = NULL;
    while (fscanf(fp, "%d", &val) != EOF) {
        struct Node *node = (struct Node*)malloc(sizeof(struct Node));
        node->data = val;
        node->next = NULL;
        if (!head) head = tail = node;
        else { tail->next = node; tail = node; }
    }
    fclose(fp);
    printf("List created.\n");
}

int length() {
    int cnt = 0;
    struct Node *temp = head;
    while (temp) { cnt++; temp = temp->next; }
    return cnt;
}

void printList(int dir) {
    if (dir == 1) {
        struct Node *temp = head;
        while (temp) { printf("%d ", temp->data); temp = temp->next; }
    } else {
        // For right-to-left, recursive print
        struct Node *temp = head;
        if (!temp) return;
        if (temp->next) printList(dir);
        printf("%d ", temp->data);
        return;
    }
    printf("\n");
}

int retrieve(int idx) {
    struct Node *temp = head;
    int i = 0;
    while (temp && i < idx) { temp = temp->next; i++; }
    if (!temp) return -1;
    return temp->data;
}

void store(int x, int idx) {
    struct Node *temp = head;
    int i = 0;
    while (temp && i < idx) { temp = temp->next; i++; }
    if (!temp) { printf("Invalid index!\n"); return; }
    temp->data = x;
}

void insert(int x, int idx) {
    struct Node *node = (struct Node*)malloc(sizeof(struct Node));
    node->data = x;
    if (idx == 0) {
        node->next = head;
        head = node;
        return;
    }
    struct Node *temp = head;
    int i = 0;
    while (temp && i < idx - 1) { temp = temp->next; i++; }
    if (!temp) { printf("Invalid index!\n"); free(node); return; }
    node->next = temp->next;
    temp->next = node;
}

void deleteElem(int idx) {
    if (!head) return;
    struct Node *temp = head;
    if (idx == 0) {
        head = head->next;
        free(temp);
        return;
    }
    int i = 0;
    struct Node *prev = NULL;
    while (temp && i < idx) { prev = temp; temp = temp->next; i++; }
    if (!temp) { printf("Invalid index!\n"); return; }
    prev->next = temp->next;
    free(temp);
}

int search(int x) {
    struct Node *temp = head;
    int idx = 0;
    while (temp) {
        if (temp->data == x) return idx;
        temp = temp->next; idx++;
    }
    return -1;
}

int main() {
    int choice, x, i;
    char filename[50];

    printf("Enter input filename: ");
    scanf("%s", filename);
    createList(filename);

    while (1) {
        printf("\n--- Menu (Linked List) ---\n");
        printf("1. Length\n2. PrintList\n3. Retrieve\n4. Store\n5. Insert\n6. Delete\n7. Search\n8. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Length = %d\n", length());
            break;
        case 2:
            printf("1. Left-to-right, 2. Right-to-left: ");
            scanf("%d", &x);
            printList(x);
            break;
        case 3:
            printf("Enter index: ");
            scanf("%d", &i);
            printf("Element = %d\n", retrieve(i));
            break;
        case 4:
            printf("Enter index and new value: ");
            scanf("%d %d", &i, &x);
            store(x, i);
            break;
        case 5:
            printf("Enter index and value to insert: ");
            scanf("%d %d", &i, &x);
            insert(x, i);
            break;
        case 6:
            printf("Enter index to delete: ");
            scanf("%d", &i);
            deleteElem(i);
            break;
        case 7:
            printf("Enter value to search: ");
            scanf("%d", &x);
            i = search(x);
            if (i == -1) printf("Not found\n");
            else printf("Found at index %d\n", i);
            break;
        case 8:
            exit(0);
        }
    }
}
