#include <iostream>
#include <cstring>
 
using namespace std;
 
int main()
{
    char c;
    //分配20个字符的动态数组，因此最多存放19个字符
    char *arr = new char[20];
    int len = 0;
    while(cin.get(c))
    {
        if(isspace(c))//字格符，制表符等空白符
            break;
        arr[len++] = c;//存入动态数组
        if(len == 19)
        {
            cout << "达到数线容量上限" << endl;
            break;
        }
 
    }
    arr[len] = '\0';
    cout <<"len = " << len << " arr=======" << arr << endl;
    //释放动态数组
    delete []arr;
 
    return 0;
}