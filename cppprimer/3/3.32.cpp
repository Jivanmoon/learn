#include<bits/stdc++.h>
using namespace std;
int main() {
    int a[10];
    for(int i = 0; i < 10; ++i) {
        a[i] = i;
    }
    int b[10];
    for(int i = 0; i < 10; ++i) {
        b[i] = a[i];
    }

    vector<int> va(10);
    for(int i = 0; i < 10; ++i) {
        va[i] = i;
    }
    vector<int> vb = va;
    return 0;
}