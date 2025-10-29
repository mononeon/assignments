#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *next;
    Node(int d): data(d), next(nullptr) {}
};

class LinkedList {
private:
    Node *head;
    size_t list_size;

public:
    LinkedList(): head(nullptr), list_size(0) {}
    ~LinkedList() {
        Node* cur = head;
        while (cur) {
            Node* tmp = cur;
            cur = cur->next;
            delete tmp;
        }
    }

    void insertFront(int val) {
        Node* n = new Node(val);
        n->next = head;
        head = n;
        ++list_size;
    }

    void insertBack(int val) {
        Node* n = new Node(val);
        if (!head) head = n;
        else {
            Node* cur = head;
            while (cur->next) cur = cur->next;
            cur->next = n;
        }
        ++list_size;
    }

    bool deleteByValue(int val) {
        Node* cur = head;
        Node* prev = nullptr;
        while (cur) {
            if (cur->data == val) {
                if (prev) prev->next = cur->next;
                else head = cur->next;
                delete cur;
                --list_size;
                return true;
            }
            prev = cur;
            cur = cur->next;
        }
        return false;
    }

    bool search(int val) const {
        Node* cur = head;
        while (cur) {
            if (cur->data == val) return true;
            cur = cur->next;
        }
        return false;
    }

    void display() const {
        if (!head) { cout << "List is empty.\n"; return; }
        Node* cur = head;
        cout << "Head -> ";
        while (cur) {
            cout << cur->data;
            if (cur->next) cout << " -> ";
            cur = cur->next;
        }
        cout << " -> NULL\n";
    }

    size_t size() const { return list_size; }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    LinkedList list;

    while (true) {
        cout << "\nLINKED LIST MENU\n"
             << "1. Insert front\n"
             << "2. Insert back\n"
             << "3. Delete by value\n"
             << "4. Search value\n"
             << "5. Display list\n"
             << "6. Show size\n"
             << "7. Exit\n"
             << "Choose: ";

        int ch;
        if (!(cin >> ch)) break;

        switch (ch) {
            case 1: {
                int v; cout << "Value: "; cin >> v;
                list.insertFront(v);
                cout << "Inserted at front.\n";
                break;
            }
            case 2: {
                int v; cout << "Value: "; cin >> v;
                list.insertBack(v);
                cout << "Inserted at back.\n";
                break;
            }
            case 3: {
                int v; cout << "Value to delete: "; cin >> v;
                if (list.deleteByValue(v)) cout << "Deleted.\n"; else cout << "Value not found.\n";
                break;
            }
            case 4: {
                int v; cout << "Value to search: "; cin >> v;
                cout << (list.search(v) ? "Found.\n" : "Not found.\n");
                break;
            }
            case 5:
                list.display();
                break;
            case 6:
                cout << "Size: " << list.size() << '\n';
                break;
            case 7:
                cout << "Exiting.\n";
                return 0;
            default:
                cout << "Invalid option.\n";
        }
    }
    return 0;
}