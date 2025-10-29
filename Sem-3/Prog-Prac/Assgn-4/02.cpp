#include <bits/stdc++.h>
using namespace std;

class Complex {
private:
    long long real;
    long long imag;
public:
    Complex(long long r = 0, long long i = 0): real(r), imag(i) {}

    // input and output
    void read() {
        cout << "Enter real part: "; cin >> real;
        cout << "Enter imag part: "; cin >> imag;
    }
    void show() const {
        cout << real << (imag >= 0 ? " + " : " - ") << llabs(imag) << "i\n";
    }

    // operators
    Complex operator+(const Complex &o) const {
        return Complex(real + o.real, imag + o.imag);
    }
    Complex operator-(const Complex &o) const {
        return Complex(real - o.real, imag - o.imag);
    }

    // optional: stream operators
    friend ostream &operator<<(ostream &os, const Complex &c) {
        os << c.real << (c.imag >= 0 ? " + " : " - ") << llabs(c.imag) << "i";
        return os;
    }
    friend istream &operator>>(istream &is, Complex &c) {
        // simple format: two integers separated by space
        is >> c.real >> c.imag;
        return is;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Complex a, b;
    while (true) {
        cout << "\nCOMPLEX MENU\n1. Read complex A\n2. Read complex B\n3. Show A and B\n4. A + B\n5. A - B\n6. Exit\nChoose: ";
        int ch; if (!(cin >> ch)) break;
        switch (ch) {
            case 1: a.read(); break;
            case 2: b.read(); break;
            case 3: cout << "A = "; a.show(); cout << "B = "; b.show(); break;
            case 4: { Complex c = a + b; cout << "A+B = "; c.show(); break; }
            case 5: { Complex c = a - b; cout << "A-B = "; c.show(); break; }
            case 6: return 0;
            default: cout << "Invalid.\n";
        }
    }
    return 0;
}