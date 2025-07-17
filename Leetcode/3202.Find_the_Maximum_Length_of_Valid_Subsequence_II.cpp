#include <bits/stdc++.h>
using namespace std;

int maximumLength(vector<int> &nums, int k)
{
    // valid subsequence sub if (sub[0] + sub[1]) % k == (sub[1] + sub[2]) % k == ... == (sub[x - 2] + sub[x - 1]) % k
    int n = nums.size();
    int maxLength = INT_MIN;
    for (int i = 0; i < k; i++)
    {
        vector<int> dp(k, 0);
        for (int j = 0; j < n; j++)
        {
            int mod = nums[j] % k;
            int prevMod = (i - mod + k) % k;
            dp[mod] = max(dp[mod], dp[prevMod] + 1);
            maxLength = max(maxLength, dp[mod]);
        }
    }
    return maxLength;
}

int main()
{
    vector<int> nums = {1, 4, 2, 3, 1, 4};
    int k = 3;
    cout << "\nMaximum length of valid subsequence: " << maximumLength(nums, k);

    return 0;
}