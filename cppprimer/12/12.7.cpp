#include<bits/stdc++.h>
using namespace std;

shared_ptr<vector<int>> create() {
    return make_shared<vector<int>>();
}

void input(shared_ptr<vector<int>> v) {
    int t;
    while(cin >> t) {
        v->push_back(t);
    }
}

void print(shared_ptr<vector<int>> v) {
    for(const auto &t : *v) {
        cout << t << " ";
    }
    cout << endl;
}

int main() {
    auto t = create();
    input(t);
    print(t);
    return 0;
}