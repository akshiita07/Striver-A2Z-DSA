#include <bits/stdc++.h>
using namespace std;

int maximumBeauty(vector<int> &nums, int k)
{
    // Choose index i that hasn't been chosen before from the range [0, nums.length - 1].
    // Replace nums[i] with any integer from the range [nums[i] - k, nums[i] + k].
    //  beauty of the array=length of the longest subsequence consisting of equal elements.

    // Return maximum possible beauty of the array nums after applying the operation any number of times.
    // Sort the array.
    // find maximum subarray A[i … j] such that A[j] - A[i] ≤ 2 * k.
    int n = nums.size();
    sort(nums.begin(), nums.end());
    int start = 0;
    int ans = 0;
    for (int end = 0; end < n; end++)
    {
        while (nums[end] - nums[start] > 2 * k)
        {
            start++;
        }
        ans = max(ans, end - start + 1);
    }
    return ans;
}

int main()
{
    vector<int> nums = {4, 6, 1, 2};
    int k = 2;
    cout << "\nLength of beauty array is: " << maximumBeauty(nums, k);
    return 0;
}