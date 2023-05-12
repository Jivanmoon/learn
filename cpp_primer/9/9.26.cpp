#include<bits/stdc++.h>
using namespace std;

int main() {
    int ia[] = {0,1,1,2,3,5,8,13,21,55,89};
    vector<int> iv;
    list<int> il;
    for(auto i = begin(ia); i != end(ia); ++i) {
        iv.push_back(*i);
        il.push_back(*i);
    }
    auto i = il.begin();
    while(i != il.end()) {
        if((*i) & 1) {
            i = il.erase(i);
        }
        else 
            ++i;
    }

    auto j = iv.begin();
    while(j != iv.end()) {
        if(!((*j) & 1)) {
            j = iv.erase(j);
        }
        else
            ++j;
    }
    for(const auto &t : il) {
        cout << t << " ";
    }
    cout << endl;
    for(const auto &t : iv) {
        cout << t << " ";
    }
    cout << endl;
    return 0;
}