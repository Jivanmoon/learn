#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> vi = {1,2,3};
    auto i = vi.begin();
    while(i != vi.end()) {
        //cout << *i << " ";
        if(*i % 2) {
            i = vi.insert(i, *i);
        }
        ++i;
    }
    return 0;
}