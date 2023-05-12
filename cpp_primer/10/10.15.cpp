
#include<bits/stdc++.h>
using namespace std;

int func() {
    int x = 10;
    auto f = [x](const int &y) {return x + y;};
    return f(20);
}

int main() {
    
    int sum = func();
    cout << sum << endl;
    return 0;
}