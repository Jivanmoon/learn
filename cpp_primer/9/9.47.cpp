#include <bits/stdc++.h>
using namespace std;

void func1(const string &s) {
    string nums("0123456789");
    string::size_type pos = 0;
    while((pos = s.find_first_of(nums, pos)) != string::npos) {
        cout << s[pos] << " ";
        ++pos;
    }
}

void func2(const string &s) {
    string nums = "0123456789";
    string::size_type pos = 0;
    while((pos = s.find_first_not_of(nums, pos)) != string::npos) {
        cout << s[pos] << " ";
        ++pos;
    }
}

int main()
{
    string s = "ab2c3d7R4E6";
    cout << "func1" << endl;
    func1(s);
    cout << "\nfunc2" << endl;
    func2(s);
    cout << endl;
    exit(0);
}