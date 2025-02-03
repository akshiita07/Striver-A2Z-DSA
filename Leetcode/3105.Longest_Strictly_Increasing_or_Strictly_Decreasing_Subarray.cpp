#include <bits/stdc++.h>
using namespace std;

int longestMonotonicSubarray(vector<int> &nums)
{
    // Return length of longest subarray ie either strictly increasing or strictly decreasing
    int increasing = 1;
    int decreasing = 1;
    int n = nums.size();
    if (n == 0)
    {
        return 0; // no subarray
    }
    int ans = 1;

    for (int i = 0; i < n - 1; i++)
    {
        // check inc :
        if (nums[i] < nums[i + 1])
        {
            increasing++;
            decreasing = 1;
        }
        else if (nums[i] > nums[i + 1])
        {
            decreasing++;
            increasing = 1;
        }
        else
        {
            // restart:
            increasing = 1;
            decreasing = 1;
        }
        ans = max({ans, increasing, decreasing});
    }
    return ans;
}

int main()
{
    // vector<int> nums = {1, 4, 3, 3, 2};      // 2
    vector<int> nums = {1, 4, 3, 4, 5}; // 3
    cout << "\nLength of longest subarray= " << longestMonotonicSubarray(nums);

    return 0;
}