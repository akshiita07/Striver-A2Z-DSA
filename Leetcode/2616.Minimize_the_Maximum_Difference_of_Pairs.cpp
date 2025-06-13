#include <bits/stdc++.h>
using namespace std;

bool canFormPair(vector<int> &nums, int p, int maxDiff)
{
    int count = 0;
    int n = nums.size();
    for (int i = 1; i < n; i++)
    {
        if (nums[i] - nums[i - 1] <= maxDiff)
        {
            count++;
            i++;
        }
    }
    return count >= p;
}

int minimizeMax(vector<int> &nums, int p)
{
    // Find p pairs of indices of nums st maximum difference amongst all the pairs is minimized
    // no index repetition in pairs
    sort(nums.begin(), nums.end());
    int n = nums.size();
    int low = 0;
    int high = nums[n - 1] - nums[0];
    int ans = 0;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (canFormPair(nums, p, mid))
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return ans;
}

int main()
{
    vector<int> nums = {10, 1, 2, 7, 1, 3};
    int p = 2;
    cout << "\nMinimum Maximum Difference: " << minimizeMax(nums, p);

    return 0;
}