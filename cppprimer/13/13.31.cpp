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
    vector<HasPtr> vp;
    //i=15是16个元素，i=16是17个元素
    for(int i = 16; i >= 0; --i) {
        string tmp = to_string(i);
        vp.emplace_back(tmp);
    }
    sort(vp.begin(), vp.end());
    for(auto &p : vp) {
        p.print();
    }
}