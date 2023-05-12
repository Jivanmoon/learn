#include <bits/stdc++.h>
using namespace std;
void func1(int **x, int **y)
{
    int *tmp = *x;
    *x = *y;
    *y = tmp;
}

void func2(int *&x, int *&y) {
    int *tmp = x;
    x = y;
    y = tmp;
}

int main()
{
    int a = 1, b = 2;
    int *pa = &a, *pb = &b;
    //func1(&pa, &pb);
    func2(pa, pb);
    cout << *pa << endl;
    cout << *pb << endl;
}