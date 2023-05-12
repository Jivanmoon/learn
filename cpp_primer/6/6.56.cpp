#include<bits/stdc++.h>
using namespace std;

int f1(int x, int y) {
    return x + y;
}

int f2(int x, int y) {
    return x - y;
}

int f3(int x, int y) {
    return x * y;
}

int f4(int x, int y) {
    return x / y;
}
int main() {
    vector<int (*)(int, int)> vi = {f1, f2, f3, f4};
    int a = 4, b = 2;
    decltype(f1) *f;
    for(int i = 0; i < vi.size(); ++i) {
        f = vi[i];
        cout << f(a, b) << endl;
    }
    return 0;
}
