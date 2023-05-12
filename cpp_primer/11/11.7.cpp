#include<bits/stdc++.h>
using namespace std;
using Family = map<string, vector<string>>;

void add_family(const string &family_name, Family &family_map)
{
	family_map[family_name].clear();
}

void add_child(const string &family_name, const string &name, Family &family_map)
{
	auto it = family_map.find(family_name);
	if (it != family_map.end())
	{
		it->second.push_back(name);
	}
}

int main()
{
	Family family_map;

	add_family("Liu", family_map);
	add_family("Li", family_map);

	add_child("Liu", "Diwen", family_map);
	add_child("Liu", "Miemie", family_map);
	add_child("Li", "Meili", family_map);

	for (const auto &pair : family_map)
	{
		const auto &family_name = pair.first;
		cout << "family: " << family_name << endl;
		for (const auto &name : pair.second)
		{
			cout << name << endl;
		}
		cout << "---------" << endl;
	}

	return 0;
}
