#include <stdio.h>

void f_int_int(int a, int b) { printf("f(int,int)\n"); }
void f_char_int(char a, int b) { printf("f(char,int)\n"); }

int main() {
    f_int_int(5, 'A');      // char promoted to int
    f_char_int('B', 'C');   // matches (char,int)
    f_int_int((int)3.5, (int)4.5); // float → int
    return 0;
}
