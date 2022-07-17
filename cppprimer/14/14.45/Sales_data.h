#ifndef SALES_DATA_H
#define SALES_DATA_H

#include<string>
#include<iostream>

class Sales_data;
//非函数成员
Sales_data operator+(const Sales_data &, const Sales_data &);
std::ostream &operator<<(std::ostream &, const Sales_data &);
std::istream &operator>>(std::istream &, Sales_data &);

class Sales_data {

    //友元声明
    friend Sales_data operator+(const Sales_data &, const Sales_data &);
    friend std::ostream &operator<<(std::ostream &, const Sales_data &);
    friend std::istream &operator>>(std::istream &, Sales_data &);

public:
    //构造函数
    Sales_data(const std::string &s, unsigned n, double p) :
        bookNo(s), units_sold(n), revenue(p * n) {}
    Sales_data() : Sales_data("", 0, 0.0) {}
    Sales_data(const std::string &s) : Sales_data(s, 0, 0.0) {}
    
    Sales_data(std::istream &in) : Sales_data() {
        in >> *this;
    }

    Sales_data& operator=(const std::string &isbn) {
        bookNo = isbn;
        units_sold = 0;
        revenue = 0.0;
        return *this;
    }

    //函数成员
    std::string isbn() const {return bookNo;}
    Sales_data &operator+=(const Sales_data &);

    //类型转换运算符
    explicit operator std::string() const {
        return bookNo;
    }

    explicit operator double() const {
        return revenue;
    }

    explicit operator bool() const {
        return !bookNo.empty();
    }
    
private:
    double avg_price() const;

    //数据成员
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

inline
double Sales_data::avg_price() const {
    if(units_sold) 
        return revenue / units_sold;
    else
        return 0;
}

#endif