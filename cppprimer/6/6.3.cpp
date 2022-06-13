#include<bits/stdc++.h>
using namespace std;

int fact1() {
    int res = 1;
    for(int i = 2; i <= 5; ++i) {
        res *= i;
    }
    return res;
}

int main()
{
    cout << fact1() << endl;
    return 0;
}