#include<bits/stdc++.h>
using namespace std;
int main() {
    const char *a = "hello";
    const char *b = "world";
    char c[strlen(a) + strlen(b) + 1];
    strcpy(c, a);
    strcat(c, b);
    cout << c << endl;
    cout << strlen(c) << endl;
    cout << sizeof(c) << endl;
    return 0;
}