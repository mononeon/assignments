#include <stdio.h>
#include <math.h>
#define EPSILON 0.0001

// Function to find the root
float func(float x) {
    return x*x*x - x*x + 2;
}

void bisectionMethod(float a, float b) {
    if (func(a) * func(b) >= 0) {
        printf("Incorrect initial guesses.\n");
        return;
    }
    float c;
    while ((b - a) >= EPSILON) {
        c = (a + b) / 2;
        if (func(c) == 0.0)
            break;
        else if (func(c) * func(a) < 0)
            b = c;
        else
            a = c;
    }
    printf("Root (Bisection Method): %f\n", c);
}

void regulaFalsiMethod(float a, float b) {
    if (func(a) * func(b) >= 0) {
        printf("Incorrect initial guesses.\n");
        return;
    }
    float c;
    for (int i = 0; i < 100; i++) {
        c = (a * func(b) - b * func(a)) / (func(b) - func(a));
        if (fabs(func(c)) < EPSILON)
            break;
        else if (func(c) * func(a) < 0)
            b = c;
        else
            a = c;
    }
    printf("Root (Regula Falsi Method): %f\n", c);
}

void newtonRaphsonMethod(float x) {
    float h, f, df;
    do {
        f = func(x);
        df = 3*x*x - 2*x; // Derivative of func(x)
        if (df == 0) {
            printf("Mathematical error, derivative is zero.\n");
            return;
        }
        h = f / df;
        x = x - h;
    } while (fabs(h) >= EPSILON);
    printf("Root (Newton-Raphson Method): %f\n", x);
}

int main() {
    int choice;
    float a, b, x0;
    do {
        printf("\nRoot Finding Methods\n");
        printf("1. Bisection Method\n2. Regula Falsi Method\n3. Newton-Raphson Method\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter two initial guesses: ");
                scanf("%f %f", &a, &b);
                bisectionMethod(a, b);
                break;
            case 2:
                printf("Enter two initial guesses: ");
                scanf("%f %f", &a, &b);
                regulaFalsiMethod(a, b);
                break;
            case 3:
                printf("Enter initial guess: ");
                scanf("%f", &x0);
                newtonRaphsonMethod(x0);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 4);
    return 0;
}
