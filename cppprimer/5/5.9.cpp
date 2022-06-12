#include<bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    int aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0;
    for(const auto &c : s) {
        if(c == 'a') ++aCnt;
        else if(c == 'e') ++eCnt; 
        else if(c == 'i') ++iCnt;
        else if(c == 'o') ++oCnt;
        else if(c == 'u') ++uCnt;
    }
    cout << aCnt << endl;
    cout << eCnt << endl;
    cout << iCnt << endl;
    cout << oCnt << endl;
    cout << uCnt << endl;
    return 0;
}