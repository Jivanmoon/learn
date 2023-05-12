#include<bits/stdc++.h>
using namespace std;

struct Sales_data {
    //函数成员
    std::string isbn() const {return bookNo;}
    Sales_data &combine(const Sales_data &);


    //数据成员
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

Sales_data &Sales_data::combine(const Sales_data &rhs) {
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}