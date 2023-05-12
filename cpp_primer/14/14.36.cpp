#include<bits/stdc++.h>
using namespace std;

class InputString {
public:
    InputString(istream &in = cin): in(in) {}
    string operator()() {
        string s;
        getline(in, s);
        if(in) return s;
        else return string();
    }    
private:
    istream &in;
};

int main() {
    InputString in;
    vector<string> vs;
    string s;
    while((s = in()) != "") {
        vs.push_back(s);
    }
    for(auto &s : vs) {
        cout << s << endl;
    }
}