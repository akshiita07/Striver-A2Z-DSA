#include <bits/stdc++.h>
using namespace std;

long long countGood(vector<int> &nums, int k)
{
    // return the number of good subarrays of nums
    // subarray arr is good if there are at least k (k or more) pairs of indices (i, j) such that i < j and arr[i] == arr[j]
    unordered_map<int, int> hashMap;
    long long ans = 0;
    long long countPairs = 0;
    int n = nums.size();
    // 2 pointers:l,r
    int l = 0;
    for (int r = 0; r < n; r++)
    {
        // slide window and add nums[r] to it:
        countPairs += hashMap[nums[r]];
        hashMap[nums[r]]++;
        // shrink window from left while no of pairs>=k
        while (countPairs >= k)
        {
            ans += n - r;
            countPairs -= (hashMap[nums[l]] - 1); // remove l element from window
            hashMap[nums[l]]--;
            l++;
        }
    }
    return ans;
}

int main()
{
    vector<int> nums = {3, 1, 4, 3, 2, 2, 4};
    int k = 2;
    // ie find 2 or more pair of indices (i,j) st i<j and arr[i] == arr[j]
    cout << "\nnumber of good subarrays of nums: " << countGood(nums, k);

    return 0;
}