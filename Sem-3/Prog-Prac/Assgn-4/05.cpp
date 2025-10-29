#include <bits/stdc++.h>
using namespace std;

class RCString {
private:
    struct S {
        char *data;
        size_t len;
        int refcount;
        S(): data(nullptr), len(0), refcount(1) {}
    };
    S *p;

    static S* makeNew(const char *s) {
        S *sobj = new S();
        if (s) {
            sobj->len = strlen(s);
            sobj->data = new char[sobj->len + 1];
            strcpy(sobj->data, s);
        } else {
            sobj->len = 0; sobj->data = nullptr;
        }
        sobj->refcount = 1;
        return sobj;
    }

public:
    RCString(): p(makeNew(nullptr)) {}
    RCString(const char *s): p(makeNew(s)) {}
    RCString(const RCString &o): p(o.p) { ++(p->refcount); }

    RCString& operator=(const RCString &o) {
        if (p == o.p) return *this;
        if (--(p->refcount) == 0) {
            delete[] p->data;
            delete p;
        }
        p = o.p;
        ++(p->refcount);
        return *this;
    }

    ~RCString() {
        if (--(p->refcount) == 0) {
            delete[] p->data;
            delete p;
        }
    }

    const char* c_str() const { return p->data ? p->data : ""; }
    int refcount() const { return p->refcount; }
    size_t size() const { return p->len; }

    void show() const {
        cout << "String: \"" << c_str() << "\" | len=" << size() << " | refcount=" << refcount() << "\n";
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    RCString s1("hello");
    RCString s2 = s1; // share
    RCString s3("world");

    while (true) {
        cout << "\nRCSTRING MENU\n1. Show s1,s2,s3\n2. Assign s3 = s1\n3. Make s1 = custom\n4. Show refcounts\n5. Exit\nChoose: ";
        int ch; if (!(cin >> ch)) break;
        switch (ch) {
            case 1: cout << "s1: "; s1.show(); cout << "s2: "; s2.show(); cout << "s3: "; s3.show(); break;
            case 2: s3 = s1; cout << "Assigned s3 = s1\n"; break;
            case 3: {
                string tmp; cin.ignore(); getline(cin, tmp);
                s1 = RCString(tmp.c_str()); // replaces s1 with new object
                cout << "Updated s1.\n";
                break;
            }
            case 4: cout << "s1 refcount: " << s1.refcount() << " | s2 refcount: " << s2.refcount() << " | s3 refcount: " << s3.refcount() << "\n"; break;
            case 5: return 0;
            default: cout << "Invalid\n";
        }
    }
    return 0;
}