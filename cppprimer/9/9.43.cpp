#include <bits/stdc++.h>
using namespace std;

void func(string &s, const string &oldVal, const string &newVal){
    auto i = s.begin();
    while(i != s.end() - oldVal.size()) {
        if(oldVal == string(i, i + oldVal.size())) {
                i = s.erase(i, i + oldVal.size());
                i = s.insert(i, newVal.cbegin(), newVal.cend());
                i += newVal.size();
        }
        else ++i;
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