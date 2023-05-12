#include<bits/stdc++.h>
using namespace std;
int func(int n) {
    static int cnt = 0;
    ++cnt;
    cout << cnt << endl;
    return n == 1 ? n : n * func(n - 1);
}
int main() {
    cout << func(5) << endl;
    return 0;
}
