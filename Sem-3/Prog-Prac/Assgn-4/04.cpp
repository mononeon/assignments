#include <bits/stdc++.h>
using namespace std;

class MyString {
private:
    char *data;
    size_t len;
public:
    MyString(): data(nullptr), len(0) {}
    MyString(const char *s) {
        if (!s) { data = nullptr; len = 0; return; }
        len = strlen(s);
        data = new char[len + 1];
        strcpy(data, s);
    }
    MyString(const MyString &o) {
        len = o.len;
        if (len) {
            data = new char[len + 1];
            strcpy(data, o.data);
        } else data = nullptr;
    }
    MyString& operator=(const MyString &o) {
        if (this == &o) return *this;
        delete[] data;
        len = o.len;
        if (len) {
            data = new char[len + 1];
            strcpy(data, o.data);
        } else data = nullptr;
        return *this;
    }
    ~MyString() { delete[] data; }

    const char* c_str() const { return data ? data : ""; }
    size_t size() const { return len; }

    // concatenation
    MyString operator+(const MyString &o) const {
        MyString r;
        r.len = len + o.len;
        r.data = new char[r.len + 1];
        if (data) strcpy(r.data, data); else r.data[0] = '\0';
        if (o.data) strcat(r.data, o.data);
        return r;
    }

    // relational operators (lexicographic)
    bool operator==(const MyString &o) const { return strcmp(c_str(), o.c_str()) == 0; }
    bool operator!=(const MyString &o) const { return !(*this == o); }
    bool operator<(const MyString &o) const { return strcmp(c_str(), o.c_str()) < 0; }
    bool operator>(const MyString &o) const { return strcmp(c_str(), o.c_str()) > 0; }
    bool operator<=(const MyString &o) const { return !(*this > o); }
    bool operator>=(const MyString &o) const { return !(*this < o); }

    void show() const { cout << c_str() << "\n"; }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    MyString s1("Hello"), s2("World");
    while (true) {
        cout << "\nSTRING MENU\n1. Show s1,s2\n2. s3 = s1 + s2\n3. compare s1 and s2\n4. assign s2 = s1\n5. custom input for s1\n6. Exit\nChoose: ";
        int ch; if (!(cin >> ch)) break;
        switch (ch) {
            case 1: cout << "s1: "; s1.show(); cout << "s2: "; s2.show(); break;
            case 2: { MyString s3 = s1 + s2; cout << "s3: "; s3.show(); break; }
            case 3:
                cout << "s1 == s2 ? " << (s1 == s2) << "\n";
                cout << "s1 < s2  ? " << (s1 < s2) << "\n";
                break;
            case 4: s2 = s1; cout << "Assigned s2 = s1\n"; break;
            case 5: {
                string tmp; cin.ignore(); getline(cin, tmp);
                s1 = MyString(tmp.c_str());
                cout << "Updated s1.\n"; break;
            }
            case 6: return 0;
            default: cout << "Invalid\n";
        }
    }
    return 0;
}