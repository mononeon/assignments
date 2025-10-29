#include <bits/stdc++.h>
using namespace std;

class IntArray {
private:
    size_t n;
    int *data;
public:
    // constructors
    IntArray(size_t size = 0, int initVal = 0): n(size) {
        if (n) data = new int[n];
        else data = nullptr;
        for (size_t i = 0; i < n; ++i) data[i] = initVal;
    }

    // construct from C array
    IntArray(const int arr[], size_t size): n(size) {
        if (n) data = new int[n];
        else data = nullptr;
        for (size_t i = 0; i < n; ++i) data[i] = arr[i];
    }

    // copy constructor (from another object)
    IntArray(const IntArray &o): n(o.n) {
        if (n) data = new int[n];
        else data = nullptr;
        for (size_t i = 0; i < n; ++i) data[i] = o.data[i];
    }

    // assignment
    IntArray& operator=(const IntArray &o) {
        if (this == &o) return *this;
        delete[] data;
        n = o.n;
        if (n) data = new int[n];
        else data = nullptr;
        for (size_t i = 0; i < n; ++i) data[i] = o.data[i];
        return *this;
    }

    ~IntArray() { delete[] data; }

    size_t size() const { return n; }

    // element access
    int& operator[](size_t i) {
        if (i >= n) throw out_of_range("Index out of range");
        return data[i];
    }
    const int& operator[](size_t i) const {
        if (i >= n) throw out_of_range("Index out of range");
        return data[i];
    }

    // elementwise addition (sizes must match)
    IntArray operator+(const IntArray &o) const {
        if (n != o.n) throw runtime_error("Array sizes mismatch");
        IntArray res(n);
        for (size_t i = 0; i < n; ++i) res.data[i] = data[i] + o.data[i];
        return res;
    }

    // scalar multiply (array * scalar)
    IntArray operator*(int s) const {
        IntArray res(n);
        for (size_t i = 0; i < n; ++i) res.data[i] = data[i] * s;
        return res;
    }

    // friend: scalar * array
    friend IntArray operator*(int s, const IntArray &a) {
        return a * s;
    }

    void show() const {
        cout << "[";
        for (size_t i = 0; i < n; ++i) {
            cout << data[i];
            if (i + 1 < n) cout << ", ";
        }
        cout << "]\n";
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    IntArray a(5, 1);
    IntArray b(5, 2);
    int carr[] = {10,20,30,40,50};
    IntArray c(carr, 5);

    while (true) {
        cout << "\nINT ARRAY MENU\n1. Show arrays (a,b,c)\n2. a + b\n3. a = c (assignment)\n4. a[2] = 99 (example)\n5. a * 5\n6. 5 * c\n7. Exit\nChoose: ";
        int ch; if (!(cin >> ch)) break;
        try {
            switch (ch) {
                case 1: cout << "a = "; a.show(); cout << "b = "; b.show(); cout << "c = "; c.show(); break;
                case 2: { IntArray d = a + b; cout << "a+b = "; d.show(); break; }
                case 3: a = c; cout << "Assigned a = c\n"; break;
                case 4: a[2] = 99; cout << "Set a[2]=99\n"; break;
                case 5: { IntArray d = a * 5; cout << "a*5 = "; d.show(); break; }
                case 6: { IntArray d = 5 * c; cout << "5*c = "; d.show(); break; }
                case 7: return 0;
                default: cout << "Invalid.\n";
            }
        } catch (const exception &e) {
            cout << "Error: " << e.what() << "\n";
        }
    }
    return 0;
}