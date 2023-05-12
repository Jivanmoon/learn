#include <bits/stdc++.h>
using namespace std;

int main()
{
    unordered_map<char, function<int(int, int)>> mp;
    mp['+'] = plus<int>();
    mp['-'] = minus<int>();
    mp['\\'] = divides<int>();
    mp['*'] = multiplies<int>();
    mp['%'] = modulus<int>();
    while (std::cout << "请输入为: 数字 操作符 数字 :\n", true)
    {
        int lhs, rhs;
        char op;
        std::cin >> lhs >> op >> rhs;
        std::cout << mp[op](lhs, rhs) << std::endl;
    }
    return 0;
}