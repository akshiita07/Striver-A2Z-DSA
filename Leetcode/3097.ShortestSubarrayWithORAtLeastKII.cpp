#include <bits/stdc++.h>
using namespace std;

int minimumSubarrayLength(vector<int> &nums, int k)
{
    // special array if the bitwise OR of all of its elements is at least k (=k or more)
    // Return the length of the shortest special non-empty subarray of nums, or return -1
    int n = nums.size();
    int cnt[32]{};
    int ans = n + 1;
    for (int i = 0, j = 0, s = 0; j < n; j++)
    {
        s |= nums[j];
        for (int h = 0; h < 32; h++)
        {
            if ((nums[j] >> h & 1) == 1)
            {
                cnt[h]++;
            }
        }
        for (; s >= k && i <= j; i++)
        {
            ans = min(ans, j - i + 1);
            for (int h = 0; h < 32; h++)
            {
                if ((nums[i] >> h & 1) == 1)
                {
                    if (cnt[h]-- == 0)
                    {
                        s ^= 1 << h;
                    }
                }
            }
        }
    }
    if (ans > n)
    {
        return -1;
    }
    return ans;
}

int main()
{
    vector<int> nums = {2, 1, 8};
    int k = 10;
    cout << "\nThe length of min special subarray is: " << minimumSubarrayLength(nums, k);

    return 0;
}