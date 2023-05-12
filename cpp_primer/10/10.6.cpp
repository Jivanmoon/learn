#include<bits/stdc++.h>
using namespace std;

int main() {
    vector<int> v;
    auto iter = back_inserter(v);
    fill_n(iter, 10, 0);
    for(int t : v) {
        cout << t << " ";
    }
    cout << endl;
    return 0;
}