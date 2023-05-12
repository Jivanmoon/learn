#include <bits/stdc++.h>
using namespace std;

int main()
{
    list<int> li = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    deque<int> odd, even;
    for(auto t : li) {
        if(t & 1) {
            odd.push_back(t);
        }
        else {
            even.push_back(t);
        }
    }
    for(auto t : odd) cout << t << ends;
    cout << endl;
    for(auto t : even) cout << t << ends;
    cout << endl;
    exit(0);
}