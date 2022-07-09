#include<bits/stdc++.h>
using namespace std;

class HasPtr {

public:
    HasPtr(const string &s = string()):
        ps(new string(s)), i(0), use(new size_t(1)) {}
    HasPtr(const HasPtr &rhs):
        ps(rhs.ps), i(rhs.i), use(rhs.use) {
            ++*use;
        }
    HasPtr &operator=(const HasPtr &rhs) {
        ++*rhs.use;
        if(--*use == 0) {
            delete ps;
            delete use;
        }
        ps = rhs.ps;
        i = rhs.i;
        use = rhs.use;
        return *this;
    }
    ~HasPtr() {
        if(--*use == 0) {
            delete ps;
            delete use;
        }
    }

private:
    string *ps;
    int i;
    size_t *use;
};

