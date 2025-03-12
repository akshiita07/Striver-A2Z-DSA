#include <bits/stdc++.h>
using namespace std;

int maximumCount(vector<int> &nums)
{
    // array is sorted
    // 0 is neither + nor -
    // count no of + nos & no of -ve nos
    // return max of this count
    // use binary search
    int n = nums.size();
    int low = 0;
    int high = n - 1;
    // find position of first negative number:
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (nums[mid] >= 0)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    int countNegative = low;

    // find position of first positive number:
    // reset:
    low = 0;
    high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (nums[mid] <= 0)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    int countPositive = n - low;
    return max(countPositive, countNegative);
}

int main()
{
    vector<int> nums = {-3, -2, -1, 0, 0, 1, 2};
    cout << "\nMax count= " << maximumCount(nums) << endl;
    return 0;
}