#include <iostream>
using namespace std;

void swap(int &a, int &b) {
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
}

int main() {
    int a, b;
    cout << "Enter two numbers:\na = ";
    cin >> a;
    cout << "b = ";
    cin >> b;
    swap(a, b);
    cout << "Numbers after swapping: \na = " << a << "\nb = " << b << "\n";
    return 0;
}
