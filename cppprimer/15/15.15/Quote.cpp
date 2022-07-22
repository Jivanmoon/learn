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
    if(cnt >= quantity)
        return cnt * (1 - discount) * price;
    else
        return cnt * price;
}

void Bulk_quote::debug() const {
    cout << "This is Bulk_quote class." << endl;
    cout << " price = " << price << endl;
    cout << "quantity = " << quantity << " discount = " << discount << endl;
}

double Limit_quote::net_price(size_t cnt) const {
    if(cnt <= quantity) 
        return cnt * (1 - discount) * price;
    else 
        return quantity * (1 - discount) * price + (cnt - quantity) * price;
}

void Limit_quote::debug() const {
    cout << "This is Limit_quote class." << endl;
    cout << " price = " << price << endl;
    cout << "quantity = " << quantity << " discount = " << discount << endl;
}

int main() {
    Bulk_quote bq1("aaa", 12.5, 5, 0.3);
    Quote &q = bq1;
    print_total(std::cout, q, 10);
}