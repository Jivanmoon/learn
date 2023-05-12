#include<bits/stdc++.h>
using namespace std;

class HasPtr {
    friend void swap(HasPtr &, HasPtr &);
public:
    HasPtr(const string &s = string()): ps(new string(s)), i(0) {}
    HasPtr(const HasPtr &arg): ps(new string(*(arg.ps))), i(arg.i) {}
    HasPtr &operator=(const HasPtr &rhs) {
        auto newp = new string(*rhs.ps);
        delete ps;
        ps = newp;
        i = rhs.i;
        return *this;
    }
    void print() const {
        cout << *ps << " " << i << endl;
    }
    ~HasPtr() {
        delete ps;
    }

private:
    string *ps;
    int i;
};

void swap(HasPtr &lhs, HasPtr &rhs) {
    using std::swap;
    cout << "void swap(HasPtr &lhs, HasPtr &rhs)" << endl;
    swap(lhs.ps, rhs.ps);
    swap(lhs.i, rhs.i);
}

int main() {
    HasPtr p1("abc");
    HasPtr p2("lalala");
    p1.print();
    p2.print();
    swap(p1, p2);
    p1.print();
    p2.print();
}