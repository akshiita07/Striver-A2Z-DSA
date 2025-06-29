#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
int numSubseq(vector<int> &nums, int target)
{
    // return no of subsequences of nums st minimum+maximum element<=target
    int ans = 0;
    int n = nums.size();
    // sort array:
    sort(nums.begin(), nums.end());
    // find powers:
    vector<int> power(n + 1, 1);
    for (int i = 1; i <= n; i++)
    {
        power[i] = (power[i - 1] * 2LL) % mod;
    }
    // 2 pointer approach:
    int i = 0;
    int j = n - 1;
    while (i <= j)
    {
        if (nums[i] + nums[j] <= target)
        {
            // find all possible subsequeneces within:
            ans = (ans + power[j - i]) % mod;
            // move left pointer:
            i++;
        }
        else
        {
            // shift right pointer
            j--;
        }
    }
    return ans % mod;
}

int main()
{
    vector<int> nums = {3, 3, 6, 8};
    int target = 10;
    cout << "\nNumber of Subsequences: " << numSubseq(nums, target);

    return 0;
}