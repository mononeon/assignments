#include <iostream>
using namespace std;

struct Student {
    int roll;
    int score;
    void input() {
        cout << "Enter roll: " << "\n"; cin >> roll;
        cout << "Enter score: " << "\n"; cin >> score;
    }
    void show() {
        cout << "Roll is: " << roll << "\n";
        cout << "Score is: " << score << "\n";
    }
};

void modify_score_g(struct Student &s) {
    int newscore;
    cout << "Enter new score: ";
    cin >> newscore;
    s.score = newscore;
}
void show_g(struct Student &s) {
    cout << "From global\n";
    cout << "Roll is: " << s.roll << "\n";
    cout << "Score is: " << s.score << "\n";
}

int main() {
    struct Student s;
    s.input();
    s.show();
    modify_score_g(s);
    show_g(s);
    return 0;
}

