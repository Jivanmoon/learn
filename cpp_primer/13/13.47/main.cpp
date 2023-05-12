#include "String.h"
#include <vector>
using namespace std;
void foo(String x) // String x 拷贝构造
{
    std::cout << x.c_str() << std::endl;
}

void bar(const String &x)
{
    std::cout << x.c_str() << std::endl;
}

String baz()
{
    String ret("overfit");
    return ret;
}
int main()
{
    char text[] = "test";
    std::cout << "--------定义---------" << std::endl;
    String s0;
    String s1("train");
    String s2(s0);  //拷贝构造
    String s3 = s1; //拷贝构造
    String s4(text);
    s2 = s1; //拷贝赋值

    std::cout << "--------调用---------" << std::endl;
    foo(s1); // String x 拷贝构造
    bar(s1);
    foo("CNN");        //使用range_initializer
    bar("CNN");        //使用range_initializer
    String s5 = baz(); //使用range_initializer
    std::cout << "--------添加---------" << std::endl;
    std::vector<String> svec;
    svec.reserve(8);
    svec.push_back(s0);
    svec.push_back(s1);
    svec.push_back(s2);
    svec.push_back(s3);
    svec.push_back(s4);
    svec.push_back(s5);
    svec.push_back(baz());      //使用range_initializer + 拷贝构造
    svec.push_back("good fit"); //使用range_initializer + 拷贝构造
    std::cout << "--------输出---------" << std::endl;
    for (const auto &s : svec)
    {
        std::cout << s.c_str() << std::endl;
    }
    return 0;
}