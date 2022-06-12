#include <bits/stdc++.h>
using namespace std;

int main()
{
    char c;
    while(cin >> c) {
        cout << c << endl;
    }


    int sum = 0;
    for(int i = 0; i < 10; ++i) {
        sum += i;
    }
    cout << sum << endl;

    //改写
    for(;cin >> c;) {
        cout << c << endl;
    }

    int i = 0;
    sum = 0;
    while(i < 10) {
        sum += i++;
    }
    cout << sum << endl;
    return 0;
}