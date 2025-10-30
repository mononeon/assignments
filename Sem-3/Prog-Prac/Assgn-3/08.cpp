#include <bits/stdc++.h>
using namespace std;

class STACK {
private:
    int capacity;
    int top;
    int *data;
    //vector<T> data;
public:
    STACK(int cap) {
        capacity = cap;
        data = new int[capacity];
        top = -1;
    }
    ~STACK() {
        delete[] data;
    }

    bool isEmpty() { return top == -1; }
    bool isFull() { return top >= capacity - 1; }

    bool push(int x) {
        if (isFull()) {
            cout << "Overflow: cannot push\n";
            return false;
        }
        data[++top] = x;
        return true;
    }
    int pop() {
        if (isEmpty()) {
            cout << "Underflow: cannot pop\n";
            return 0;
        }
        cout << data[top] << " is popped from stack\n";
        return data[top--];
    }
    void display() {
        if (isEmpty()) cout << "Stack is empty\n";
        cout << "The top element is " << data[top] << "\n";
    }
};

int main() {
    int max_limit;
    cout << "Enter max size limit of the stack: ";
    cin >> max_limit;
    STACK st(max_limit);
    while (true) {
        cout << "\nSTACK MENU:\n1. Push\n2. Pop\n3. Display\n4. Exit\n"
             << "Choose: ";
        int ch; if (!(cin >> ch)) return 0;
        switch (ch) {
            case 1: {
                int x; cout << "Enter value to push: "; cin >> x;
                st.push(x);
                break;
            }
            case 2: {
                st.pop();
                break;
            }
            case 3: {
                st.display();
                break;
            }
            case 4: return 0;
            default: cout << "Invalid option\n";
        }
    }
}