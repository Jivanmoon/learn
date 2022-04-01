/**
 * 
 * 成员模板
 */
#include<iostream>
using namespace std;

template <typename T>
class MyClass {
private:
    T value;
public:
    template<typename X>
    void Assign(const MyClass<X>& x) {
        value = x.getValue();
    }
    //由于MyClass<X>和MyClass<T>可能是不同的类型，因此无法直接访问私有成员，需要定义一个可以获取私有成员的方法
    T getValue() const {
        return value;
    }
};

int main(void) {
    MyClass<double> d;
    MyClass<int> i;
    d.Assign(d); //OK
    d.Assign(i); //ERROR d与i类型不同
    return 0;
}
