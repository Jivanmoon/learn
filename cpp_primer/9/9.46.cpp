#include <bits/stdc++.h>
using namespace std;

string func(string name, const string &pre, const string &last){
    name.insert(0, pre);
    name.insert(name.size(), last);
    return name;
}

int main()
{
    string name = "jivan";
    name = func(name, "Mr.", "III");
    cout << name << endl;
    return 0;
}