#include "Thread.h"
#include <iostream>
#include <unistd.h>
using namespace std;

class TestThread : public Thread
{
public:
    TestThread(int count) : count_(count)
    {
        cout <<"TestThread..."<<endl;
    }
    ~TestThread()
    {
        cout <<"~TestThread..."<<endl;
    }
private:
    void run()
    {
        while(count_--)
        {
            cout<<"this is a test..."<<endl;
            sleep(1);
        }
    }
    int count_;
};
int main(void)
{
    /*
    TestThread t(5);
    t.Start();
    t.Join();
    */
   TestThread* t = new TestThread(5);
   t->SetAutoDelete(true);
   t->Start();
   t->Join();
    return 0;
}