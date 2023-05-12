#include<bits/stdc++.h>
using namespace std;

int fact2(int n) {
    int res = 1;
    for(int i = 2; i <= n; ++i) {
        res *= i;
    }
    return res;
}

int main()
{
    int n;
    cin >> n;
    cout << fact2(n) << endl;
    return 0;
}