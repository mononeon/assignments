#include <iostream>
using namespace std;

void f(int a, int b) { printf("f(int,int)\n"); }
void f(char a, int b) { printf("f(char,int)\n"); }

int main() {
    f(5, 'A');
    f('B', 'C');
    f(3.5, 4.5);
    return 0;
}
