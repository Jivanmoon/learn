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
    auto idx = mp.find("alan");
    if(idx != mp.end()) {
        mp.erase("alan");
    }
    for(const auto &p : mp) {
        cout << p.first <<":" << p.second << endl;
    }
    return 0;
}