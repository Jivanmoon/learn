/*
 *
 * 函数模板相关知识点
 *
 */
#include <iostream>
#include <cstring>
using namespace std;

template <typename T>
const T &max(const T &a, const T &b)
{
    return a < b ? b : a;
}

//函数模板特化
template <>
const char *const &max(const char *const &a, const char *const &b)
{
    return strcmp(a, b) < 0 ? b : a;
}

//函数模板重载
template <typename T>
const T &max(const T &a, const T &b, const T &c)
{
    return ::max(a, b) < c ? c : ::max(a, b);
}

//普通函数重载函数模板
//普通函数的优先级更高
const int &max(const int &a, const int &b)
{
    cout << "no function template" << endl;
    return a < b ? b : a;
}

//函数模板实例化出模板函数
int main(void)
{
    cout << ::max(5, 6) << endl;
    cout << ::max('5', 'a') << endl;

    const char *str1 = "aaa";
    const char *str2 = "abc";
    cout << ::max(str1, str2) << endl;

    cout << ::max(4.5, 5.0, 3.4) << endl;

    cout << ::max('c', 10) << endl;

    //显式调用模板函数——自动推导
    cout << ::max<>(5, 10) << endl;

    //显式指定模板函数
    cout << ::max<int>('a', 10) << endl;

    return 0;
}