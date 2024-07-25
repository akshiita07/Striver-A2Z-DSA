#include <bits/stdc++.h>
using namespace std;

void searchRange(vector<int> &nums, int target)
{
    vector<int> ans(2, -1); // initialise with -1
    int n = nums.size();
    int lowBound = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
    int upperBound = upper_bound(nums.begin(), nums.end(), target) - nums.begin();
    if (nums[lowBound] != target || lowBound == n)
    {
        ans[0] = -1;
        ans[1] = -1;
    }
    ans[0] = lowBound;
    upperBound = upperBound - 1;
    ans[1] = upperBound;

    cout << target << " Starting index: " << ans[0] << " & ending index: " << ans[1] << endl;
}

void searchRange2(vector<int> &nums, int target)
{
    vector<int> ans(2, -1); // initialise with -1
    int n = nums.size();
    int low = 0;
    int high = n - 1;
    // for first index keep looking in left
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (nums[mid] == target)
        {
            ans[0] = mid;
            // keep looking on left for 1st occ
            high = mid - 1;
        }
        else if (nums[mid] > target)
        {

            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    // last occ
    low = 0;
    high = n - 1;
    // for last index keep looking in right
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (nums[mid] == target)
        {
            ans[1] = mid;
            // keep looking on left for 1st occ
            low = mid + 1;
        }
        else if (nums[mid] > target)
        {

            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    cout << target << " Starting index: " << ans[0] << " & ending index: " << ans[1] << endl;
}

int main()
{
    vector<int> nums = {5, 7, 7, 8, 8, 10};
    int target = 8;
    // searchRange(nums, target);
    searchRange2(nums, target);

    return 0;
}