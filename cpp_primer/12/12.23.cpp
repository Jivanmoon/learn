#include <iostream>
#include <cstring>
 
using std::cout;
using std::endl;
using std::string;
 
int main()
{
    const char *c1 = "Hello ";
    const char *c2 = "World";
    //字符串所需空间=字符数+1
    char *r = new char[strlen(c1) + strlen(c2) + 1];
    strcpy(r, c1);//拷贝第一个字符串常量
    strcat(r, c2);//连接第二个字符串常量
    cout << "r=====" << r << endl;
 
    string s1 = "hello ";
    string s2 = "world";
    strcpy(r, (s1 + s2).c_str());
    cout << "r=====" << r << endl;
    //释放动态数组
    delete []r;
    return 0;
}