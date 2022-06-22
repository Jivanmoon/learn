#include <bits/stdc++.h>
using namespace std;

int main()
{
    list<int> li = {1, 2, 3};
    vector<int> vi = {2, 3, 4};
    vector<double> vd(li.begin(), li.end());
    vector<double> vdd(vi.begin(), vi.end());
    for(auto t : vd) {
        cout << t << ends;
    }
    cout << endl;

    for(auto t : vdd) {
        cout << t << ends;
    }
    cout << endl;
    return 0;
}