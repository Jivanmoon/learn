#include<bits/stdc++.h>
using namespace std;

int main() {
    vector<string> words{
        "dsadsadsa", "3213213123", "sad", "123"
    };
    auto cnt = count_if(words.begin(), words.end(), 
        [](const string &s) {
            return s.size() > 6;
        }
    );
    cout << cnt << endl;
    return 0;
}