#include<bits/stdc++.h>
using namespace std;

class HasPtr {
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
    ~HasPtr() {
        delete ps;
    }

private:
    string *ps;
    int i;
};