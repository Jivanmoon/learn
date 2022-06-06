#include<bits/stdc++.h>
using namespace std;
int main() {
    int ia[3][4] = {0,1,2,3,4,5,6,7,8,9,10,11};
    for(const int (&tmp)[4] : ia) {
        for(const int t : tmp) {
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

    for(const int (*i)[4] = begin(ia); i != end(ia); ++i) {
        for(const int *j = begin(*i); j != end(*i); ++j) {
            cout << *j << " ";
        }
        cout << endl;
    }
}