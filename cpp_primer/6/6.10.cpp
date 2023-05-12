#include<bits/stdc++.h>
using namespace std;
void func(int *x, int *y) 
{
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

int main() {
    int a = 3, b = 4;
    cout << "a = " << a << ", b = " << b << endl;
    func(&a, &b);
    cout << "a = " << a << ", b = " << b << endl;
    return 0;
}