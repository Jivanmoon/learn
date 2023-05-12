#include "Quote.h"
using std::cout;
using std::endl;
double print_total(std::ostream &os, const Quote &item, size_t n) {
    double ret = item.net_price(n);
    os << "ISBN: " << item.isbn() << " # sold: " << n << " total due: " << ret << std::endl;
    return ret;
}


double Bulk_quote::net_price(size_t cnt) const {
    if(cnt >= quantity)
        return cnt * (1 - discount) * price;
    else
        return cnt * price;
}


double Limit_quote::net_price(size_t cnt) const {
    if(cnt <= quantity) 
        return cnt * (1 - discount) * price;
    else 
        return quantity * (1 - discount) * price + (cnt - quantity) * price;
}

// int main() {
//     Disc_quote d;
// }