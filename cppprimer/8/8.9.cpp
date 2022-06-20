#include<bits/stdc++.h>
using namespace std;

istream &func(istream &in) {
    string tmp;
    while(in >> tmp) {
        cout << tmp << endl;
    }
    in.clear();
    return in;
}

int main() {
    istringstream sin("hello, world");
    func(sin);
    return 0;
}