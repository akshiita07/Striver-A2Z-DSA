#include <bits/stdc++.h>
using namespace std;

bool canRob(vector<int> &nums, int k, int mid)
{
    int count = 0;
    int n = nums.size();

    for (int i = 0; i < n; i++)
    {
        if (nums[i] <= mid)
        {
            // Rob this house
            count++;
            i++; // Skip the adjacent house
        }
        if (count >= k)
        {
            // Found k houses
            return true;
        }
    }

    return false;
}

int minCapability(vector<int> &nums, int k)
{
    // cannot steal from adjacent houses
    // capability of robber= maxm amount of money stolen from all houses
    // each ith house has nums[i] amount of money
    // atleast k: minimum number of houses the robber will steal from
    int left = *min_element(nums.begin(), nums.end());
    int right = *max_element(nums.begin(), nums.end());
    int ans = right;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (canRob(nums, k, mid))
        {
            ans = mid; // Try for a lower capability
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }

    return ans;
}

int main()
{
    vector<int> nums = {2, 3, 5, 9};
    int k = 2;
    // cout << "\nbrute_force: minimum capability of the robber out of all the possible ways to steal at least k houses= " << brute_force(nums, k);
    cout << "\nminimum capability of the robber out of all the possible ways to steal at least k houses= " << minCapability(nums, k);

    return 0;
}