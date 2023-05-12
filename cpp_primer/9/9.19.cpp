#include <bits/stdc++.h>
using namespace std;

int main()
{
    list<string> q;
    string s;
    while(cin >> s) {
        q.push_back(s);
    }
    for(auto i = q.cbegin(); i != q.cend(); ++i) {
        cout << *i << endl;
    }
    exit(0);
}