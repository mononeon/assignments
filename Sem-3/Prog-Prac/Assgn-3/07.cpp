#include<bits/stdc++.h>
using namespace std;

class TIME {
private:
    int hour, minute, second;
    void normalize() {
        if (second >= 60) {
            minute += second / 60;
            second %= 60;
        }
        if (minute >= 60) {
            hour += minute / 60;
            minute %= 60;
        } if (hour >= 24) {
            hour %= 24;
        }
    }
public:
    TIME(int h, int m, int s) {
        hour = h;
        minute = m;
        second = s;
        normalize();
    }

    TIME(int h, int m, int s, bool isPM) {
        hour = h;
        minute = m;
        second = s;
        if (isPM && hour != 12) hour += 12;
        else if (!isPM && hour == 12) hour = 0;
        normalize();
    }

    void display24() {
        cout << setfill('0') << setw(2) << hour << ":"
             << setfill('0') << setw(2) << minute << ":"
             << setfill('0') << setw(2) << second << "\n";
    }

    void display12() {
        int display_hour = hour % 12;
        if (display_hour == 0) {
            display_hour = 12;
        }
        string meridiem = (hour >= 12) ? "PM" : "AM";
        cout << display_hour << ":"
             << setfill('0') << setw(2) << minute << ":"
             << setfill('0') << setw(2) << second << " " << meridiem << "\n";
    }

    void add_minutes(int mins) {
        minute += mins;
        normalize();
    }

    void input_time() {
        string time_string;
        cout << "Enter time (hh:mm:ss or hh mm ss) in 24-hour format, or hh:mm:ss AM/PM or hh mm ss AM/PM: ";
        cin.ignore();
        getline(cin, time_string);
        transform(time_string.begin(), time_string.end(), time_string.begin(), ::toupper);

        auto pos_AM = time_string.find("AM");
        auto pos_PM = time_string.find("PM");
        bool isAMPM = false;
        bool isPM = false;

        if (pos_AM != string::npos || pos_PM != string::npos) {
            isAMPM = true;
            if (pos_PM != string::npos) isPM = true;
            size_t pos = pos_AM;
            if (pos == string::npos) pos = pos_AM;
            time_string = time_string.substr(0, pos);
        }

        for (auto& c : time_string) {
            if (c == ':') c = ' ';
        }

        stringstream ss(time_string);
        int h, m, s;

        if (ss >> h >> m >> s) {
            if (h < 0 || h >= 24 || m < 0 || m >= 60 || s < 0 || s >= 60) {
                cout << "Invalid Input!\n";
                return;
            }
            if (isAMPM) {
                if (h < 1 || h > 12) {
                    cout << "Invalid Input!\n";
                }
                *this = TIME(h, m, s, isPM);
            } else {
                *this = TIME(h, m, s);
            }
        } else {
            cout << "Invalid Input!\n";
        }
    }
};

int main() {
    TIME time(0, 0, 0);
    int choice;
    do {
        cout << "\nMenu:\n";
        cout << "1. Input new time\n";
        cout << "2. Display time in 12-hour format\n";
        cout << "3. Display time in 24-hour format\n";
        cout << "4. Add minutes to time\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                time.input_time();
                break;
            }
            case 2: {
                cout << "Time in 12-hour format: ";
                time.display12();
                break;
            }
            case 3: {
                cout << "Time in 24-hour format: ";
                time.display24();
                break;
            }
            case 4: {
                int extra_mins;
                cout << "Enter the number of minutes to add: ";
                cin >> extra_mins;
                time.add_minutes(extra_mins);
                break;
            }
            case 5: {
                cout << "Exiting program...\n";
                break;
            }
            default: {
                cout << "Invalid choice. Please try again.\n";
                break;
            }
        }
    } while (choice != 5);
    return 0;
}
