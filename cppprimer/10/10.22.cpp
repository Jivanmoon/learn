#include<bits/stdc++.h>
using namespace std;
using namespace std::placeholders;

bool less_than_sz(const string &word, string::size_type sz) {
    return word.size() < sz;
}

int main() {
    vector<string> words{
        "dsadsadsa", "3213213123", "sad", "123", "1234"
    };
    auto less_than_6 = bind(less_than_sz, _1, 6);
    auto cnt = count_if(words.begin(), words.end(), less_than_6);
    cout << cnt << endl;
    return 0;
}