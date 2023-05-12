#include<string>
#include<iostream>
using std::string;

//Quote
class Quote {
public:
    Quote() = default;
    Quote(const string &book, double sales_price):
        bookNo(book), price(sales_price) {}
    string isbn() const {return bookNo;}
    virtual ~Quote() = default;
    virtual double net_price(size_t n) const {
        return n * price;
    }
     
protected:
    string bookNo;
    double price = 0.0;
};

//Disc_quote
class Disc_quote: public Quote {
public:
    Disc_quote() = default;
    Disc_quote(const std::string &book, double price, size_t qty, double disc):
        Quote(book, price), quantity(qty), discount(disc) {}
    virtual double net_price(size_t) const = 0;
protected:
    size_t quantity = 0;
    double discount = 0.0;
};

//Bulk_quote
class Bulk_quote: public Disc_quote {

public:
    using Disc_quote::Disc_quote;
    double net_price(size_t) const override;
};

//Limit_quote
class Limit_quote: public Disc_quote {
public:
    using Disc_quote::Disc_quote;
    double net_price(size_t) const override;
};


double print_total(std::ostream &os, const Quote &item, size_t n);