#include<iostream>
using namespace std;

int main() {
    int i = 0, &r = i;
    auto a = r;

    const int ci = i, &cr = ci;
    auto b = ci;
    auto c = cr;
    auto d = &i;
    auto e = &ci;
    auto &g = ci;

    cout << a << endl;
    cout << b << endl;
    cout << c << endl;
    cout << d << endl;
    cout << e << endl;
    cout << g << endl;
    cout << "-----------------" << endl;

    a = 42, b = 42, c = 42;
    //d = 42, e = 42, g = 42;

    cout << a << endl;
    cout << b << endl;
    cout << c << endl;
}