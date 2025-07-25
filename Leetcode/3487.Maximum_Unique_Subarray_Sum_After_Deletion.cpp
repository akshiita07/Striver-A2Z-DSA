#include <bits/stdc++.h>
using namespace std;

int maxSum(vector<int> &nums)
{
    // maximise sumof subarray & must have only unique elements by dleteing any no of elements in array & not making it empty
    int n = nums.size();
    unordered_map<int, int> hashMap;
    int maxVal = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (nums[i] > 0)
        {
            // adding only + elements
            hashMap[nums[i]]++;
        }
        if (nums[i] > maxVal)
        {
            maxVal = nums[i];
        }
    }
    int sum = 0;
    if (hashMap.empty())
    {
        // ie only -ve or 0 values are present
        sum = maxVal;
    }

    for (auto it : hashMap)
    {
        // add only unique
        sum += it.first;
    }
    return sum;
}

int main()
{
    vector<int> nums = {1, 2, -1, -2, 1, 0, -1};
    cout << "\nMaximum Unique Subarray Sum After Deletion: " << maxSum(nums);

    return 0;
}