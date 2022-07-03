#include<bits/stdc++.h>
#include "StrBlob.h"
using namespace std;

int main() {
    ifstream fin("data");
    string line;
    StrBlob sb;
    while(getline(fin, line)) {
        sb.push_back(line);
    }
    for(auto i = sb.begin(); !i.equal(sb.end()); i.incr()) {
        cout << i.deref() << endl;
    }
}