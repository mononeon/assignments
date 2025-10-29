#include <iostream>
using namespace std;

void f(int x) { cout << "inside f(int)\n"; }
void f(float x) { cout << "inside f(float)\n"; }

int main() {
    int at = 5;
    char ct = 'A';
    float ft = 3.2;
    double dt = 4.5;

    f(at);
    f(ct);
    f(dt);
    f(ft);
    f(at);
    f(ct);
    f(ft);
    f(dt);
    return 0;
}
