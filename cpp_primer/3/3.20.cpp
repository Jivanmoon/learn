#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main() {
    vector<int> v;
    int i;
    while(cin >> i) {
        v.push_back(i);
    }
    for(int i = 0; i < v.size(); i += 2) {
        int sum = v[i];
        if(i + 1 < v.size()) sum += v[i + 1];
        cout << sum << endl;
    }

    for(int i = 0; i < v.size() / 2; i ++) {
        cout << v[i] + v[v.size() - 1 - i] << endl;
    }
    return 0;
}