#include<bits/stdc++.h>
using namespace std;

void elimDups(list<int> &words) {
    words.sort();
    words.unique();
}

int main() {
    list<int> li = {1,2,3,4,5,3,2,1};
    elimDups(li);
    for_each(li.cbegin(), li.cend(), 
        [](const int &x) {
            cout << x << " ";
        }
    );
    cout << endl;
    return 0;
}