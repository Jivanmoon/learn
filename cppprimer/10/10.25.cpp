#include<bits/stdc++.h>
using namespace std;
using namespace std::placeholders;

bool check_size(const string &s, string::size_type sz) {
    return s.size() >= sz;
}

void elimDups(vector<string> &v) {
    stable_sort(v.begin(), v.end());
    auto rm_idx = unique(v.begin(), v.end());
    v.erase(rm_idx, v.end());
}

void biggies(vector<string> &words, vector<string>::size_type sz) {
    elimDups(words);
    stable_sort(words.begin(), words.end(),
        [](const string &x, const string &y) {
            return x.size() < y.size();
        }
    );
    auto wc = partition(words.begin(), words.end(), bind(check_size, _1, sz));
    for_each(words.begin(), wc,
        [](const string &s) {
        cout << s << " ";
    });
    cout << endl;
}

int main() {
    vector<std::string> v{
	    "1234", "1234", "1234", "hi~", "alan", "alan", "cp"
    };
    biggies(v, 3);
    return 0;
}