#include<bits/stdc++.h>
using namespace std;

void print(const deque<int> &v) {
    for(const auto &t : v) {
        cout << t << " ";
    }
    cout << endl;
}

int main() {
    vector<int> v;
    for(int i = 1; i < 10; ++i) {
        v.push_back(i);
    }
    deque<int> vc1, vc2, vc3;
    copy(v.cbegin(), v.cend(), inserter(vc1, vc1.begin()));
    copy(v.cbegin(), v.cend(), back_inserter(vc2));
    copy(v.cbegin(), v.cend(), front_inserter(vc3));
    print(vc1);
    print(vc2);
    print(vc3);
    return 0;
}