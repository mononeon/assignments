#include <iostream>
#include <cstring>
using namespace std;

struct Item {
    int code;
    char name[50];
    float rate;
    int quantity;
};

class ItemList {
    Item items[100];
    int count;

public:
    ItemList() { count = 0; }

    void addItem() {
        Item it;
        cout << "Enter item code: "; cin >> it.code;
        for (int i = 0; i < count; ++i)
            if (items[i].code == it.code) {
                cout << "Item code already exists!\n";
                return;
            }
        cin.ignore();
        cout << "Enter item name: "; cin.getline(it.name, 50);
        cout << "Enter rate: "; cin >> it.rate;
        cout << "Enter quantity: "; cin >> it.quantity;
        items[count++] = it;
    }

    void updateRate() {
        int code; cout << "Enter item code: "; cin >> code;
        for (int i = 0; i < count; ++i)
            if (items[i].code == code) {
                cout << "Enter new rate: "; cin >> items[i].rate; return;
            }
        cout << "Item not found!\n";
    }

    void issueItem() {
        int code, qty;
        cout << "Enter code and quantity: ";
        cin >> code >> qty;
        for (int i = 0; i < count; ++i)
            if (items[i].code == code) {
                if (items[i].quantity < qty) cout << "Not enough stock!\n";
                else items[i].quantity -= qty;
                return;
            }
        cout << "Item not found!\n";
    }

    void receiveItem() {
        int code, qty; cout << "Enter code and quantity: "; cin >> code >> qty;
        for (int i = 0; i < count; ++i)
            if (items[i].code == code) {
                items[i].quantity += qty; return;
            }
        cout << "Item not found!\n";
    }

    void showItem() {
        int code; cout << "Enter code: "; cin >> code;
        for (int i = 0; i < count; ++i)
            if (items[i].code == code) {
                cout << items[i].name << ": Rate " << items[i].rate
                     << ", Qty " << items[i].quantity << "\n";
                return;
            }
        cout << "Item not found!\n";
    }

    void displayAll() {
        for (int i = 0; i < count; ++i)
            cout << items[i].code << " " << items[i].name
                 << " " << items[i].rate << " " << items[i].quantity << "\n";
    }
};

int main() {
    ItemList L;
    int ch;
    do {
        cout << "\n=== Item List Menu ===\n"
             << "1. Add Item\n"
             << "2. Update Rate\n"
             << "3. Issue Item\n"
             << "4. Receive Item\n"
             << "5. Show Item\n"
             << "6. Display All\n"
             << "7. Exit\n"
             << "Choice: ";
        cin >> ch;
        switch (ch) {
        case 1: L.addItem(); break;
        case 2: L.updateRate(); break;
        case 3: L.issueItem(); break;
        case 4: L.receiveItem(); break;
        case 5: L.showItem(); break;
        case 6: L.displayAll(); break;
        }
    } while (ch != 7);
    return 0;
}
