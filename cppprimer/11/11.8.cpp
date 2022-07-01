#include<bits/stdc++.h>
using namespace std;
int main() {
    vector<string> v;
    string word;
    while(cin >> word) {
        if(find(v.cbegin(), v.cend(), word) == v.cend()) {
            v.push_back(word);
        }
    }
    for(const auto &s : v) {
        cout << s << endl;
    }
    return 0;
}