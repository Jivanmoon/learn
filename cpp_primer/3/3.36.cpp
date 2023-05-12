#include<bits/stdc++.h>
using namespace std;
bool fun1(const int a[], const int b[]) {
    if(sizeof(a) != sizeof(b)) return false;
    for(int i = 0; i < sizeof(a) / sizeof(int); ++i) {
        if(a[i] != b[i]) return false;
    }
    return true;
}

bool fun2(vector<int> &a, vector<int> &b) {
    return a == b;
}