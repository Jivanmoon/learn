#include <bits/stdc++.h>
using namespace std;

int main()
{
    string word, pre, ans;
    int cnt = 1, maxm;
    while(cin >> word) {
        if(word == pre) {
            ++cnt;
            if(cnt > maxm) {
                maxm = cnt;
                ans = word;
            }
        }
        else {
            cnt = 1;
        }
        pre = word;
    }
    if(maxm > 1)
        cout << ans << ":" << maxm << endl;
    else   
        cout << "NO" << endl;
    return 0;
}