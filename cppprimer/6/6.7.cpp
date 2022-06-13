#include<bits/stdc++.h>
using namespace std;
int func() {
    static int cnt = 0;
    return cnt++;
}
int main() {
    cout << func() << endl;
    cout << func() << endl;
    cout << func() << endl;
    return 0;
}
