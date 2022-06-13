#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a, b;
    cin>>a>>b;
    if(b == 0) 
        throw runtime_error("除数不能为0");
    cout<<a/b<<endl;
    return 0;
}