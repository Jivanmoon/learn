#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main() {
    vector<string> text;
    text.push_back("i an a good man.");
    text.push_back("");
    text.push_back("but i like eat food.");

    for(auto it = text.begin(); it != text.end() && !it->empty(); ++it) {
        for(auto &c : *it) {
            if(isalpha(c)) {
                c = toupper(c);
            }
        }
        cout << *it << endl;
    }
    return 0;
}