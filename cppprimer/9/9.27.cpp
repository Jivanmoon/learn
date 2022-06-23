#include<bits/stdc++.h>
using namespace std;

int main() {
    forward_list<int> flst = {1,2,3,4,5,6};
    auto prev = flst.before_begin();
    auto cur = flst.begin();
    while(cur != flst.end()) {
        if(*cur % 2) {
            cur = flst.erase_after(prev);
        }
        else {
            prev = cur;
            ++cur;
        }
    }
    for(const auto &t : flst) {
        cout << t << " ";
    }
    cout << endl;
    return 0;
}