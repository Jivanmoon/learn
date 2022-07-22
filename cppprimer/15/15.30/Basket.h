#pragma once
#include "Quote.h"
#include <iostream>
#include <memory>
#include <set>
using std::cout;
using std::endl;
using std::shared_ptr;

class Basket {
public:
    void add_item(const Quote &sale) {
        items.insert(shared_ptr<Quote>(sale.clone()));
    }
    void add_item(Quote &&sale) {
        items.insert(shared_ptr<Quote>(std::move(sale).clone()));
    }
    double total_receipt(std::ostream &) const;
private:
    static bool compare(const shared_ptr<Quote> &lhs, const shared_ptr<Quote> &rhs) {
        return lhs->isbn() < rhs->isbn();
    }
    std::multiset<shared_ptr<Quote>, decltype(compare) *> items{compare};
};