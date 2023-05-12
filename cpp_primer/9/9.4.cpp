#include <bits/stdc++.h>
using namespace std;

bool func(vector<int>::const_iterator begin, vector<int>::const_iterator end, int x)
{
    while (begin != end)
    {
        if (*begin == x)
            return true;
        ++begin;
    }
    return false;
}

int main()
{
    vector<int> vi = {1, 2, 3, 4};
    cout << func(vi.cbegin(), vi.cend(), 3) << endl;
    return 0;
}