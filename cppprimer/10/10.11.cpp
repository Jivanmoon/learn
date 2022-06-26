#include<bits/stdc++.h>
using namespace std;

bool isShorter(const string &x, const string &y) {
    return x.size() < y.size();
}

void elimDups(vector<string> &v) {
    stable_sort(v.begin(), v.end(), isShorter);
    auto rm_idx = unique(v.begin(), v.end());
    v.erase(rm_idx, v.end());
}

int main() {
    vector<string> v;
    string t;
    while(cin >> t) {
        v.emplace_back(t);
    }
    elimDups(v);
    for(auto t : v) {
        cout << t << " ";
    }
    cout << endl;
    return 0;
}