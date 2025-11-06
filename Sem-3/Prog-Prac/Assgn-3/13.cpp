#include <iostream>
#include <cstring>
using namespace std;

class Balance {
    int acc_no;
    float balance;
    char last_update[15];

public:
    void create(int acc, float bal, const char* date) {
        acc_no = acc; balance = bal; strcpy(last_update, date);
    }

    void show() {
        cout << "Account: " << acc_no
             << " | Balance: " << balance
             << " | Last Update: " << last_update << "\n";
    }

    int getAcc() { return acc_no; }

    void update(float amt, char type, const char* date) {
        if (type == 'W') {
            if (amt > balance) cout << "Insufficient balance!\n";
            else balance -= amt;
        } else if (type == 'D') balance += amt;
        strcpy(last_update, date);
    }
};

class Transaction {
    int acc_no;
    float amount;
    char type;
    char date[15];

public: 
    void perform(Balance b[], int n) {
        cout << "Enter acc no, amount, type(W/D), date: ";
        cin >> acc_no >> amount >> type >> date;
        for (int i = 0; i < n; ++i)
            if (b[i].getAcc() == acc_no) {
                b[i].update(amount, type, date);
                cout << "Transaction successful.\n";
                return;
            }
        cout << "Account not found!\n";
    }
};

int main() {
    Balance b[100];
    int count = 0, ch;
    do {
        cout << "\n=== Balance Menu ===\n"
             << "1. Add Account\n"
             << "2. Transaction\n"
             << "3. Show All\n"
             << "4. Exit\n"
             << "Choice: ";
        cin >> ch;
        switch (ch) {
        case 1: {
            int acc; float bal; char date[15];
            cout << "Enter acc no, initial bal, date: ";
            cin >> acc >> bal >> date;
            b[count++].create(acc, bal, date);
            break;
        }
        case 2: {
            Transaction t;
            t.perform(b, count);
            break;
        }
        case 3:
            for (int i = 0; i < count; ++i) b[i].show();
            break;
        }
    } while (ch != 4);
    return 0;
}
