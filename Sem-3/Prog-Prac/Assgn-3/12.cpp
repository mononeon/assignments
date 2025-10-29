#include <bits/stdc++.h>
using namespace std;

struct Item {
    string code;
    string name;
    double rate = 0.0;
    int quantity = 0;
};

class ItemList {
private:
    unordered_map<string, Item> items;

public:
    bool addItem(const Item &it) {
        if (items.find(it.code) != items.end()) return false;
        items[it.code] = it;
        return true;
    }

    void addItemInteractive() {
        Item it;
        cout << "Enter item code: ";
        cin >> it.code;
        if (items.find(it.code) != items.end()) {
            cout << "Error: item code '" << it.code << "' already exists.\n";
            return;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Enter item name: ";
        getline(cin, it.name);
        cout << "Enter rate: ";
        if (!(cin >> it.rate)) { cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n'); cout << "Invalid rate\n"; return; }
        cout << "Enter quantity: ";
        if (!(cin >> it.quantity)) { cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n'); cout << "Invalid quantity\n"; return; }
        items[it.code] = it;
        cout << "Item added.\n";
    }

    bool updateRate(const string &code, double newRate) {
        auto it = items.find(code);
        if (it == items.end()) return false;
        it->second.rate = newRate;
        return true;
    }

    bool issueItem(const string &code, int qty) {
        auto it = items.find(code);
        if (it == items.end()) return false;
        if (qty <= 0) return false;
        if (it->second.quantity < qty) return false;
        it->second.quantity -= qty;
        return true;
    }

    bool receiveItem(const string &code, int qty) {
        auto it = items.find(code);
        if (it == items.end()) return false;
        if (qty <= 0) return false;
        it->second.quantity += qty;
        return true;
    }

    bool getPriceAndQuantity(const string &code, double &rateOut, int &qtyOut) const {
        auto it = items.find(code);
        if (it == items.end()) return false;
        rateOut = it->second.rate;
        qtyOut  = it->second.quantity;
        return true;
    }

    void showAll() const {
        if (items.empty()) { cout << "Inventory is empty.\n"; return; }
        cout << left << setw(12) << "Code" << setw(24) << "Name" << setw(10) << "Rate" << setw(10) << "Qty" << "\n";
        cout << string(56, '-') << "\n";
        for (const auto &p : items) {
            const Item &it = p.second;
            cout << left << setw(12) << it.code << setw(24) << it.name
                 << setw(10) << fixed << setprecision(2) << it.rate
                 << setw(10) << it.quantity << "\n";
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ItemList inv;
    while (true) {
        cout << "\nITEM LIST MENU\n"
             << "1. Add item\n"
             << "2. Update rate\n"
             << "3. Issue item (reduce qty)\n"
             << "4. Receive item (increase qty)\n"
             << "5. Show price & quantity for an item\n"
             << "6. Show all items\n"
             << "7. Exit\n"
             << "Choose: ";
        int ch;
        if (!(cin >> ch)) break;
        switch (ch) {
            case 1:
                inv.addItemInteractive();
                break;
            case 2: {
                string code; double nr;
                cout << "Enter code: "; cin >> code;
                cout << "Enter new rate: "; if (!(cin >> nr)) { cout << "Invalid rate\n"; break; }
                if (!inv.updateRate(code, nr)) cout << "Item not found.\n"; else cout << "Rate updated.\n";
                break;
            }
            case 3: {
                string code; int q;
                cout << "Enter code: "; cin >> code;
                cout << "Enter qty to issue: "; if (!(cin >> q)) { cout << "Invalid qty\n"; break; }
                if (inv.issueItem(code, q)) cout << "Issued " << q << " of " << code << ".\n";
                else cout << "Issue failed (item not found or insufficient qty).\n";
                break;
            }
            case 4: {
                string code; int q;
                cout << "Enter code: "; cin >> code;
                cout << "Enter qty to receive: "; if (!(cin >> q)) { cout << "Invalid qty\n"; break; }
                if (inv.receiveItem(code, q)) cout << "Received " << q << " of " << code << ".\n";
                else cout << "Receive failed (item not found).\n";
                break;
            }
            case 5: {
                string code; cout << "Enter code: "; cin >> code;
                double r; int q;
                if (inv.getPriceAndQuantity(code, r, q)) cout << "Rate: " << fixed << setprecision(2) << r << " | Qty: " << q << "\n";
                else cout << "Item not found.\n";
                break;
            }
            case 6:
                inv.showAll();
                break;
            case 7:
                cout << "Exiting.\n"; return 0;
            default:
                cout << "Invalid option.\n";
        }
    }
    return 0;
}