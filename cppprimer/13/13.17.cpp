#include<bits/stdc++.h>
using namespace std;

class numbered {
public:
    numbered() {
        mysn = i++;
    }
    numbered(const numbered &n) {
        mysn = i++;
    }
    static int i;
    int mysn;
};
int numbered::i = 1;

void f(const numbered &s) {
    cout << s.mysn << endl;
}

int main() {
    numbered a, b = a, c = a;
    f(a), f(b), f(c);
    return 0;
}