#include <bits/stdc++.h>
using namespace std;

vector<int> getMaximumXor(vector<int> &nums, int maximumBit)
{
    int n = nums.size();
    int k = (1 << maximumBit) - 1; // 2^maximumBit - 1
    vector<int> ans(n);

    int xorAll = 0;
    for (int i = 0; i < n; i++)
    {
        xorAll ^= nums[i];
    }

    for (int i = 0; i < n; i++)
    {
        ans[i] = xorAll ^ k;
        xorAll ^= nums[n - i - 1]; // Remove last element for the next query
    }

    return ans;
}

int main()
{
    vector<int> nums = {0, 1, 1, 3};
    int maximumBit = 2;
    vector<int> ans = getMaximumXor(nums, maximumBit);
    cout << "Ans:\n";
    for (auto it : ans)
    {
        cout << it << " ";
    }
    return 0;
}