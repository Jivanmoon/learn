#include<iostream>
#include<thread>
#include<mutex>
using namespace std;
mutex m;

void proc1(int &a) {
    lock_guard<mutex> g1(m);//用此语句替换了m.lock()；lock_guard传入一个参数时，该参数为互斥量，此时调用了lock_guard的构造函数，申请锁定m
    cout << "proc1函数正在改写a" << endl;
    cout << "原始a为" << a << endl;
    a += 2;
    cout << "现在a为" << a << endl;
}

void proc2(int &a) {
    {
        //手动锁定
        m.lock();
        //adopt_lock标识表示构造函数中不再进行互斥量锁定，因为此时需要提前手动锁定。
        lock_guard<mutex> g2(m, adopt_lock);
        cout << "proc2函数正在改写a" << endl;
        cout << "原始a为" << a << endl;
        a += 1;
        cout << "现在a为" << a << endl;
    }//通过使用{}来调整作用域范围，可使得m在合适的地方被解锁
    cout << "作用域外的内容3" << endl;
    cout << "作用域外的内容4" << endl;
    cout << "作用域外的内容5" << endl;
}
int main() {
    int a = 0;
    thread t1(proc1, ref(a));
    thread t2(proc2, ref(a));
    t1.join();
    t2.join();
    return 0;
}