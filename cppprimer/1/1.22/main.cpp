#include<iostream>
#include "Sales_item.h"
using namespace std;

int main() {
    Sales_item book, sum;
    if(cin >> sum) {
        while(cin >> book) {
            sum += book;
        }
    }
    cout << sum << endl;
    return 0;
}