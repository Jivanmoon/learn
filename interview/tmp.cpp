#include <iostream>
using namespace std;

int main() {
    int *p = nullptr;
    *p = 0; // 给空指针指向的地址赋值，引发core dump
    return 0;
}
