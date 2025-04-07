#include <bits/stdc++.h>
using namespace std;

bool recursiveBrute(vector<int> &nums, int index, int target_sum)
{
    int n = nums.size();
    if (target_sum == 0)
    {
        // can always make 0 sum
        return true;
    }
    if (index >= n || target_sum < 0)
    {
        // if we have traversed all elements or target_sum is negative
        return false;
    }
    bool include_current = recursiveBrute(nums, index + 1, target_sum - nums[index]);
    bool exclude_current = recursiveBrute(nums, index + 1, target_sum);
    return include_current || exclude_current;
}

bool brute_force(vector<int> &nums)
{
    // true: partition array into 2 subsets st sum of elements in both subsets is EQUAL else false
    int n = nums.size();
    // true if sum of both subsets = total_sum_of_all_array_elements/2
    int total_sum = accumulate(nums.begin(), nums.end(), 0);
    // if total sum is odd then there cannot be 2 subsets of equal size so return false
    if (total_sum % 2 != 0)
    {
        return false;
    }
    int target_sum = total_sum / 2;
    return recursiveBrute(nums, 0, target_sum);
}

bool canPartition(vector<int> &nums)
{
    // true: partition array into 2 subsets st sum of elements in both subsets is EQUAL else false
    int n = nums.size();
    // true if sum of both subsets = total_sum_of_all_array_elements/2
    int total_sum = accumulate(nums.begin(), nums.end(), 0);
    // if total sum is odd then there cannot be 2 subsets of equal size so return false
    if (total_sum % 2 != 0)
    {
        return false;
    }
    int target_sum = total_sum / 2;
    // check if target_sum is possible or not from given elements:
    vector<bool> dp(target_sum + 1, false);
    dp[0] = true; // 0 sum is always possible
    for (auto it : nums)
    {
        // traverse backwards:
        for (int i = target_sum; i >= it; i--)
        {
            // check if target_sum is possible or not:
            if (dp[i - it])
            {
                dp[i] = true;
            }
        }
    }
    return dp[target_sum];
}

int main()
{
    vector<int> nums = {1, 5, 11, 5};
    cout << "\nbrute_force:Partition= " << brute_force(nums);
    cout << "\nPartition= " << canPartition(nums);
    return 0;
}