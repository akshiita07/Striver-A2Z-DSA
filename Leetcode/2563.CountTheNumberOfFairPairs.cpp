#include <bits/stdc++.h>
using namespace std;

long long brute_force(vector<int> &nums, int lower, int upper)
{
    int n = nums.size();
    long long cnt = 0;
    // A pair (i, j) is fair if: 0 <= i < j < n, and lower <= nums[i] + nums[j] <= upper
    // return no of fair pairs
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i < j && (nums[i] + nums[j] >= lower) && (nums[i] + nums[j] <= upper))
            {
                cnt++;
            }
        }
    }
    return cnt;
}

long long countFairPairs(vector<int> &nums, int lower, int upper)
{
    int n = nums.size(); // 6
    long long cnt = 0;
    // A pair (i, j) is fair if: 0 <= i < j < n, and lower <= nums[i] + nums[j] <= upper
    // return no of fair pairs
    sort(nums.begin(), nums.end());
    // {0, 1, 4, 4, 5, 7}
    for (int i = 0; i < n; i++)
    {
        // find fist element >=
        auto j = lower_bound(nums.begin() + i + 1, nums.end(), lower - nums[i]);
        auto k = lower_bound(nums.begin() + i + 1, nums.end(), upper - nums[i] + 1);
        cnt = cnt + (k - j);
    }
    return cnt;
}

int main()
{
    vector<int> nums = {0, 1, 7, 4, 4, 5};
    int lower = 3;
    int upper = 6;
    cout << "\nThe no of fair pairs are: " << countFairPairs(nums, lower, upper);

    return 0;
}