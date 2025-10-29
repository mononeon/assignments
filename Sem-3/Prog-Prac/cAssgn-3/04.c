#include <stdio.h>

void f_int(int x) { printf("inside f(int)\n"); }
void f_float(float x) { printf("inside f(float)\n"); }

int main() {
    int a=5; char c='A'; float f=3.2; double d=4.5;

    f_int(a);
    f_int(c);    // char promoted to int
    f_float(f);
    f_float((float)d); // must cast double -> float
    return 0;
}
