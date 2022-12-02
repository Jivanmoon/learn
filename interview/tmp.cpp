#include <iostream>
using namespace std;
class A {
public:
    void func1() {
        cout << "virtual void A::func1()" << endl;
    }
};

class B : public A {
public:
    void func1(int a) {
        cout << "virtual void B::func1(int a)" << endl;
    }
};
int main() {
    B b;
    b.A::func1();
    b.func1(1);
    return 0;
}
