#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> v1;//默认为空
    vector<int> v2(5);//包含5个0
    vector<int> v3(5, 1);//包含5个1
    vector<int> v4(v3);//和v3一样
    vector<int> v5 = {1, 2, 3, 4};//包含1 2 3 4
    vector<int> v6(v5.begin(), v5.end());//和v5一样
    return 0;
}