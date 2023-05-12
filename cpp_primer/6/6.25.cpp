#include<bits/stdc++.h>
using namespace std;
int main(int argc, char **argv) {
    string ans;
    for(int i = 0; i < argc; ++i) {
        ans = ans + argv[i];
    }
    cout << ans << endl;
    return 0;
}