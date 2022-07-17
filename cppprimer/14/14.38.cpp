#include<bits/stdc++.h>
using namespace std;

class Func {
public:
    Func(int n): num(n) {}
    bool operator()(string &s) {
        return s.size() == num;
    }

private:
    int num;
};

int main() {
    string line;
    vector<int> ans(11);
    while(getline(cin, line)) {
        for(int i = 1; i <= 10; ++i) {
            Func func(i);
            if(func(line)) ++ans[i];
        }
    }
    for(int i = 1; i <= 10; ++i) {
        cout << ans[i] << endl;
    }
}