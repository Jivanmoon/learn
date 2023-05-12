#include<bits/stdc++.h>
using namespace std;

class HasPtr {
    friend void swap(HasPtr &, HasPtr &);
public:
    HasPtr(const string &s = string()): ps(new string(s)), i(0) {}
    HasPtr(const HasPtr &arg): ps(new string(*(arg.ps))), i(arg.i) {}
    HasPtr(HasPtr &&rhs) noexcept: ps(rhs.ps), i(std::move(i)) {
        rhs.ps = nullptr;
    }
    HasPtr &operator=(const HasPtr &rhs) noexcept {
        auto newp = new string(*rhs.ps);
        delete ps;
        ps = newp;
        i = rhs.i;
        return *this;
    }
    HasPtr &operator=(HasPtr &&rhs) {
        if(this != &rhs) {
            ps = rhs.ps;
            i = std::move(rhs.i);
            rhs.ps = nullptr;
        }
        return *this;
    }
    // HasPtr &operator=(HasPtr rhs) {
    //     swap(*this, rhs);
    //     return *this;l
    // }
    void print() const {
        cout << *ps << endl;
    }
    bool operator<(const HasPtr &rhs) const {
        return *ps < *rhs.ps;
    }
    ~HasPtr() {
        delete ps;
    }

private:
    string *ps;
    int i;
};

inline
void swap(HasPtr &lhs, HasPtr &rhs) {
    using std::swap;
    cout << "void swap(HasPtr &lhs, HasPtr &rhs)" << endl;
    swap(lhs.ps, rhs.ps);
    swap(lhs.i, rhs.i);
}

int main() {
    HasPtr hp1("test"), hp2("train"), *pH = new HasPtr("train");
    hp1 = hp2;
    hp1 = std::move(*pH);
}