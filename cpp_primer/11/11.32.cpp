#include<bits/stdc++.h>
using namespace std;

int main() {
    multimap<string, string> mp{
		{ "alan", "DMA" },
		{ "pezy", "LeetCode" },
		{ "alan", "CLRS" },
		{ "wang", "FTP" },
		{ "pezy", "CP5" },
		{ "wang", "CPP-Concurrency" } 
    };
    map<string, set<string>> order_mp;
    for(const auto &p : mp) {
        order_mp[p.first].insert(p.second);
    }
    for(const auto &p : order_mp) {
        cout << p.first << ":";
        for(const auto &t : p.second) {
            cout << t << " ";
        }
        cout << endl;
    }
    return 0;
}