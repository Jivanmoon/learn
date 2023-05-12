#include<bits/stdc++.h>
using namespace std;

int main() {
    vector<int> v = {1,2,3,4,5,3,2,1};
    auto cnt = count(v.cbegin(), v.cend(), 0);
    cout << cnt << endl;
    return 0;
}