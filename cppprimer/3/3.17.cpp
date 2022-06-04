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
    for(string &s : words) {
        for(char &c : s)
            c = toupper(c);
    }
    for(string &s : words) 
        cout << s << endl;
    return 0;
}