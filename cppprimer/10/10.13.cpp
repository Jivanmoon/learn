#include<bits/stdc++.h>
using namespace std;

bool func(const string &s) {
    return s.size() >= 5;
}

int main() {
    vector<string> v;
    string word;
    while(cin >> word) {
        v.emplace_back(word);
    }
    auto end = partition(v.begin(), v.end(), func);
    auto i = v.begin();
    while(i != end) {
        cout << *i << endl;
        ++i;
    }
    return 0;
}