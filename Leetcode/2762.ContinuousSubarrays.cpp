#include <bits/stdc++.h>
using namespace std;
/*
long long continuousSubarrays(vector<int> &nums)
{
    int n = nums.size();
    long long ans = 0;
    int left = 0;
    int minEle = nums[0];
    int maxEle = nums[0];
    for (int right = 0; right < n; right++)
    {
        minEle = min(minEle, nums[right]);
        maxEle = max(maxEle, nums[right]);
        // condition: |nums[i1] - nums[i2]| <= 2
        while (maxEle - minEle > 2)
        {
            // reduce window
            left++;
            // recompute min & max
            minEle = *min_element(nums.begin() + left, nums.begin() + right - 1);
            maxEle = *max_element(nums.begin() + left, nums.begin() + right - 1);
        }
        ans += (right - left + 1);
    }
    return ans;
}
*/

long long continuousSubarrays(vector<int> &nums)
{
    int n = nums.size();
    long long ans = 0;
    int left = 0;
    // to track min & max elem:
    multiset<int> window;
    for (int right = 0; right < n; right++)
    {
        // Add current element to the window
        window.insert(nums[right]);
        // condition: |nums[i1] - nums[i2]| <= 2
        while (*window.rbegin() - *window.begin() > 2)
        {
            window.erase(window.find(nums[left]));
            left++;
        }
        ans += (right - left + 1);
    }
    return ans;
}

int main()
{
    vector<int> nums = {5, 4, 2, 4};
    cout << "\nNo of cts subarrays are: " << continuousSubarrays(nums);

    return 0;
}