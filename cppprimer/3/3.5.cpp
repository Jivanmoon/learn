#include<string>
#include<iostream>
using namespace std;
int main() {
    string s, sum;
    // while(cin >> s) {
    //     sum += s;
    // }
    // cout << sum << endl;

    //改写
    sum.empty();
    while(cin >> s) {
        sum += s + ' ';
    }
    cout << sum << endl;
}