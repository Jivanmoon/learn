#include<iostream>
using namespace std;
int main() {
    int v1 = 0, v2 = 0;
    cout << "输入两个整数：" << endl;
    cin >> v1 >> v2;
    while(v1 <= v2) {
        cout << v1 << endl;
        ++v1;
    }
    return 0;
}