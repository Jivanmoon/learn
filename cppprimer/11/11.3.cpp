#include<bits/stdc++.h>
using namespace std;
void word_count(const vector<string> &words) {
    unordered_map<string, unsigned> mp;
    for(const string &word : words) {
        ++mp[word];
    }
    for(const auto &p : mp) {
        cout << p.first << ":" << p.second << endl;
    }
}
int main() {
    vector<string> vs{
        "aaa","aaa","dasdas","hello"
    };
    word_count(vs);
    return 0;
}