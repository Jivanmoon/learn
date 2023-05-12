#include "Basket.h"

double Basket::total_receipt(std::ostream &os) const {
    double sum = 0.0;
    for(auto iter = items.begin(); iter != items.end(); iter = items.upper_bound(*iter)) {
        sum += print_total(os, **iter, items.count(*iter));
    }
    os << "Total Sale: " << sum << std::endl;
    return sum;
}