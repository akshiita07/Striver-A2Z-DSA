#include <bits/stdc++.h>
using namespace std;

int findMin(vector<int> &nums)
{
    int minEle = INT_MAX;
    int ele;
    int n = nums.size();
    int low = 0;
    int high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        // check if lhs is sorted
        if (nums[low] <= nums[mid])
        {
            // left half is sorted
            // right half is NOT sorted

            // take min elem from left half
            ele = nums[low]; // because sorted
            minEle = min(ele, minEle);
            low = mid + 1;
        }
        // check if rhs is sorted
        else
        {
            // right is sorted
            // find min from sorted half
            ele = nums[mid];
            minEle = min(ele, minEle);

            high = mid - 1;
        }
    }
    return minEle;
}

int main()
{
    vector<int> nums = {3, 4, 5, 1, 2}; // op: 1
    cout << "\nThe min element is: " << findMin(nums);

    return 0;
}