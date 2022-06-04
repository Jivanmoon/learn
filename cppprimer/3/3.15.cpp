#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main() {
    vector<string> words;
    string word;
    while(cin >> word) {
        words.push_back(word);
    }
    return 0;
}