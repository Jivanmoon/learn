#include<bits/stdc++.h>
using namespace std;

class IsEuqal {
public:
    IsEuqal() = default;
    IsEuqal(int n): num(n) {}
    bool operator()(int x) {
        return x == num;
    }
private:
    int num;
};

int main() {
    vector<int> vi{1,2,3,4,5,5,4,3,2,1};
    IsEuqal isequal(4);
    replace_if(vi.begin(), vi.end(), isequal, 8);
    for(auto &t : vi) {
        cout << t << " ";
    }
    cout << endl;
}
