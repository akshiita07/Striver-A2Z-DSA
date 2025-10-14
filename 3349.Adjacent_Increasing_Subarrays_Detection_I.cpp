#include <bits/stdc++.h>
using namespace std;

bool isInc(vector<int> &nums, int start, int k)
{
    for (int i = start; i < start + k - 1; i++)
    {
        if (nums[i] >= nums[i + 1])
        {
            return false;
        }
    }
    return true;
}

bool hasIncreasingSubarrays(vector<int> &nums, int k)
{
    int n = nums.size();
    // 2 adjacent k length subarrays strictly increasing
    // return true if possible else false
    if (n < 2 * k)
    {
        // not enough length for 2 subarrays:
        return false;
    }
    for (int i = 0; i + 2 * k <= n; i++)
    {
        if (isInc(nums, i, k) && isInc(nums, i + k, k))
        {
            return true;
        }
    }
    return false;
}

int main()
{

    return 0;
}