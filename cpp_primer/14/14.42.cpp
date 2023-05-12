#include <bits/stdc++.h>
using namespace std;
using namespace std::placeholders;

int main()
{
    vector<int> vi{1024, 1025, 1321, 4324, 11, 321};
    int cnt = count_if(vi.begin(), vi.end(), bind(greater<int>(), _1, 1024));
    cout << cnt << endl;
    vector<string> vs{"pooh", "pooh", "pooo"};
    auto idx = find_if(vs.begin(), vs.end(), bind(not_equal_to<string>(), _1, "pooh"));
    cout << *idx << endl;
    transform(vi.begin(), vi.end(), vi.begin(), bind(multiplies<int>(), _1, 2));
    for (auto &t : vi)
    {
        cout << t << " ";
    }
    cout << endl;

    // 14.43
    vi = {4, 6, 8, 9};
    int num = 2;
    auto ret = any_of(vi.begin(), vi.end(), bind(modulus<int>(), _1, 2));
    cout << (ret == true ? "No" : "Yes") << endl;
}