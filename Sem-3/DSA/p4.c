/* Q4_user_input.c : Add two polynomials using linked list (user input) */
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coeff;
    int exp;
    struct Node *next;
};

// Create new node
struct Node* newNode(int coeff, int exp) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->coeff = coeff;
    node->exp = exp;
    node->next = NULL;
    return node;
}

// Insert at end
void insert(struct Node** head, int coeff, int exp) {
    struct Node* node = newNode(coeff, exp);
    if (*head == NULL) {
        *head = node;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) temp = temp->next;
    temp->next = node;
}

// Print polynomial
void printPoly(struct Node* poly) {
    while (poly != NULL) {
        printf("%dx^%d", poly->coeff, poly->exp);
        poly = poly->next;
        if (poly != NULL) printf(" + ");
    }
    printf("\n");
}

// Add two polynomials
struct Node* addPoly(struct Node* p1, struct Node* p2) {
    struct Node* result = NULL;

    while (p1 != NULL && p2 != NULL) {
        if (p1->exp > p2->exp) {
            insert(&result, p1->coeff, p1->exp);
            p1 = p1->next;
        }
        else if (p2->exp > p1->exp) {
            insert(&result, p2->coeff, p2->exp);
            p2 = p2->next;
        }
        else {
            insert(&result, p1->coeff + p2->coeff, p1->exp);
            p1 = p1->next;
            p2 = p2->next;
        }
    }

    while (p1 != NULL) {
        insert(&result, p1->coeff, p1->exp);
        p1 = p1->next;
    }

    while (p2 != NULL) {
        insert(&result, p2->coeff, p2->exp);
        p2 = p2->next;
    }

    return result;
}

int main() {
    struct Node* poly1 = NULL;
    struct Node* poly2 = NULL;
    int n1, n2, coeff, exp;

    // Input polynomial 1
    printf("Enter number of terms in polynomial 1: ");
    scanf("%d", &n1);
    printf("Enter terms in descending order of exponent (coeff exp):\n");
    for (int i = 0; i < n1; i++) {
        scanf("%d %d", &coeff, &exp);
        insert(&poly1, coeff, exp);
    }

    // Input polynomial 2
    printf("Enter number of terms in polynomial 2: ");
    scanf("%d", &n2);
    printf("Enter terms in descending order of exponent (coeff exp):\n");
    for (int i = 0; i < n2; i++) {
        scanf("%d %d", &coeff, &exp);
        insert(&poly2, coeff, exp);
    }

    printf("\nPolynomial 1: ");
    printPoly(poly1);

    printf("Polynomial 2: ");
    printPoly(poly2);

    struct Node* sum = addPoly(poly1, poly2);
    printf("Sum: ");
    printPoly(sum);

    return 0;
}
