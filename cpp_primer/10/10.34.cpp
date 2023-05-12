#include<bits/stdc++.h>
using namespace std;

int main() {
    vector<int> v = {1,2,3,4,5,3,2,7};
    for_each(v.crbegin(), v.crend(), 
        [](const int &x) {
            cout << x << " ";
        }
    );
    cout << endl;
    return 0;
}