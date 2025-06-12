#include <bits/stdc++.h>
using namespace std;

int maxAdjacentDistance(vector<int> &nums)
{
    // find max absolute diff between adjacent elements
    // circular array ie 1st and last elements are circular
    int n = nums.size();
    int ans = INT_MIN;
    for (int i = 0; i < n - 1; i++)
    {
        ans = max(ans, abs((nums[i]) - (nums[i + 1])));
    }
    ans = max(ans, abs((nums[0]) - (nums[n - 1])));
    return ans;
}

int main()
{
    vector<int> nums = {1, 2, 4};
    cout << "\nMaximum Adjacent Distance: " << maxAdjacentDistance(nums);

    return 0;
}