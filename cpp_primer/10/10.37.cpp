#include<bits/stdc++.h>
using namespace std;

int main() {
    vector<int> v = {1,2,3,4,5,6,7,8,9,10};
    list<int> li;
    copy(v.cbegin() + 2, v.cbegin() + 7, front_inserter(li));
    for(const auto &t : li) {
        cout << t << " ";
    }
    cout << endl;
    return 0;
}