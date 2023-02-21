#include<iostream>
#include<thread>
using namespace std;

void proc(int &a) {
    cout << "我是子线程,传入参数为" << a << endl;
    cout << "子线程中显示子线程id为" << this_thread::get_id() << endl;
}

int main() {
    cout << "我是主线程id为" << this_thread::get_id() << endl;
    int a = 9;
    //第一个参数为函数名，第二个参数为该函数的第一个参数，如果该函数接收多个参数就依次写在后面。此时线程开始执行。
    thread th2(proc,ref(a));
    cout << "主线程中显示子线程id为" << th2.get_id() << endl;

    //此处省略多行，不要在创建完线程后马上join,应该在程序结束前join

    //此时主线程被阻塞直至子线程执行结束。
    if(th2.joinable()) th2.join();
    return 0;
}

