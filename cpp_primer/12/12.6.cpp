#include<bits/stdc++.h>
using namespace std;

vector<int> *create() {
    return new vector<int>();
}

void input(vector<int> *v) {
    int t;
    while(cin >> t) {
        v->push_back(t);
    }
}

void print(vector<int> *v) {
    for(const auto &t : *v) {
        cout << t << " ";
    }
    cout << endl;
    delete v;
}

int main() {
    auto t = create();
    input(t);
    print(t);
    return 0;
}