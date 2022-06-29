#include<bits/stdc++.h>
using namespace std;

int main() {
    vector<int> v = {1,2,3,4,5};
    auto i = v.cend();
    do {
        --i;
        cout << *i << " ";
    } while(i != v.cbegin());
    cout << endl;
    return 0;
}