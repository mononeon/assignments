#include <bits/stdc++.h>
using namespace std;

class Balance {
private:
    string account_number;
    double balance_amount = 0.0;
    string last_update;

public:
    Balance() = default;
    Balance(const string &acc, double bal, const string &date)
        : account_number(acc), balance_amount(bal), last_update(date) {}

    const string &account() const { return account_number; }
    double balance() const { return balance_amount; }
    const string &lastUpdate() const { return last_update; }

    void deposit(double amount, const string &date) {
        balance_amount += amount;
        last_update = date;
    }

    bool withdraw(double amount, const string &date) {
        if (amount > balance_amount) return false;
        balance_amount -= amount;
        last_update = date;
        return true;
    }

    void show() const {
        cout << "Account: " << account_number
             << " | Balance: " << fixed << setprecision(2) << balance_amount
             << " | Last update: " << last_update << "\n";
    }
};

class Transaction {
private:
    string account_number;
    string date;
    double amount = 0.0;
    char type = 'D'; // 'D' = deposit, 'W' = withdrawal

public:
    Transaction() = default;
    Transaction(const string &acc, const string &dt, double amt, char t)
        : account_number(acc), date(dt), amount(amt), type(t) {}

    bool process(Balance &bal) const {
        if (bal.account() != account_number) {
            cerr << "Transaction account mismatch.\n";
            return false;
        }
        if (type == 'D' || type == 'd') {
            bal.deposit(amount, date);
            return true;
        } else if (type == 'W' || type == 'w') {
            if (!bal.withdraw(amount, date)) {
                cerr << "Insufficient funds for withdrawal of " << amount << ".\n";
                return false;
            }
            return true;
        } else {
            cerr << "Unknown transaction type '" << type << "'.\n";
            return false;
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    unordered_map<string, Balance> accounts;

    while (true) {
        cout << "\nBANK MENU\n"
             << "1. Create account\n"
             << "2. Show account\n"
             << "3. Deposit (via Transaction)\n"
             << "4. Withdraw (via Transaction)\n"
             << "5. Process generic Transaction\n"
             << "6. Show all accounts\n"
             << "7. Exit\n"
             << "Choose: ";
        int ch;
        if (!(cin >> ch)) break;
        switch (ch) {
            case 1: {
                string acc, date;
                double bal;
                cout << "Account number: "; cin >> acc;
                if (accounts.find(acc) != accounts.end()) { cout << "Account already exists.\n"; break; }
                cout << "Initial balance: "; if (!(cin >> bal)) { cout << "Invalid balance\n"; break; }
                cout << "Date (YYYY-MM-DD): "; cin >> date;
                accounts.emplace(acc, Balance(acc, bal, date));
                cout << "Account created.\n";
                break;
            }
            case 2: {
                string acc; cout << "Account number: "; cin >> acc;
                auto it = accounts.find(acc);
                if (it == accounts.end()) cout << "Account not found.\n";
                else it->second.show();
                break;
            }
            case 3: {
                string acc, date; double amt;
                cout << "Account number: "; cin >> acc;
                cout << "Amount to deposit: "; if (!(cin >> amt)) { cout << "Invalid amount\n"; break; }
                cout << "Date: "; cin >> date;
                auto it = accounts.find(acc);
                if (it == accounts.end()) cout << "Account not found.\n";
                else {
                    Transaction tx(acc, date, amt, 'D');
                    if (tx.process(it->second)) cout << "Deposit successful.\n";
                }
                break;
            }
            case 4: {
                string acc, date; double amt;
                cout << "Account number: "; cin >> acc;
                cout << "Amount to withdraw: "; if (!(cin >> amt)) { cout << "Invalid amount\n"; break; }
                cout << "Date: "; cin >> date;
                auto it = accounts.find(acc);
                if (it == accounts.end()) cout << "Account not found.\n";
                else {
                    Transaction tx(acc, date, amt, 'W');
                    if (tx.process(it->second)) cout << "Withdrawal successful.\n";
                    else cout << "Withdrawal failed.\n";
                }
                break;
            }
            case 5: {
                string acc, date; double amt; char t;
                cout << "Account number: "; cin >> acc;
                cout << "Date: "; cin >> date;
                cout << "Amount: "; if (!(cin >> amt)) { cout << "Invalid amount\n"; break; }
                cout << "Type (D/W): "; cin >> t;
                auto it = accounts.find(acc);
                if (it == accounts.end()) cout << "Account not found.\n";
                else {
                    Transaction tx(acc, date, amt, t);
                    if (tx.process(it->second)) cout << "Transaction processed.\n";
                    else cout << "Transaction failed.\n";
                }
                break;
            }
            case 6:
                if (accounts.empty()) { cout << "No accounts available.\n"; break; }
                for (const auto &p : accounts) p.second.show();
                break;
            case 7:
                cout << "Exiting.\n"; return 0;
            default:
                cout << "Invalid option.\n";
        }
    }
    return 0;
}