#include<iostream>
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
    istream & in = func(cin);
    cout << in.rdstate() << endl;
    return 0;
}