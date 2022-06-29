#include<bits/stdc++.h>
using namespace std;

int main() {
    vector<int> v = {1,2,3,4,5,3,2,1};
    sort(v.begin(), v.end());
    vector<int> vc;
    unique_copy(v.cbegin(), v.cend(), back_inserter(vc));
    for(auto t : vc) {
        cout << t << " ";
    }
    cout << endl;
    return 0;
}