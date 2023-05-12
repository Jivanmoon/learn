#include <iostream>
using namespace std;

class Base {
public:
    virtual int fcn() {
        cout << "Base:void fcn()" << endl;
    }
};

class D1 : public Base {
public:
    int fnc(int x) {
        cout << "D1:int fcn(int x)" << endl;
    }
    int fcn() override {
        cout << "D1:int fnc()" << endl;
    }
    virtual void f2() {
        cout << "D1:void f2()" << endl;
    }
};

class D2 : public D1 {
public:
    int fcn(int x) {
        cout << "D2:int fcn(int x)" << endl;
    }
    int fcn() override {
        cout << "D2:int fcn()" << endl;
    }
    void f2() {
        cout << "D2:void f2()" << endl;
    }
};

int main() {
    Base bobj;
    D1 d1obj;
    D2 d2obj;
    Base *bp1 = &bobj, *bp2 = &d1obj, *bp3 = &d2obj;
    bp1->fcn();
    bp2->fcn();
    bp3->fcn();

    D1 *d1p = &d1obj;
    D2 *d2p = &d2obj;
    // bp2->f2();
    d1p->f2();
    d2p->f2();
}
