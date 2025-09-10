/* Q5.c : Evaluate postfix expression */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int x) {
    stack[++top] = x;
}

int pop() {
    return stack[top--];
}

int main() {
    char exp[MAX];
    printf("Enter postfix expression: ");
    fgets(exp, MAX, stdin);

    for (int i = 0; i < strlen(exp); i++) {
        if (isspace(exp[i])) continue;  // skip spaces

        // If operand → push it
        if (isdigit(exp[i])) {
            push(exp[i] - '0');  // convert char to int
        }
        // If operator → pop two operands and apply
        else if (exp[i]=='+' || exp[i]=='-' || exp[i]=='*' || exp[i]=='/' || exp[i]=='^') {
            int b = pop();
            int a = pop();
            switch (exp[i]) {
                case '+': push(a + b); break;
                case '-': push(a - b); break;
                case '*': push(a * b); break;
                case '/': push(a / b); break;
                case '^': {
                    int res = 1;
                    for (int j=0; j<b; j++) res *= a;
                    push(res);
                    break;
                }
            }
        }
    }

    printf("Result = %d\n", pop());
    return 0;
}
