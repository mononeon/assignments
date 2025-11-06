#include <iostream>
#include <cstring>
using namespace std;

class Applicant {
    static int last_id;
    int id;
    char name[50];
    float score;

public:
    Applicant() { id = 0; }

    void receiveData() {
        id = ++last_id;
        cout << "Enter applicant name: ";
        cin.ignore();
        cin.getline(name, 50);
        cout << "Enter score: ";
        cin >> score;
    }

    void showDetails() {
        if (id == 0) return;
        cout << "Application ID: " << id
             << "\nName: " << name
             << "\nScore: " << score << "\n";
    }

    static int getApplicantCount() { return last_id; }
};

int Applicant::last_id = 0;

int main() {
    Applicant applicants[100];
    int count = 0, ch;

    do {
        cout << "\n=== Applicant Menu ===\n"
             << "1. Add Applicant\n" 
             << "2. Show All Applicants\n"
             << "3. Show Count\n"
             << "4. Exit\n"
             << "Choice: ";
        cin >> ch;

        switch (ch) {
        case 1:
            applicants[count].receiveData();
            count++;
            break;
        case 2:
            for (int i = 0; i < count; ++i)
                applicants[i].showDetails();
            break;
        case 3:
            cout << "Total Applicants: " << Applicant::getApplicantCount() << "\n";
            break;
        }
    } while (ch != 4);

    return 0;
}
