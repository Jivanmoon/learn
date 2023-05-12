#include<iostream>
#include<vector>
#include<string>
using namespace std;

void vintprint(vector<int> &v) {
    cout << v.size() << endl;
    for(auto i : v) cout << i << " ";
    cout << endl;
}

void vsprint(vector<string> &v) {
    cout << v.size() << endl;
    for(auto i : v) cout << i << " ";
    cout << endl;
}


int main() {
    vector<int> v1;
    vintprint(v1);
    vector<int> v2(10);
    vintprint(v2);
    vector<int> v3(10, 42);
    vintprint(v3);
    vector<int> v4{10};
    vintprint(v4);
    vector<int> v5{10, 42};
    vintprint(v5);

    vector<string> v6{10};
    vsprint(v6);
    vector<string> v7{10, "hi"};
    vsprint(v7);
    return 0;
}