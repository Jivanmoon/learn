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

double print_total(std::ostream &os, const Quote &item, size_t n);


//Bulk_quote
class Bulk_quote: public Quote {

public:
    Bulk_quote() = default;
    Bulk_quote(const string &book, double p, size_t qty, double disc):
        Quote(book, p), min_qty(qty), discount(disc) {}
    double net_price(size_t) const override;
    void debug() const override;
private:
    size_t min_qty = 0;
    double discount = 0.0;
};

class Limit_quote: public Quote {
public:
    Limit_quote() = default;
    Limit_quote(const string &book, double p, size_t lmt, double disc):
        Quote(book, p), limit(lmt), discount(disc) {}
    double net_price(size_t) const override;
    void debug() const override;
private:
    size_t limit = 0;
    double discount = 0.0;
};