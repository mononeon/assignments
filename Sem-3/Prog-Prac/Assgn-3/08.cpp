#include <bits/stdc++.h>
using namespace std;

template<typename T>
class Stack {
private:
    vector<T> data;
    size_t capacity;
public:
    explicit Stack(size_t cap = 100) : capacity(cap) { data.reserve(cap); }
    bool push(const T &x) {
        if (data.size() >= capacity) {
            cout << "Overflow: cannot push\n";
            return false;
        }
        data.push_back(x);
        return true;
    }
    bool pop(T &out) {
        if (data.empty()) {
            cout << "Underflow: cannot pop\n";
            return false;
        }
        out = data.back();
        data.pop_back();
        return true;
    }
    bool isEmpty() const { return data.empty(); }
    bool isFull() const { return data.size() >= capacity; }
    void display() const {
        cout << "Top -> ";
        for (auto it = data.rbegin(); it != data.rend(); ++it) cout << *it << " ";
        cout << "\n";
    }
};

int main() {
    Stack<int> st;
    while (true) {
        cout << "\nSTACK MENU:\n1. Push\n2. Pop\n3. Display\n4. Exit\nChoose: ";
        int ch; if (!(cin >> ch)) return 0;
        switch (ch) {
            case 1: {
                int x; cout << "Enter value to push: "; cin >> x; st.push(x); break;
            }
            case 2: {
                int out; if (st.pop(out)) cout << "Popped: " << out << '\n'; break;
            }
            case 3: st.display(); break;
            case 4: return 0;
            default: cout << "Invalid option\n";
        }
    }
}