#include <bits/stdc++.h>
using namespace std;

struct PersonInfo
{
    string name;
    vector<string> phones;
};

bool valid(const string &str)
{
    return isdigit(str[0]);
}

string format(const string &str)
{
    return str.substr(0, 3) + "-" + str.substr(3, 3) + "-" + str.substr(6);
}

int main(int argc, char **argv)
{
    ifstream fin(argv[1]);
    if (!fin)
    {
        cerr << "open file failure" << endl;
        exit(1);
    }
    string line, word;
    vector<PersonInfo> peoples;
    istringstream record;
    while (getline(fin, line))
    {
        PersonInfo info;
        record.clear();
        record.str(line);
        record >> info.name;
        while (record >> word)
            info.phones.push_back(word);
        peoples.push_back(info);
    }
    for (const auto &entry : peoples)
    {
        ostringstream formatted, badNums;
        for (const auto &nums : entry.phones)
            if (!valid(nums))
                badNums << " " << nums;
            else
                formatted << " " << format(nums);
        if (badNums.str().empty())
            cout << entry.name << " " << formatted.str() << endl;
        else
            cerr << "input error: " << entry.name
                 << " invalid number(s) " << badNums.str() << endl;
    }
    return 0;
}
