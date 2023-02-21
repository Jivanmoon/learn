#include<iostream>
#include<thread>
#include<mutex>
using namespace std;
mutex m;

void proc1(int &a) {
    m.lock();
    cout << "proc1函数正在改写a" << endl;
    cout << "原始a为" << a << endl;
    a += 2;
    cout << "现在a为" << a << endl;
    m.unlock();
}

void proc2(int &a) {
    m.lock();
    cout << "proc2函数正在改写a" << endl;
    cout << "原始a为" << a << endl;
    a += 1;
    cout << "现在a为" << a << endl;
    m.unlock();
}

int main() {
    int a = 0;
    thread t1(proc1, ref(a));
    thread t2(proc2, ref(a));
    t1.join();
    t2.join();
    return 0;
}
