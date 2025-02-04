#include <bits/stdc++.h>
using namespace std;

int maxAscendingSum(vector<int> &nums)
{
    // return the maximum possible sum of an ascending subarray in nums
    int n = nums.size();
    int currentSum = nums[0];
    int maxSum = INT_MIN;

    for (int i = 1; i < n; i++)
    {
        if (nums[i] > nums[i - 1])
        {
            currentSum += nums[i];
        }
        else
        {
            maxSum = max(maxSum, currentSum);
            currentSum = nums[i]; // restart
        }
        cout << "\nCurr sum= " << currentSum;
        cout << "\nMax sum= " << maxSum;
    }
    maxSum = max(maxSum, currentSum); // for last subarray
    return maxSum;
}

int main()
{
    vector<int> nums = {12, 17, 15, 13, 10, 11, 12}; // 33
    cout << "\nMaximum possible sum of an ascending subarray= " << maxAscendingSum(nums);

    return 0;
}