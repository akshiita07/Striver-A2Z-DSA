#include <bits/stdc++.h>
using namespace std;

int maximumDifference(vector<int> &nums)
{
    int n = nums.size();
    // find max diff nums[j]-nums[i] st 0 <= i < j < n and nums[i] < nums[j] else return -1
    int maxDiff = -1;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (nums[i] < nums[j])
            {
                maxDiff = max(maxDiff, nums[j] - nums[i]);
            }
        }
    }
    return maxDiff;
}

int main()
{
    vector<int> nums = {7, 1, 5, 4};
    cout << "\nMaximum Difference: " << maximumDifference(nums);

    return 0;
}