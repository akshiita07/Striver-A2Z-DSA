#include <bits/stdc++.h>
using namespace std;

long long countInterestingSubarrays(vector<int> &nums, int modulo, int k)
{
    // find the count of subarrays that are interesting
    // subarray nums[l_ _r] is interesting if : cnt =no. of indices i in the range [l, r] such that nums[i] % modulo == k. Then, cnt % modulo == k
    unordered_map<int, long long> hashMap;
    hashMap[0] = 1; // count=0
    int n = nums.size();
    int count = 0;
    long long ans = 0;

    for (int i = 0; i < n; i++)
    {
        if (nums[i] % modulo == k)
        {
            count++;
        }
        int modCount = count % modulo;
        int target = (modCount - k + modulo) % modulo; // cnt of subarrays with modCount = target
        ans += hashMap[target];
        hashMap[modCount]++;
    }
    return ans;
}

int main()
{
    vector<int> nums = {3, 2, 4};
    int modulo = 2;
    int k = 1;
    cout << "\nCount of Interesting Subarrays: " << countInterestingSubarrays(nums, modulo, k);

    return 0;
}