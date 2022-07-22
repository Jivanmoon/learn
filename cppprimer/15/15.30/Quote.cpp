#include "Quote.h"

Quote::Quote(const Quote &x)
    : bookNo(x.bookNo), price(x.price) {
    std::cout << "Quote 拷贝构造函数" << std::endl;
}

Quote::Quote(Quote &&x)
    : bookNo(std::move(x.bookNo)), price(std::move(x.price)) {
    std::cout << "Quote 移动构造函数" << std::endl;
}

Quote &Quote::operator=(const Quote &rhs) {
    std::cout << "Quote 拷贝赋值函数" << std::endl;
    if (this != &rhs) {
        bookNo = rhs.bookNo;
        price  = rhs.price;
    }
    return *this;
}

Quote &Quote::operator=(Quote &&rhs) noexcept {
    std::cout << "Quote 移动赋值函数" << std::endl;
    if (this != &rhs) {
        bookNo = std::move(rhs.bookNo);
        price  = std::move(rhs.price);
    }
    return *this;
}




double Bulk_quote::net_price(size_t cnt) const {
    if (cnt >= min_qty)
        return cnt * (1 - discount) * price;
    else
        return cnt * price;
}

Bulk_quote::Bulk_quote(const Bulk_quote &x)
    : Quote(x), min_qty(x.min_qty), discount(x.discount) {
    std::cout << "Bulk_quote 拷贝构造函数" << std::endl;
}

Bulk_quote::Bulk_quote(Bulk_quote &&x)
    : Quote(std::move(x)), min_qty(std::move(x.min_qty)), discount(std::move(x.discount)) {
    std::cout << "Bulk_quote 移动构造函数" << std::endl;
}

Bulk_quote &Bulk_quote::operator=(const Bulk_quote &rhs) {
    std::cout << "Bulk_quote 拷贝赋值函数" << std::endl;
    if (this != &rhs) {
        Quote::operator=(rhs);
        min_qty  = rhs.min_qty;
        discount = rhs.discount;
    }
    return *this;
}

Bulk_quote &Bulk_quote::operator=(Bulk_quote &&rhs) noexcept {
    std::cout << "Bulk_quote 移动赋值函数" << std::endl;
    if (this != &rhs) {
        Quote::operator=(std::move(rhs));
        min_qty = std::move(rhs.min_qty);
        discount  = std::move(rhs.discount);
    }
    return *this;
}

double print_total(std::ostream &os, const Quote &item, size_t n) {
    double ret = item.net_price(n);
    os << "ISBN: " << item.isbn() << " # sold: " << n << " total due: " << ret << std::endl;
    return ret;
}