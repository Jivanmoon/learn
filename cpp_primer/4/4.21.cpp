#include<bits/stdc++.h>
using namespace std;

int main() {
    vector<int> v = {1,2,3,4,5,6,7,8,9};
    for(auto &i : v) {
        i = i & 1 == 1 ? i * 2 : i;
    }
    for(const auto &i : v) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}