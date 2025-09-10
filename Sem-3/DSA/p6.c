/* Q6.c : Convert postfix expression to infix */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

// Stack of strings
char stack[MAX][MAX];
int top = -1;

void push(char *str) {
    strcpy(stack[++top], str);
}

char* pop() {
    return stack[top--];
}

int main() {
    char exp[MAX];
    printf("Enter postfix expression: ");
    fgets(exp, MAX, stdin);

    for (int i = 0; i < strlen(exp); i++) {
        if (isspace(exp[i])) continue;  // skip spaces

        // If operand → push as string
        if (isalnum(exp[i])) {
            char op[2] = {exp[i], '\0'};
            push(op);
        }
        // If operator → pop two operands, combine
        else if (exp[i]=='+' || exp[i]=='-' || exp[i]=='*' || exp[i]=='/' || exp[i]=='^') {
            char op2[MAX], op1[MAX], res[MAX];
            strcpy(op2, pop());
            strcpy(op1, pop());
            sprintf(res, "(%s%c%s)", op1, exp[i], op2);
            push(res);
        }
    }

    printf("Infix expression: %s\n", pop());
    return 0;
}
