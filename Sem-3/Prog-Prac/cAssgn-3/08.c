#include <stdio.h>
#define SIZE 5

struct Stack {
    int arr[SIZE];
    int top;
};

void init(struct Stack *s) { s->top=-1; }
void push(struct Stack *s,int x) {
    if(s->top==SIZE-1) printf("Overflow\n");
    else s->arr[++s->top]=x;
}
void pop(struct Stack *s) {
    if(s->top==-1) printf("Underflow\n");
    else printf("Popped %d\n",s->arr[s->top--]);
}
