#include <bits/stdc++.h>
using namespace std;

int maxDistinctElements(vector<int> &nums, int k)
{
    // Add an integer in the range [-k, k] to each element of array atmost once
    // Return the maximum possible number of distinct elements in nums after performing the operations.
    sort(nums.begin(), nums.end());
    long long nextFreeElement = INT_MIN;
    int ans = 0;
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        int rangeLow = nums[i] - k;
        int rangeHigh = nums[i] + k;
        if (nextFreeElement < rangeLow)
        {
            nextFreeElement = rangeLow;
        }
        if (nextFreeElement <= rangeHigh)
        {
            nextFreeElement++;
            ans++;
        }
    }
    return ans;
}

int main()
{
    vector<int> nums = ;
    int k = ;

    return 0;
}