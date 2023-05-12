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
    virtual double net_price(size_t n) const {
        return n * price;
    }
    virtual ~Quote() = default;
    virtual void debug() const;
private:
    string bookNo;
protected:
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
    Bulk_quote() = default;
    Bulk_quote(const string &book, double p, size_t qty, double disc):
        Disc_quote(book, p, qty, disc) {}
    double net_price(size_t) const override;
    void debug() const override;
};

//Limit_quote
class Limit_quote: public Disc_quote {
public:
    Limit_quote() = default;
    Limit_quote(const string &book, double p, size_t lmt, double disc):
        Disc_quote(book, p, lmt, disc) {}
    double net_price(size_t) const override;
    void debug() const override;
};


double print_total(std::ostream &os, const Quote &item, size_t n);