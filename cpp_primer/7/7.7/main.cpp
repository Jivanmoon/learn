#include "Sales_data.h"
using std::cin;
using std::cout;
using std::endl;
using std::cerr;
int main() {
    Sales_data total;
    double price = 0.0;
    if(read(cin, total)) {
        Sales_data trans;
        while(read(cin, trans)) {
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