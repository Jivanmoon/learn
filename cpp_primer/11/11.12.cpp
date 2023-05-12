#include<bits/stdc++.h>
using namespace std;

int main() {
    vector<pair<string, int>> v;
    string s;
    int i;
    while(cin >> s >> i) {
        v.push_back({s, i});
    }
    for(const auto &t : v) {
        cout << t.first << ":" << t.second << endl;
    }
    return 0;
}