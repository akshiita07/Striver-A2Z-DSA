#include <bits/stdc++.h>
using namespace std;

int longestSubarray(vector<int> &nums)
{
    // delete 1 element from nums-> compulsory
    int n = nums.size();
    // return length of longest subarray containing only 1s
    int left = 0;
    int noOfZeroes = 0;
    int ans = INT_MIN;
    for (int right = 0; right < n; right++)
    {
        if (nums[right] == 0)
        {
            noOfZeroes++;
        }
        // we must have atmost 1 zero in the window ie 0 or 1 no of zeroes only else shorten window
        while (noOfZeroes > 1)
        {
            if (nums[left] == 0)
            {
                noOfZeroes--;
            }
            left++;
        }
        ans = max(ans, right - left + 1);
    }
    // since 1 element has to be deleted:
    ans -= 1;
    return ans;
}

int main()
{
    vector<int> nums = {0, 1, 1, 1, 0, 1, 1, 0, 1};
    cout << "\nlength of longest subarray containing only 1s= " << longestSubarray(nums);

    return 0;
}