#include<string>
#include<iostream>
using namespace std;
int main() {
    //一次读入一行
    // string line;
    // getline(cin, line);
    // cout << line << endl;

    //一次读入一个词
    string word;
    while(cin >> word) {
        cout << word << endl;
    }
    return 0;
}