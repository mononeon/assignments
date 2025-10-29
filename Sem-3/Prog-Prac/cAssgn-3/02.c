#include <stdio.h>

int* maxVal(int *a, int *b) {
    return (*a > *b) ? a : b;
}

int main() {
    int a=10, b=20;

    // case i: copy
    int x = *maxVal(&a,&b);
    x += 5;
    printf("x=%d a=%d b=%d\n",x,a,b);

    // case ii: pointer (like reference)
    int *y = maxVal(&a,&b);
    *y += 5;
    printf("y=%d a=%d b=%d\n",*y,a,b);

    return 0;
}
