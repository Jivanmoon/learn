#include<bits/stdc++.h>
using namespace std;
int main() {
    vector<int> iv(10, 5);
    for(auto it = iv.begin(); it != iv.end(); ++it) {
        *it = (*it) * 2;
        cout << *it << " ";
    }
    cout << endl;
    return 0;
}