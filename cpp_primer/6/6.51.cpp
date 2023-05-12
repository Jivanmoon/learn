#include <bits/stdc++.h>
using namespace std;
void f() {
    cout << "f()" << endl;
}

void f(int x) {
    cout << "f(int x)" << endl;
}

void f(int x, int y) {
    cout << "f(int x, int y)" << endl;
}

void f(double x, double y = 3.14) {
    cout << "f(double x, double y = 3.14)" << endl;
}

int main()
{
    f(2.56, 43);
    f(42);
    f(42, 0);
    f(5.56, 3.23);
    return 0;
}