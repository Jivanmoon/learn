/**
 * 
 * typename的作用
 * 
 */
#include<iostream>
using namespace std;

template <typename T>
class MyClass {
private:
    //此时会认为SubType是T类型中的一个静态数据成员，而*被当成乘号
    //T::SubType *prt_;
    typename T::SubType *prt_;
};

class Test {
public:
    typedef int SubType;
};

int main(void) {
    MyClass<Test> mc;
    return 0;
}