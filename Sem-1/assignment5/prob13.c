#include <stdio.h>
#include <stdlib.h>
 
struct Node {
    int data;
    struct Node *next;
};  
 
struct Stack {
    struct Node *top;
};
 
void push(struct Stack *stack, int data) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = stack->top;
    stack->top = newNode;
}
 
int pop(struct Stack *stack) {
    if (stack->top == NULL) {
        printf("Stack underflow.\n");
        return -1;
    }
 
    struct Node *temp = stack->top;
    int data = temp->data;
    stack->top = temp->next;
    free(temp);
    return data;
}
 
int main() {
    struct Stack stack = {NULL};
 
    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);
 
    printf("Popped: %d\n", pop(&stack));
    printf("Popped: %d\n", pop(&stack));
    printf("Popped: %d\n", pop(&stack));
 
    return 0;
}