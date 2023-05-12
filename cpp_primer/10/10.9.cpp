#include<bits/stdc++.h>
using namespace std;

void elimDups(vector<int> &v) {
    sort(v.begin(), v.end());
    auto rm_idx = unique(v.begin(), v.end());
    v.erase(rm_idx, v.end());
}

int main() {
    vector<int> v;
    int t;
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