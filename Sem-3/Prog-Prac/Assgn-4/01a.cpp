#include <bits/stdc++.h>
using namespace std;

class AccountList; // forward

// Withdraw object (contains account number and amount)
class Withdraw {
public:
    string acct;
    double amount;
    Withdraw() = default;
    Withdraw(const string &a, double m): acct(a), amount(m) {}
};

// Account class
class Account {
private:
    string account_number;
    double balance;

public:
    Account() = default;
    Account(const string &acc, double bal): account_number(acc), balance(bal) {}
    string getAccount() const { return account_number; }
    double getBalance() const { return balance; }

    void show() const {
        cout << "Account: " << account_number
             << " | Balance: " << fixed << setprecision(2) << balance << "\n";
    }

    // grant AccountList access to private members
    friend class AccountList;

    // keep friend withdraw processor (optional)
    friend bool processWithdraw(AccountList &list, const Withdraw &wd);
};

// AccountList keeps vector of Account (private)
class AccountList {
private:
    vector<Account> accounts;

public:
    bool addAccount(const Account &a) {
        for (auto &ac : accounts)
            if (ac.account_number == a.account_number) // allowed because AccountList is friend
                return false;
        accounts.push_back(a);
        return true;
    }

    Account* findAccount(const string &acc) {
        for (auto &a : accounts)
            if (a.account_number == acc) // allowed
                return &a;
        return nullptr;
    }

    void showAll() const {
        if (accounts.empty()) { cout << "No accounts.\n"; return; }
        for (const auto &a : accounts) a.show();
    }

    // grant the standalone function access (optional, we already gave AccountList access)
    friend bool processWithdraw(AccountList &list, const Withdraw &wd);
};

// friend function implementation (has direct access to Account private members)
bool processWithdraw(AccountList &list, const Withdraw &wd) {
    for (auto &a : list.accounts) {
        if (a.account_number == wd.acct) {
            if (wd.amount <= 0) return false;
            if (a.balance < wd.amount) return false;
            a.balance -= wd.amount;
            return true;
        }
    }
    return false; // account not found
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    AccountList bank;
    while (true) {
        cout << "\nBANK (friend) MENU\n"
             << "1. Add account\n"
             << "2. Find & show account\n"
             << "3. Withdraw (via Withdraw object)\n"
             << "4. Show all accounts\n"
             << "5. Exit\n"
             << "Choose: ";
        int ch; if (!(cin >> ch)) break;
        switch (ch) {
            case 1: {
                string acc; double bal;
                cout << "Account number: "; cin >> acc;
                cout << "Initial balance: "; cin >> bal;
                if (!bank.addAccount(Account(acc, bal))) cout << "Account already exists.\n";
                else cout << "Added.\n";
                break;
            }
            case 2: {
                string acc; cout << "Account number: "; cin >> acc;
                Account *a = bank.findAccount(acc);
                if (!a) cout << "Not found.\n"; else a->show();
                break;
            }
            case 3: {
                string acc; double amt;
                cout << "Account number: "; cin >> acc;
                cout << "Amount to withdraw: "; cin >> amt;
                Withdraw wd(acc, amt);
                if (processWithdraw(bank, wd)) cout << "Withdrawal successful.\n";
                else cout << "Withdrawal failed (not found/insufficient/invalid).\n";
                break;
            }
            case 4: bank.showAll(); break;
            case 5: cout << "Bye.\n"; return 0;
            default: cout << "Invalid.\n";
        }
    }
    return 0;
}