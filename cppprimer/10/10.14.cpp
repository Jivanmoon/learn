
#include<bits/stdc++.h>
using namespace std;

int main() {
    auto func = [](const int &x, const int &y) {return x + y;};
    int sum = func(10, 20);
    cout << sum << endl;
    return 0;
}