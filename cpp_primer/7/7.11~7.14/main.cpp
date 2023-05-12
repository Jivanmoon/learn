#include "Sales_data.h"
using std::cin;
using std::cout;
using std::endl;
using std::cerr;
int main() {
    //7.11
    // Sales_data item1;
	// print(std::cout, item1) << std::endl;

	// Sales_data item2("0-201-78345-X");
	// print(std::cout, item2) << std::endl;

	// Sales_data item3("0-201-78345-X", 3, 20.00);
	// print(std::cout, item3) << std::endl;

	// Sales_data item4(std::cin);
	// print(std::cout, item4) << std::endl;

    //7.13
    Sales_data total(cin);
    if(cin) {
        while(cin) {
            Sales_data trans(cin);
            if(trans.isbn() == total.isbn()) {
                total.combine(trans);
            }
            else {
                print(cout, total);
                cout << endl;
                total = trans;
            }
        }
    }
    else {
        cerr << "No data?" << endl;
        return 1;
    }
    return 0;
}