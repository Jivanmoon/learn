#include <bits/stdc++.h>
using namespace std;

int main()
{
    list<int> l1 = {1, 2, 3};
    vector<int> v1 = {1, 2, 3};
    auto lit = l1.begin();
    auto vit = v1.begin();
    while(lit != l1.end() && vit != v1.end()) {
        if(*lit != *vit) {
            cout << "no same" << endl;
            exit(0);
        }
        ++lit;
        ++vit;
    }
    if(l1.size() != v1.size()) cout << "no same" << endl;
    else cout << "same" << endl;
    exit(0);
}