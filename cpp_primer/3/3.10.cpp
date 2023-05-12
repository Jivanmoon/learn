#include<iostream>
#include<cctype>
using namespace std;

int main() {
    string s, tmp;
    cin >> s;
    for(char c : s) {
        if(ispunct(c)) continue;
        tmp += c;
    }
    cout << tmp << endl;
    return 0;
}