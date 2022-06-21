#include <bits/stdc++.h>
using namespace std;

vector<int>::const_iterator func(vector<int>::const_iterator begin, vector<int>::const_iterator end, int x)
{
    while (begin != end)
    {
        if (*begin == x)
            return begin;
        ++begin;
    }
    return end;
}

int main()
{
    vector<int> vi = {1, 2, 3, 4};
    auto idx = func(vi.cbegin(), vi.cend(), 6);
    if(idx == vi.cend()) {
        cout << "not find" << endl;
    }
    else cout << *idx << endl;
    return 0;
}