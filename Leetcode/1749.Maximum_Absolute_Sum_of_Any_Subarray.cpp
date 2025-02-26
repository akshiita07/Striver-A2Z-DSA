#include <bits/stdc++.h>
using namespace std;

int maxAbsoluteSum(vector<int> &nums)
{
    int n = nums.size();
    int maxSum = nums[0];
    int minSum = nums[0];
    int currMax = nums[0];
    int currMin = nums[0];
    for (int i = 1; i < n; i++)
    {
        // Max Kadane:
        currMax = max(nums[i], currMax + nums[i]);
        maxSum = max(currMax, maxSum);
        // Min Kadane:
        currMin = min(nums[i], currMin + nums[i]);
        minSum = min(currMin, minSum);
    }
    return max(abs(maxSum), abs(minSum));
}

int main()
{
    vector<int> nums = {2, -5, 1, -4, 3, -2};
    cout << "\nMax abs sum= " << maxAbsoluteSum(nums);

    return 0;
}