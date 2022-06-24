#include <bits/stdc++.h>
using namespace std;

int main()
{
    const string not_in = "bdfhkltgjpq";
    ifstream fin("9.49.data");
    string word, ans;
    while(fin >> word) {
        auto pos = word.find_first_of(not_in);
        if(pos == string::npos) {
            if(ans.empty() || word.size() > ans.size()) {
                ans = word;
            }
        }
    }
    cout << ans << endl;
    fin.close();
    return 0;
}