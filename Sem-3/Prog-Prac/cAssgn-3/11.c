#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node* insert(struct Node* head,int x) {
    struct Node* n=malloc(sizeof(struct Node));
    n->data=x; n->next=head;
    return n;
}
void display(struct Node* head) {
    while(head) {
        printf("%d ",head->data);
        head=head->next;
    }
    printf("\n");
}
