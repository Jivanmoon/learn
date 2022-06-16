#include <bits/stdc++.h>
using namespace std;
void func(vector<int> &nums, int idx)
{
    if (idx == nums.size())
        return;
    cout << nums[idx] << endl;
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
    return 0;
}