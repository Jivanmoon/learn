#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s, pre;
    while(cin>>s) {
        if(s == pre) break;
        pre = s;
    }
    if(s == pre) cout << s << endl;
    else cout << "No" << endl;
    return 0;
}