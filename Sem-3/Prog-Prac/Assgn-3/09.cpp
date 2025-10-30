#include <bits/stdc++.h>
using namespace std;

class Applicant {
private:
    static int last_id;
    int id;
    string name;
    double score;
public:
    Applicant() : id(++last_id), name(""), score(0.0) {}
    void receiveData() {
        cout << "Enter name: ";
        getline(cin >> ws,  name);
        cout << "Enter score: "; cin >> score;
    }
    void show() const {
        cout << "ID: " << id << " | Name: " << name << " | Score: " << score << '\n';
    }
    int getId() const { return id; }
};
int Applicant::last_id = 0;

int main() {
    vector<Applicant> list;
    while (true) {
        cout << "\nAPPLICANT MENU:\n1. Add Applicant\n2. Show All\n3. Count\n4. Exit\nChoose: ";
        int ch; if (!(cin >> ch)) return 0;
        switch (ch) {
            case 1: {
                Applicant a; a.receiveData(); list.push_back(a);
                break;
            }
            case 2: {
                for (const auto &a : list) a.show();
                break;
            }
            case 3: cout << "Total applicants: " << list.size() << '\n';
            break;
            case 4: return 0;
            default: cout << "Invalid option\n";
        }
    }
}