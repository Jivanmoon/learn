#include<functional>
template<typename T>
int compare(const T &t1, const T &t2) {
    if(std::less<T>(t1, t2)) return -1;
    if(std::less<T>(t2, t1)) return 1;
    return 0;
}

//16.3 题目中要求使用Sales_data调用compare函数，但是使用一个自定义的没有实现<运算符的类是一样的效果

class A {

};

int main() {
    A a, b;
    compare(a, b);
    return 0;
}