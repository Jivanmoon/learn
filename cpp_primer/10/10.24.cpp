#include<bits/stdc++.h>
using namespace std;
using namespace std::placeholders;

bool check_size(const string &word, string::size_type sz) {
    return sz > word.size();
}

int main() {
    string s("hello, world");
    auto func = bind(check_size, s, _1);
    vector<int> v{
        1,2,3,43,54,65,5,3
    };
    auto idx = find_if(v.cbegin(), v.cend(), func);
    cout << *idx << endl;
    return 0;
}