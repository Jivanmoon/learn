#include<bits/stdc++.h>
using namespace std;

class Func {
public:
    Func(int l, int u): low(l), up(u) {}
    bool operator()(string &s) {
        return s.size() >= low && s.size() <= up;
    }

private:
    int low, up;
};

int main() {
    string line;
    int ans1 = 0, ans2 = 0;
    while(getline(cin, line)) {
        Func func1(1, 9), func2(2, INT_MAX);
        if(func1(line)) ++ans1;
        if(func2(line)) ++ans2;
    }
    cout << ans1 << endl;
    cout << ans2 << endl;
}