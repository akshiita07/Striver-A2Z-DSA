#include <bits/stdc++.h>
using namespace std;

int brute_force(vector<int> &nums)
{
    int n = nums.size();
    int numOfValidSplits = 0;
    // sum of first i + 1 elements >= sum of last n - i - 1 elements.
    // There is at least one element to the right of i : 0 <= i < n - 1
    int leftSum = 0;
    int rightSum = 0;
    for (int i = 0; i < n - 1; i++)
    {
        leftSum += nums[i];
        rightSum = 0;
        for (int j = i + 1; j < n; j++)
        {
            rightSum += nums[j];
        }
        if (leftSum >= rightSum)
        {
            numOfValidSplits++;
        }
    }
    return numOfValidSplits;
}

int waysToSplitArray(vector<int> &nums)
{
    int n = nums.size();
    int numOfValidSplits = 0;
    // sum of first i + 1 elements >= sum of last n - i - 1 elements.
    // There is at least one element to the right of i : 0 <= i < n - 1
    long long totalSum = 0;
    for (auto it : nums)
    {
        totalSum += it;
    }
    long long leftSum = 0;
    for (int i = 0; i < n - 1; i++)
    {
        leftSum += nums[i];
        long long rightSum = totalSum - leftSum;
        if (leftSum >= rightSum)
        {
            numOfValidSplits++;
        }
    }
    return numOfValidSplits;
}

int main()
{
    vector<int> nums = {10, 4, -8, 7};
    cout << "\nBrute: No of valid splits are: " << brute_force(nums);
    cout << "\nNo of valid splits are: " << waysToSplitArray(nums);
    return 0;
}