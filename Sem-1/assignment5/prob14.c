#include <stdio.h>
#include <stdlib.h>
 
struct Node {
    int data;
    struct Node *next;
};
 
void reverseList(struct Node **head) {
    struct Node *prev = NULL, *current = *head, *next = NULL;
 
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
 
    *head = prev;
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
    head = (struct Node *)malloc(sizeof(struct Node));
    head->data = 10;
    head->next = (struct Node *)malloc(sizeof(struct Node));
    head->next->data = 20;
    head->next->next = (struct Node *)malloc(sizeof(struct Node));
    head->next->next->data = 30;
    head->next->next->next = NULL;
 
    printf("Original List: ");
    traverseList(head);
 
    reverseList(&head);
 
    printf("Reversed List: ");
    traverseList(head);
 
    return 0;
}