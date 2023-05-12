#include "Sales_data.h"
#include<bits/stdc++.h>
using namespace std;

int main() {
    vector<Sales_data> v;
    Sales_data tmp;
    while(read(cin, tmp)) {
        v.push_back(tmp);
    }
    sort(v.begin(), v.end(), 
        [](const Sales_data &x, const Sales_data &y) {
            return x.isbn() < y.isbn();
        }
    );
    for(const auto &t : v) {
        print(cout, t);
        cout << endl;
    }
    return 0;
}