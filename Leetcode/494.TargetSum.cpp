#include <bits/stdc++.h>
using namespace std;

void recursiveBacktracking(vector<int> &nums, int target, int index, int sum, int &ans)
{
    // base case:when all numbers done:
    if (index == nums.size())
    {
        if (sum == target)
        {
            ans++;
        }
        return;
    }
    // backtrack while adding:
    recursiveBacktracking(nums, target, index + 1, sum + nums[index], ans);
    // backtrack while subtracting:
    recursiveBacktracking(nums, target, index + 1, sum - nums[index], ans);
}

int findTargetSumWays(vector<int> &nums, int target)
{
    int ans = 0;
    recursiveBacktracking(nums, target, 0, 0, ans);
    return ans;
}

int main()
{
    vector<int> nums = {1, 1, 1, 1, 1};
    int target = 3;
    cout << "\nNo of ways to get target: " << findTargetSumWays(nums, target);

    return 0;
}