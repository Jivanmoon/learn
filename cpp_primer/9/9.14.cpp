#include <bits/stdc++.h>
using namespace std;

int main() 
{
    list<const char *> ls = {
        "hello",
        "world"
    };
    vector<string> vs;
    vs.assign(ls.cbegin(), ls.cend());
    for(auto s : vs) {
        cout << s << endl;
    }
    return 0;
}