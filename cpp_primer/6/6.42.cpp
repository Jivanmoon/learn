#include<bits/stdc++.h>
using namespace std;

string make_plural(size_t ctr, const string &word, const string &ending = "s") {
    return (ctr > 1) ? word + ending : word;
}

int main() {
    string a = "success", b = "failure";
    cout << make_plural(1, a) << endl;
    cout << make_plural(2, b) << endl;
    return 0;
}
