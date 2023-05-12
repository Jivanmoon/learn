#include<bits/stdc++.h>
using namespace std;

map<string, string> build_map(ifstream &map_file) {
    map<string, string> trans_map;
    string word, trans_word;;
    while(map_file >> word && getline(map_file, trans_word)) {
        if(trans_word.size() > 1) {
            trans_map[word] = trans_word.substr(1);
        }
        else {
            throw new runtime_error("no transfrom word for" + word);
        }
    }
    return trans_map;
}

const string &
transform(const string &s, const map<string, string> &m) {
    auto map_it = m.find(s);
    if(map_it != m.cend()) 
        return map_it->second;
    else 
        return s;
}


void word_transfrom(ifstream &map_file, ifstream &input) {
    auto trans_map = build_map(map_file);
    string line;
    while(getline(input, line)) {
        stringstream ss;
        ss << line;
        string word;
        bool is_not_first = false;
        while(ss >> word) {
            if(is_not_first) cout << " ";
            cout << transform(word, trans_map);
            is_not_first = true;
        }
        cout << endl;
    }
}

int main() {
    ifstream fin1("rules"), fin2("text");
    word_transfrom(fin1, fin2);
    return 0;
}