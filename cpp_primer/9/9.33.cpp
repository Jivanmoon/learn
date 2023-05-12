#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> vi = {1,2,3};
    auto begin = vi.begin();
    while(begin != vi.end()) {
        ++begin;
        begin = vi.insert(begin, 42);
        ++begin;
    }
    for(const auto &t : vi) {
        cout << t << " ";
    }
    cout << endl;
    return 0;
}