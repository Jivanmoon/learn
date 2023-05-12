#include <bits/stdc++.h>
using namespace std;

void func(string &s, const string &oldVal, const string &newVal){
    for(size_t i = 0; i < s.size() - oldVal.size(); ++i) {
        if(oldVal == s.substr(i, oldVal.size())) {
            s.replace(i, oldVal.size(), newVal);
        }
    }
}

int main()
{
    string word = "tho a is thru b thoiathru";
    func(word, "tho", "though");
    func(word, "thru", "through");
    cout << word << endl;
    return 0;
}