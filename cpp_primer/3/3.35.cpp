#include<bits/stdc++.h>
using namespace std;
int main() {
    int a[10];
    int *ab = begin(a), *ae = end(a);
    while(ab != ae) {
        *ab = 0;
        ++ab;
    }
    return 0;
}