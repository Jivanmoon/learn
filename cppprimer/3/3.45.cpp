#include<bits/stdc++.h>
using namespace std;
int main() {
    int ia[3][4] = {0,1,2,3,4,5,6,7,8,9,10,11};

    using int_array = int[4];

    for(auto &tmp : ia) {
        for(int t : tmp) {
            cout << t << " ";
        }
        cout << endl;
    }
    cout << "=====================" << endl;

    for(size_t i = 0; i < 3; ++i) {
        for(size_t j = 0; j < 4; ++j) {
            cout << ia[i][j] << " ";
        }
        cout << endl;
    }

    cout << "=====================" << endl;

    for(auto i = begin(ia); i != end(ia); ++i) {
        for(auto j = begin(*i); j != end(*i); ++j) {
            cout << *j << " ";
        }
        cout << endl;
    }
}