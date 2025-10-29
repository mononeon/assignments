#include <iostream>
using namespace std;

int& max(int &a, int &b) {
    return (a > b) ? a : b;
}

int main() {
    int a, b;
    cout << "Enter two numbers:\na = ";
    cin >> a;
    cout << "b = ";
    cin >> b;
    // (i) x is a variable (copy)
    int x = max(a, b);
    cout << "Larger value stored in x (copy): x = " << x << "\n";
    x = x + 7;
    cout << "After modifying x (copy) [x = x + 7]: x = " << x << "\n";
    cout << "a = " << a << ", b = " << b << "\n";
    // (ii) x is a reference
    int &y = max(a, b);
    cout << "Larger value stored in y (reference): y = " << y << "\n";
    y = y + 7;
    cout << "After modifying y (reference) [y = y + 7]: y = " << y << "\n";
    cout << "a = " << a << ", b = " << b << "\n";
}
