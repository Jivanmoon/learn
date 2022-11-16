#include<iostream>
using namespace std;
class A { 
    static int a; 
    void Fun();
};
int main(){
  cout<<sizeof(A)<<endl;// 输出 1;
  A a; 
  cout<<sizeof(a)<<endl;// 输出 1;
  return 0;
}