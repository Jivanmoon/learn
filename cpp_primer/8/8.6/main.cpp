#include "Sales_data.h"
#include<bits/stdc++.h>
using namespace std;
int main(int argc, char **argv) {
    ifstream fin(argv[1]);
    Sales_data total;
    if(read(fin, total)) {
        Sales_data trans;
        while(read(fin, trans)) {
            if(trans.isbn() == total.isbn()) {
                total.combine(trans);
            }
            else {
                print(cout, total);
                cout << endl;
                total = trans;
            }
        }
        print(cout, total);
        cout << endl;
    }
    else {
        cerr << "No data?" << endl;
        return 1;
    }
    return 0;
}