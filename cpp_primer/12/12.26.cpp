#include<bits/stdc++.h>
using namespace std;

int main() {
    int n = 10;
    allocator<string> as;
    auto const p = as.allocate(n);
    auto *q = p;
    string s;
    while(cin >> s && q != p + n) {
        as.construct(q++, s);
    }
    
    const size_t size = q - p;
    for (size_t i = 0; i < size; i++)
		cout << p[i] << endl;
    
    while(q != p) {
        as.destroy(--q);
    }
    as.deallocate(p, n);
    return 0;
}