#include<bits/stdc++.h>
using namespace std;

int main() {
    ifstream fin("10.29.data");
    istream_iterator<string> in_iter(fin), eof;
    ostream_iterator<string> out_iter(cout, "\n");
    vector<string> vs;
    while(in_iter != eof) {
        vs.push_back(*in_iter++);
    }
    for(const auto &s : vs) {
        *out_iter++ = s;
    }
    return 0;
}