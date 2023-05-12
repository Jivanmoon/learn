#include<bits/stdc++.h>
using namespace std;

class Func {
public:
    Func() = default;
    Func(int n): num(n) {}
    int operator()(int a, int b, int c) {
        if(a == num) return b;
        else return c;
    }
private:
    int num;
};

int main() {
    Func func(2);
    cout << func(3, 1, 2) << endl;
}