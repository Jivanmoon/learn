#include<bits/stdc++.h>
using namespace std;

int main() {
    list<string> li;
    string word;
    while(cin >> word) {
        li.push_back(word);
    }
    auto cnt = count(li.cbegin(), li.cend(), "world");
    cout << cnt << endl;
    return 0;
}