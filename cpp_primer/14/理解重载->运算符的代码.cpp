#include <iostream>
using namespace std;

class A
{
public:
    void action()
    {
        cout << "Action in class A!" << endl;
    }
};

class B
{
    A a;

public:
    A *operator->()
    {
        return &a;
    }
    void action()
    {
        cout << "Action in class B!" << endl;
    }
};

class C
{
    B b;

public:
    B operator->()
    {
        return b;
    }
    void action()
    {
        cout << "Action in class C!" << endl;
    }
};

int main(int argc, char *argv[])
{
    C *pc = new C;
    pc->action();

    
    C c;
    c->action();
    getchar();
    return 0;
}