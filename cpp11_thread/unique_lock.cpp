#include<iostream>
#include<thread>
#include<chrono>
#include<mutex>
using namespace std;
mutex m;
void proc1(int &a) {
	unique_lock<mutex> g1(m, defer_lock);//初始化了一个没有加锁的mutex
	cout << "xxxxxxxx" << endl;
	g1.lock();//手动加锁，注意，不是m.lock();注意，不是m.lock(),m已经被g1接管了;
	cout << "proc1函数正在改写a" << endl;
	cout << "原始a为" << a << endl;
    a += 2;
	cout << "现在a为" << a << endl;
	g1.unlock();//临时解锁
	cout << "xxxxx" << endl;
	g1.lock();
	cout << "xxxxxx" << endl;
    this_thread::sleep_for(chrono::seconds(5));
}//自动解锁

void proc2(int &a) {
    //尝试加锁一次，但如果没有锁定成功，会立即返回，不会阻塞在那里，且不会再次尝试锁操作。
	unique_lock<mutex> g2(m, try_to_lock);
	if (g2.owns_lock()) {//锁成功
		cout << "proc2函数正在改写a" << endl;
		cout << "原始a为" << a << endl;
        a += 1;
		cout << "现在a为" << a << endl;
	}
	else {//锁失败则执行这段语句
		cout << "proc2函数没有获取到锁" << endl;
	}
}//自动解锁

int main()
{
	int a = 0;
	thread t1(proc1, ref(a));
    this_thread::sleep_for(chrono::seconds(1));
    thread t2(proc2, ref(a));
    t1.join();
	t2.join();
	return 0;
}