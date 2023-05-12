#include<iostream>
using namespace std;

int main() {
    int sum = 0, tmp = 0;
    while(cin >> tmp) {
        sum += tmp;
    }
    cout << sum << endl;
    return 0;
}