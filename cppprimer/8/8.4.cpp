#include<bits/stdc++.h>
using namespace std;

int main() {
    ifstream fin("8.4.data");
    vector<string> vs;
    string word;
    while(getline(fin, word)) {
        vs.push_back(word);
    }
    for(const auto &s : vs) {
        cout << s << endl;
    }
    return 0;
}