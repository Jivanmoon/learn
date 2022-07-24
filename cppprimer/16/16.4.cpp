#include <bits/stdc++.h>
using namespace std;

template <typename T, typename U>
T find(T begin, T end, const U &target) {
    for (; begin != end && *begin != target; ++begin) {}
    return begin;
}

int main() {
    vector<int> vi{3, 4, 5, 6, 43, 21, 432};
    list<string> ls{
        "hello",
        "world",
        "find"
    };
    auto i = ::find(vi.begin(), vi.end(), 5);
    *i = 10;
    string s = "find";
    auto j = ::find(ls.begin(), ls.end(), s);
    *j = "name";
    for_each(vi.begin(), vi.end(), [](const auto &t){cout << t << endl;});
    for_each(ls.begin(), ls.end(), [](const auto &t){cout << t << endl;});
}   
