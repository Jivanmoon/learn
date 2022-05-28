#include<iostream>
using namespace std;
int main() {
    int v1 = 0, v2 = 0;
    cout << "输入两个整数：" << endl;
    cin >> v1 >> v2;
    for(int i = v1; i <= v2; ++i) {
        cout << i << endl;
    }
    return 0;
}