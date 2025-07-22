#include <bits/stdc++.h>
using namespace std;

int maximumUniqueSubarray(vector<int> &nums)
{
    // erase a subarray containing unique elements
    // score=sum of elements of this subarray
    // Return the maximum score you can get by erasing exactly one subarray
    unordered_set<int> duplicate;
    int n = nums.size();
    int left = 0;
    int right = 0;
    int maxSum = INT_MIN;
    int currentSum = 0;
    while (right < n)
    {
        // check if already present:
        while (duplicate.find(nums[right]) != duplicate.end())
        {
            // remove & shorten window
            duplicate.erase(nums[left]);
            currentSum -= nums[left];
            left++;
        }
        // add rightmost element:
        duplicate.insert(nums[right]);
        currentSum += nums[right];
        maxSum = max(maxSum, currentSum);
        right++;
    }
    return maxSum;
}

int main()
{
    vector<int> nums = {4, 2, 4, 5, 6};
    cout << "\nmaximum score you can get by erasing exactly one subarray= " << maximumUniqueSubarray(nums);

    return 0;
}