#include<bits/stdc++.h>
using namespace std;

int main() {
    int x = 10;
    auto func = [x] () mutable -> bool {
        if(x == 0) return true;
        else {
            --x;
            return false;
        }
    };
    int n = 12;
    while(n--) {
        cout << ((func() == 1) ? "true" : "false") << endl;
    }
    return 0;
}