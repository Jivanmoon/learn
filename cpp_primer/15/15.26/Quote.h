#include <iostream>
#include <string>
using std::string;

// Quote
class Quote {
public:
    Quote() { std::cout << "Quote 默认构造函数" << std::endl; }
    Quote(const string &book, double sales_price) : bookNo(book), price(sales_price) {
        std::cout << "Quote 两个参数移动函数" << std::endl;
    }

    Quote(const Quote &x);
    Quote(Quote &&x);
    Quote &operator=(const Quote &rhs);
    Quote &operator=(Quote &&rhs) noexcept;

    virtual ~Quote() {
        std::cout << "Quote 析构函数" << std::endl;
    }

    string isbn() const { return bookNo; }
    virtual double net_price(size_t n) const {
        return n * price;
    }

protected:
    string bookNo;
    double price = 0.0;
};

// Bulk_quote
class Bulk_quote : public Quote {

public:
    using Quote::Quote;
    Bulk_quote() {
        std::cout << "Bulk_quote 默认构造函数" << std::endl;
    }
    Bulk_quote(const string &book, double p, size_t qty, double disc) : Quote(book, p), min_qty(qty), discount(disc) {
        std::cout << "Bulk_quote 四个参数移动函数" << std::endl;
    }

    Bulk_quote(const Bulk_quote &x);
    Bulk_quote(Bulk_quote &&x);
    Bulk_quote &operator=(const Bulk_quote &rhs);
    Bulk_quote &operator=(Bulk_quote &&rhs) noexcept;

    virtual ~Bulk_quote() {
        std::cout << "Bulk_quote 析构函数" << std::endl;
    }

    double net_price(size_t) const override;

private:
    size_t min_qty  = 0;
    double discount = 0.0;
};