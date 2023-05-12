#include<iostream>
#include<string>
using namespace std;

int main() {
    string s;
    cin >> s;
    //while循环写
    int i = s.size();
    while(i--) {
        s[i] = 'X';
    }
    cout << s << endl;

    //传统for循环写
    for(int i = 0; i < s.size(); ++i) {
        s[i] = 'Y';
    }
    cout << s << endl;
    return 0;
}