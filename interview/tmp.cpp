#include <iostream>
using namespace std;
void judge_bigend_littleend()
{
    union
    {
        int i;
        char c;
    }un;
    un.i = 1;

    if (un.c == 1)
        printf("小端\n");
    else
        printf("大端\n");
}
int main() {
    judge_bigend_littleend();
    return 0;
}
