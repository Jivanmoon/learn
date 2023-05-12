#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main() {
    vector<int> v;
    int i;
    while(cin >> i) {
        v.push_back(i);
    }
    for(auto it = v.cbegin(); it != v.cend(); it += 2) {
        int sum = *it;
        if(it + 1 != v.cend()) sum += *(it + 1);
        cout << sum << " ";
    }
    cout << endl;
    auto itl = v.cbegin(), itr = v.cend() - 1;
    while(itl <= itr) {
        int sum = *itl + *itr;
        if(itl == itr) sum /= 2;
        ++itl, --itr;
        cout << sum << " ";
    }
    cout << endl;
    return 0;
}