#include<string>
#include<iostream>
using namespace std;
int main() {
    string s1, s2;
    cin >> s1 >> s2;
    if(s1 == s2) cout << "相等" << endl;
    else {
        string big = s1 > s2 ? s1 : s2;
        cout << big << endl;
    }

    //改写
    if(s1.length() == s2.length()) cout << "等长" << endl;
    else {
        string lengther = s1.length() > s2.length() ? s1 : s2;
        cout << lengther << endl;
    }
}