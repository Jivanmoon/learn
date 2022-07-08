#include<bits/stdc++.h>
using namespace std;

struct X {
    X() {cout << "X()" << endl;}
    X(const X &x) {cout << "X(const X&)" << endl;} 
    X &operator=(const X &rhs) {
        cout << "X &operator=(const X &rhs)" << endl;
    }
    ~X() {
        cout << "~X()" << endl;
    }
};

void func(X x) {

}

int main() {
    X x1;
    X *x2 = new X(x1);
    X x3;
    x3 = x1;
    delete x2;
    vector<X> v;
    v.push_back(x1);
    func(x1);
    //v.emplace_back();
    return 0;
}