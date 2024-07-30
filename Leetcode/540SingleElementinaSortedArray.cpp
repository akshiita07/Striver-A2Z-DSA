#include <bits/stdc++.h>
using namespace std;

int singleNonDuplicate(vector<int> &nums)
{
    int n = nums.size();
    int low = 0;
    int high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1])
        {
            // neither side has same element
            return nums[mid];
        }
        else
        {
            // odd no of digits remaining: search in that half
            if ((mid + 1) % 2 == 0)
            {
                low = mid + 1;
            }
            else if ((high - mid + 1) % 2 == 0)
            {
                high = mid - 1;
            }
        }
    }
    return -1;
}

int main()
{
    vector<int> nums = {3, 3, 7, 7, 10, 11, 11};
    cout << "\nThe no that occurs exactly once in array is: " << singleNonDuplicate(nums);

    return 0;
}