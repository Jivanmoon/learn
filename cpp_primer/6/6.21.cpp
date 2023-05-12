#include<bits/stdc++.h>
using namespace std;
int func(int x, const int *y) {
    return (x > *y) ? x : *y;
}

int main() {
    int a = 10, b = 20;
    cout << func(a, &b) << endl;
    return 0;
}