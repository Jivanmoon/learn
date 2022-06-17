#include <bits/stdc++.h>
using namespace std;
void func(vector<int> &nums, int idx)
{
    #ifndef NDEBUG
        cout << nums.size() << endl;
    #endif
    if (idx == nums.size())
        return;
    cout << nums[idx] << " ";
    func(nums, idx + 1);
}

int main()
{
    vector<int> iv = {1,
                      2,
                      3,
                      4,
                      6};
    func(iv, 0);
    cout << endl;
    return 0;
}