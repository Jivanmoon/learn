#include<bits/stdc++.h>
using namespace std;

void func(forward_list<string> &fs, const string &s1, const string &s2) {
    auto prev = fs.before_begin();
    auto cur = fs.begin();
    while(cur != fs.end()) {
        if(*cur != s1) {
            prev = cur;
            ++cur;
        }
        else {
            fs.insert_after(cur, s2);
            return ;
        }
    }
    if(cur == fs.end()) {
        fs.insert_after(prev, s2);
    }
}

int main() {
    forward_list<string> fs = {"hello", "world"};
    //func(fs, "hello", "......");
    func(fs, "helloo", "......");
    for(const auto &s : fs) {
        cout << s << endl;
    }
    return 0;
}