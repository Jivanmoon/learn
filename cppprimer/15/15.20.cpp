#include <iostream>
#include <string>
class Base
{
public:
    void pub_mem(); // public member
protected:
    int prot_mem; // protected member
private:
    char priv_mem; // private member
};

struct Pub_Derv : public Base
{
    void memfcn(Base &b) { b = *this; }
};
struct Priv_Derv : private Base
{
    void memfcn(Base &b) { b = *this; }
};
struct Prot_Derv : protected Base
{
    void memfcn(Base &b) { b = *this; }
};
struct Derived_from_Public : public Pub_Derv
{
    void memfcn(Base &b) { b = *this; }
};
struct Derived_from_Private : public Priv_Derv
{
    // void memfcn(Base &b) { b = *this; }
};
struct Derived_from_Protected : public Prot_Derv
{
    void memfcn(Base &b) { b = *this; }
};
int main()
{
    Pub_Derv d1;
    Priv_Derv d2;
    Prot_Derv d3;
    Derived_from_Public dd1;
    Derived_from_Protected dd2;
    Derived_from_Private dd3;

    Base *p = &d1; // d1的类型是Pub_Derv，合法
                   // 如果是保护或私有继承，则派生类不能向基类转换
                   //    p = &d2;              // d2的类型是Priv_Derv,非法
                   //    p = &d3;              // d3的类型是Prot_Derv，非法
    p = &dd1;      // dd1的类型是Derived_from_Public，合法
                   //    p = &dd2;             // dd2的类型是Derived_from_Private，非法
                   //    p = &dd3;             // dd3的类型是Derived_from_Protected，非法
    return 0;
}
