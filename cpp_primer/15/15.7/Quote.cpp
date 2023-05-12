#include "Quote.h"
using std::cout;
using std::endl;
double print_total(std::ostream &os, const Quote &item, size_t n) {
    double ret = item.net_price(n);
    os << "ISBN: " << item.isbn() << " # sold: " << n << " total due: " << ret << std::endl;
    return ret;
}

void Quote::debug() const {
    cout << "This is Quote class." << endl;
    cout << "bookNo = " << bookNo << " price = " << price << endl;
}

double Bulk_quote::net_price(size_t cnt) const {
    if(cnt >= min_qty)
        return cnt * (1 - discount) * price;
    else
        return cnt * price;
}

void Bulk_quote::debug() const {
    cout << "This is Bulk_quote class." << endl;
    cout << " price = " << price << endl;
    cout << "min_qty = " << min_qty << " discount = " << discount << endl;
}

double Limit_quote::net_price(size_t cnt) const {
    if(cnt <= limit) 
        return cnt * (1 - discount) * price;
    else 
        return limit * (1 - discount) * price + (cnt - limit) * price;
}

void Limit_quote::debug() const {
    cout << "This is Limit_quote class." << endl;
    cout << " price = " << price << endl;
    cout << "limit = " << limit << " discount = " << discount << endl;
}