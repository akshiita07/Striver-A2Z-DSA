#include <bits/stdc++.h>
using namespace std;

int partitionArray(vector<int> &nums, int k)
{
    // partiton nums array into subarrays such that each element appears exactly once in the subarray
    // diff bw max & min elemenent in each subarray is at most k
    // return minimum number of subsequences
    sort(nums.begin(), nums.end());
    int n = nums.size();
    int ans = 0;
    int i = 0;
    while (i < n)
    {
        int mini = nums[i];
        ans++;
        i++;
        while (i < n && nums[i] - mini <= k)
        {
            // continue adding to subsequence
            i++;
        }
    }
    return ans;
}

int main()
{
    vector<int> nums = {3, 6, 1, 2, 5};
    int k = 2;
    cout << "\nminimum number of subsequences= " << partitionArray(nums, k);

    return 0;
}