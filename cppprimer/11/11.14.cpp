#include <bits/stdc++.h>
using namespace std;
using Family = map<string, vector<pair<string, unsigned>>>;

void add_family(const string &family_name, Family &family_map)
{
    family_map[family_name].clear();
}

void add_child(const string &family_name, const string &name, const unsigned &age,Family &family_map)
{
    auto it = family_map.find(family_name);
    if (it != family_map.end())
    {
        it->second.push_back({name, age});
    }
}

int main()
{
    Family family_map;

    add_family("Liu", family_map);
    add_family("Li", family_map);

    add_child("Liu", "Diwen", 12, family_map);
    add_child("Liu", "Miemie", 14, family_map);
    add_child("Li", "Meili", 16, family_map);

    for (const auto &pair : family_map)
    {
        const auto &family_name = pair.first;
        cout << "family: " << family_name << endl;
        for (const auto &name_age : pair.second)
        {
            cout << name_age.first << ":" << name_age.second << endl;
        }
        cout << "---------" << endl;
    }

    return 0;
}
