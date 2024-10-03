#include <bits/stdc++.h>
using namespace std;

int minSubarray(vector<int> &nums, int p)
{
    int totalSum = 0;
    for (int num : nums)
    {
        totalSum = (totalSum + num) % p;
    }

    // If the total sum is already divisible by p, no need to remove any subarray
    if (totalSum == 0)
    {
        return 0;
    }

    // To find the smallest subarray to remove, we use prefix sums and hashing
    unordered_map<int, int> prefixSumRemainder;
    prefixSumRemainder[0] = -1; // To handle cases where the subarray starts from index 0
    int prefixSum = 0, minLength = nums.size();
    for (int i = 0; i < nums.size(); ++i)
    {
        prefixSum = (prefixSum + nums[i]) % p;
        int target = (prefixSum - totalSum + p) % p;

        // If target remainder is found in the map, calculate the subarray length
        if (prefixSumRemainder.find(target) != prefixSumRemainder.end())
        {
            minLength = min(minLength, i - prefixSumRemainder[target]);
        }

        // Update the map with the current prefix sum remainder
        prefixSumRemainder[prefixSum] = i;
    }

    // If the minimum length found is equal to the size of the array, return -1
    return minLength == nums.size() ? -1 : minLength;
}

int main()
{
    vector<int> nums = {3, 1, 4, 2};
    int p = 6;
    cout << "\nLength of smallest sub-array to remove to make sum divisble by 6 is: " << minSubarray(nums, p);
    return 0;
}