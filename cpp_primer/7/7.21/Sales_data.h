#ifndef SALES_DATA_H
#define SALES_DATA_H

#include<string>
#include<iostream>

class Sales_data;
//非函数成员
Sales_data add(const Sales_data &, const Sales_data &);
std::ostream &print(std::ostream &, const Sales_data &);
std::istream &read(std::istream &, Sales_data &);

class Sales_data {

    //友元声明
    friend Sales_data add(const Sales_data &, const Sales_data &);
    friend std::ostream &print(std::ostream &, const Sales_data &);
    friend std::istream &read(std::istream &, Sales_data &);

public:
    //构造函数
    Sales_data() = default;
    Sales_data(const std::string &s) : bookNo(s) {}
    Sales_data(const std::string &s, unsigned n, double p) :
        bookNo(s), units_sold(n), revenue(p * n) {}
    Sales_data(std::istream &in) {
        read(in, *this);
    }

    //函数成员
    std::string isbn() const {return bookNo;}
    Sales_data &combine(const Sales_data &);
    
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