#include <bits/stdc++.h>
using namespace std;

bool judge(vector<int> &s, vector<int> &l) {
    for(int i = 0; i < s.size(); ++i) {
        if(s[i] != l[i]) return false;
    }
    return true;
}

int main()
{
    vector<int> v1 = {0, 1, 1, 2};
    vector<int> v2 = {0, 1, 1, 2, 3, 5, 8};
    bool ans;
    if(v1.size() < v2.size())
        ans = judge(v1, v2);
    else 
        ans = judge(v2, v1);
    cout << ans << endl;
    return 0;
}