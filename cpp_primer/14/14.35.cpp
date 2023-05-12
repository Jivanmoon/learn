#include<bits/stdc++.h>
using namespace std;

class PrintString {
public:
    PrintString(istream &in = cin): in(in) {}
    string operator()() {
        string s;
        getline(in, s);
        if(in) return string();
        else return s;
    }    
private:
    istream &in;
};