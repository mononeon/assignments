#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int d) { data = d; next = NULL; }
};

class LinkedList {
    Node* head;

public:
    LinkedList() { head = NULL; }

    void insert(int val) {
        Node* newNode = new Node(val);
        if (!head) head = newNode;
        else {
            Node* temp = head;
            while (temp->next) temp = temp->next;
            temp->next = newNode;
        }
    }

    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }

    void remove(int val) {
        Node *temp = head, *prev = NULL;
        while (temp && temp->data != val) {
            prev = temp;
            temp = temp->next;
        }
        if (!temp) { cout << "Not found!\n"; return; }
        if (!prev) head = head->next;
        else prev->next = temp->next;
        delete temp;
    }
};

int main() {
    LinkedList list;
    int ch, val;
    do {
        cout << "\n=== Linked List Menu ===\n"
             << "1. Insert\n"
             << "2. Delete\n"
             << "3. Display\n"
             << "4. Exit\n"
             << "Choice: ";
        cin >> ch;
        switch (ch) {
            case 1: {
                cout << "Enter value: ";
                cin >> val;
                list.insert(val);
                break;
            }
            case 2: {
                cout << "Enter value to delete: ";
                cin >> val;
                list.remove(val);
                break;
            }
            case 3: list.display(); break;
        }
    } while (ch != 4);
    return 0;
}
