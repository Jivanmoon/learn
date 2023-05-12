#include<bits/stdc++.h>
using namespace std;
int main() {
    int a[3] = {1, 2, 3};
    vector<int> va(begin(a), end(a));
    for(auto t : va) 
        cout << t << endl;
    return 0;
}