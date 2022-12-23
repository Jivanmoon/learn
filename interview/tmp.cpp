#include <iostream>
using namespace std;
class A {
public:
    void func1() {
        cout << "virtual void A::func1()" << endl;
    }
    static void func() {
        cout << "static void func()" << endl;
    }
};

int main() {
    A a;
    a.func();
    A::func();
    return 0;
}
