#include <bits/stdc++.h>
using namespace std;

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
             << " | Balance: " << fixed << setprecision(2) << balance << '\n';
    }

    // safe withdraw method
    bool withdraw(double amt) {
        if (amt <= 0) return false;
        if (amt > balance) return false;
        balance -= amt;
        return true;
    }

    void deposit(double amt) {
        if (amt > 0) balance += amt;
    }
};

class Withdraw {
public:
    string acct;
    double amount;
    Withdraw() = default;
    Withdraw(const string &a, double m): acct(a), amount(m) {}
};

class AccountList {
private:
    vector<Account> accounts;

public:
    bool addAccount(const Account &a) {
        for (const auto &ac : accounts)
            if (ac.getAccount() == a.getAccount())
                return false;
        accounts.push_back(a);
        return true;
    }

    // returns index of account or -1
    int findAccountIndex(const string &acc) const {
        for (size_t i = 0; i < accounts.size(); ++i)
            if (accounts[i].getAccount() == acc) return static_cast<int>(i);
        return -1;
    }

    bool processWithdraw(const Withdraw &wd) {
        int idx = findAccountIndex(wd.acct);
        if (idx == -1) return false;
        return accounts[idx].withdraw(wd.amount);
    }

    bool depositToAccount(const string &acc, double amt) {
        int idx = findAccountIndex(acc);
        if (idx == -1) return false;
        accounts[idx].deposit(amt);
        return true;
    }

    void showAccount(const string &acc) const {
        int idx = findAccountIndex(acc);
        if (idx == -1) { cout << "Account not found.\n"; return; }
        accounts[idx].show();
    }

    void showAll() const {
        if (accounts.empty()) { cout << "No accounts.\n"; return; }
        for (const auto &a : accounts) a.show();
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    AccountList bank;

    while (true) {
        cout << "\n=== BANK MENU ===\n"
             << "1. Add account\n"
             << "2. Find & show account\n"
             << "3. Withdraw\n"
             << "4. Deposit\n"
             << "5. Show all accounts\n"
             << "6. Exit\n"
             << "Choose: ";

        int ch;
        if (!(cin >> ch)) {
            cout << "Invalid input. Exiting.\n";
            break;
        }

        switch (ch) {
            case 1: {
                string acc;
                double bal;
                cout << "Account number: "; cin >> acc;
                cout << "Initial balance: ";
                if (!(cin >> bal)) { cout << "Invalid balance.\n"; cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n'); break; }
                if (!bank.addAccount(Account(acc, bal))) cout << "Error: account already exists.\n";
                else cout << "Account added.\n";
                break;
            }

            case 2: {
                string acc; cout << "Account number: "; cin >> acc;
                bank.showAccount(acc);
                break;
            }

            case 3: {
                string acc; double amt;
                cout << "Account number: "; cin >> acc;
                cout << "Amount to withdraw: "; 
                if (!(cin >> amt)) { cout << "Invalid amount.\n"; cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n'); break; }
                Withdraw wd(acc, amt);
                if (bank.processWithdraw(wd)) cout << "Withdrawal successful.\n";
                else cout << "Withdrawal failed (not found / invalid amount / insufficient funds).\n";
                break;
            }

            case 4: {
                string acc; double amt;
                cout << "Account number: "; cin >> acc;
                cout << "Amount to deposit: ";
                if (!(cin >> amt)) { cout << "Invalid amount.\n"; cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n'); break; }
                if (bank.depositToAccount(acc, amt)) cout << "Deposit successful.\n";
                else cout << "Deposit failed (account not found / invalid amount).\n";
                break;
            }

            case 5:
                bank.showAll();
                break;

            case 6:
                cout << "Goodbye.\n";
                return 0;

            default:
                cout << "Invalid option. Try again.\n";
        }
    }

    return 0;
}