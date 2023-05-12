#include<bits/stdc++.h>
using namespace std;
int main() {
    ifstream fin("12.28.data");
    vector<string> lines;
    unordered_map<string, set<size_t>> mp;
    string line;
    size_t num = 1;
    while(getline(fin, line)) {
        lines.push_back(line);
        istringstream sin(line);
        string word;
        while(sin >> word) {
            mp[word].insert(num);
        }
        ++num;
    }
    while(true) {
        cout << "enter word to look for, or q to quit: ";
        string s;
        if(!(cin >> s) || s == "q") break;
        if(mp.find(s) == mp.end()) {
            cout << "no this word" << endl;
        }
        else {
            auto &w_set = mp[s]; 
            cout << s << " occurs " << w_set.size() << " times" << endl;
            for(const auto &num : w_set) {
                cout << "\tline( " << num <<" ) " << lines[num - 1] << std::endl;
            }
        }
    }
}