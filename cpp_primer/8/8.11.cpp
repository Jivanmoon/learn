#include<bits/stdc++.h>
using namespace std;

struct PersonInfo {
    string name;
    vector<string> phones;
};

int main() {
    string line, word;
    vector<PersonInfo> peoples;
    istringstream record;
    while(getline(cin, line)) {
        PersonInfo info;
        record.clear();
        record.str(line);
        record >> info.name;
        while(record >> word) 
            info.phones.push_back(word);
        peoples.push_back(info);
    }   
    for (auto &p : peoples)
	{
		std::cout << p.name << " ";
		for (auto &s : p.phones)
			std::cout << s << " ";
		std::cout << std::endl;
	}
    return 0;
}

