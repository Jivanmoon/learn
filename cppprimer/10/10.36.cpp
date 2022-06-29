#include<bits/stdc++.h>
using namespace std;

int main() {
    list<int> li{1,3,0,5,0,8};
    auto idx = find(li.crbegin(), li.crend(), 0);
    cout << distance(idx, li.crend()) << endl;
    return 0;
}