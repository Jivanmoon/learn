//生产者消费者模型

#include<iostream>
#include<thread>
#include<mutex>
#include<condition_variable>
#include<queue>
using namespace std;

queue<int> q;
const int MAX_QUEUE_LEN = 10;

mutex m;
condition_variable consumer_cond;
condition_variable producer_cond;

int num = 1;

void consumer() {
    while(true) {
        unique_lock<mutex> lock(m);
        auto m_id = this_thread::get_id();
        cout << "消费者线程：" << m_id << "获取到互斥锁" << endl;
        while(q.empty()) {
            cout << "当前队列为空，消费者线程：" << m_id << "需要阻塞等待" << endl;
            consumer_cond.wait(lock);
            cout << "当前队列不为空，消费者线程" << m_id << "，阻塞结束" << endl;
        }
        auto t = q.front();
        q.pop();
        producer_cond.notify_one();
        cout << "消费者线程：" << m_id << "获取到队列中的：" << t << endl;
    }
}

void producer() {
    while(true) {
        unique_lock<mutex> lock(m);
        auto m_id = this_thread::get_id();
        cout << "生产者线程" << m_id << "获取到互斥锁" << endl;
        while(q.size() == MAX_QUEUE_LEN) {
            cout << "当前队列满了，生产者进程：" << m_id << "需要阻塞等待" << endl;
            producer_cond.wait(lock);
            cout << "当前队列还有空位，生产者线程" << m_id << "，阻塞结束" << endl;
        }
        q.push(num++);
        consumer_cond.notify_one();
        cout << "生产者线程：" << m_id << "插入到队列中的：" << num - 1 << endl;
    }
}

void func(int cnum, int pnum) {
    vector<thread> ct;
    for(int i = 0; i < cnum; ++i) {
        ct.push_back(thread(consumer));
    }

    vector<thread> pt;
    for(int i = 0; i < pnum; ++i) {
        pt.push_back(thread(producer));
    }

    for(auto &t : ct) {
        if(t.joinable()) t.join();
    }
    
    for(auto &t : pt) {
        if(t.joinable()) t.join();
    }

}

int main() {
    func(5, 5);
    return 0;
}
