#include <bits/stdc++.h>
using namespace std;

// sliding window approach:
long long countSubarrays(vector<int> &nums, int minK, int maxK)
{
    // fixed bound subarray of nums: min value of subarray==minK & max value of subarray==maxK
    // Return the number of fixed-bound subarrays
    // divide array into subarrays such that numbers lie between minK and maxK INCLUSIVE
    long long ans = 0;
    int n = nums.size();
    int lastMin = -1;
    int lastMax = -1;
    int lastInvalid = -1;

    for (int i = 0; i < n; i++)
    {
        if (nums[i] < minK || nums[i] > maxK)
        {
            // invalid:
            lastInvalid = i;
        }
        if (nums[i] == minK)
        {
            lastMin = i;
        }
        if (nums[i] == maxK)
        {
            lastMax = i;
        }
        int start = min(lastMin, lastMax);
        if (start > lastInvalid)
        {
            // valid subarray:
            ans += start - lastInvalid;
        }
    }

    return ans;
}

int main()
{
    vector<int> nums = {1, 3, 5, 2, 7, 5};
    int minK = 1;
    int maxK = 5;
    cout << "\nThe count of fixed-bound subarrays is: " << countSubarrays(nums, minK, maxK);

    return 0;
}