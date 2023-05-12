#include <bits/stdc++.h>
using namespace std;

int func(initializer_list<int> li)
{
    int sum = 0;
    for (auto t : li)
    {
        sum += t;
    }
    return sum;
}

int main(int argc, char **argv)
{
    cout << func({1, 2, 3, 4, 5}) << endl;
    return 0;
}