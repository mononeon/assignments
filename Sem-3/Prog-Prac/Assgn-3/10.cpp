#include <bits/stdc++.h>
using namespace std;

class Student {
private:
    string roll;
    string name;
    string course;
    string admission_date;
    array<int, 5> marks;

    static int admitted_count;

public:
    Student(const string &r, const string &n, const string &c, const string &d)
        : roll(r), name(n), course(c), admission_date(d) {
        marks.fill(-1);
        ++admitted_count;
    }

    const string &getRoll() const { return roll; }

    void receiveMarks() {
        cout << "Enter marks for 5 subjects for " << roll << " (" << name << "):\n";
        for (int i = 0; i < 5; ++i) {
            int m;
            while (true) {
                cout << " Subject " << (i + 1) << ": ";
                if (cin >> m) {
                    if (m < 0 || m > 100) {
                        cout << "  Marks should be 0..100. Try again.\n";
                        continue;
                    }
                    marks[i] = m;
                    break;
                } else {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "  Invalid input. Enter integer marks.\n";
                }
            }
        }
    }

    void prepareMarkSheet() const {
        cout << "----------------------------------------\n";
        cout << "Marksheet : " << name << "  (Roll: " << roll << ")\n";
        cout << "Course: " << course << " | Admission date: " << admission_date << "\n";
        bool allGiven = true;
        int total = 0;
        for (int i = 0; i < 5; ++i) {
            cout << " Subject " << (i + 1) << ": ";
            if (marks[i] < 0) {
                cout << "Not entered\n";
                allGiven = false;
            } else {
                cout << marks[i] << '\n';
                total += marks[i];
            }
        }
        if (allGiven) {
            double percent = total / 5.0;
            cout << " Total: " << total << "  | Percentage: " << fixed << setprecision(2) << percent << "%\n";
            cout << " Grade: ";
            if (percent >= 75) cout << "A";
            else if (percent >= 60) cout << "B";
            else if (percent >= 50) cout << "C";
            else cout << "F";
            cout << '\n';
        } else {
            cout << " Marks incomplete — cannot compute total/grade.\n";
        }
        cout << "----------------------------------------\n";
    }

    void showSummary() const {
        cout << setw(10) << roll << " | " << setw(20) << name << " | " << setw(6) << course
             << " | " << admission_date << '\n';
    }

    static int numberOfAdmitted() { return admitted_count; }
};

int Student::admitted_count = 0;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<Student> students;

    while (true) {
        cout << "\nSTUDENT MENU\n"
             << "1. Admit student\n"
             << "2. Enter marks for a student\n"
             << "3. Prepare marksheet for a student\n"
             << "4. List students (summary)\n"
             << "5. Show number of admitted students\n"
             << "6. Exit\n"
             << "Choose: ";

        int ch;
        if (!(cin >> ch)) break;

        switch (ch) {
            case 1: {
                string roll, name, course, date;
                cout << "Roll (unique): "; cin >> roll;
                bool exists = false;
                for (const auto &s : students) if (s.getRoll() == roll) { exists = true; break; }
                if (exists) { cout << "Error: roll already exists.\n"; break; }
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Name: "; getline(cin, name);
                cout << "Course: "; getline(cin, course);
                cout << "Admission date (YYYY-MM-DD): "; getline(cin, date);
                students.emplace_back(roll, name, course, date);
                cout << "Student admitted.\n";
                break;
            }

            case 2: {
                string roll; cout << "Enter roll to add marks: "; cin >> roll;
                auto it = find_if(students.begin(), students.end(), [&](const Student &s){ return s.getRoll() == roll; });
                if (it == students.end()) cout << "Student not found.\n";
                else it->receiveMarks();
                break;
            }

            case 3: {
                string roll; cout << "Enter roll to prepare marksheet: "; cin >> roll;
                auto it = find_if(students.begin(), students.end(), [&](const Student &s){ return s.getRoll() == roll; });
                if (it == students.end()) cout << "Student not found.\n";
                else it->prepareMarkSheet();
                break;
            }

            case 4: {
                if (students.empty()) { cout << "No students admitted yet.\n"; break; }
                cout << setw(10) << "Roll" << " | " << setw(20) << "Name" << " | " << setw(6) << "Course" << " | Admission\n";
                cout << string(60, '-') << '\n';
                for (const auto &s : students) s.showSummary();
                break;
            }

            case 5:
                cout << "Total admitted students: " << Student::numberOfAdmitted() << '\n';
                break;

            case 6:
                cout << "Exiting.\n";
                return 0;

            default:
                cout << "Invalid option.\n";
        }
    }

    return 0;
}