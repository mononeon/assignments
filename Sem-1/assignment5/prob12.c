#include <stdio.h>
#include <stdlib.h>
 
struct Node {
    int data;
    struct Node *next;
};
 
void addAtBeginning(struct Node **head, int data) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}
 
void addAtEnd(struct Node **head, int data) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
 
    if (*head == NULL) {
        *head = newNode;
        return;
    }
 
    struct Node *temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}
 
void deleteNode(struct Node **head, int key) {
    struct Node *temp = *head, *prev = NULL;
 
    if (temp != NULL && temp->data == key) {
        *head = temp->next;
        free(temp);
        return;
    }
 
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }
 
    if (temp == NULL) return;
 
    prev->next = temp->next;
    free(temp);
}
 
void traverseList(struct Node *head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}
 
int main() {
    struct Node *head = NULL;
 
    addAtBeginning(&head, 10);
    addAtEnd(&head, 20);
    addAtEnd(&head, 30);
    traverseList(head);
 
    deleteNode(&head, 20);
    traverseList(head);
 
    return 0;
}