#include <bits/stdc++.h>
using namespace std;

// BRUTE FORCE: TIME-O(n)
int brute_force(vector<int> &nums)
{
    int n = nums.size();
    // if only 1 element present in array:
    if (n == 1)
    {
        return nums[0];
    }
    for (int i = 0; i < n; i++)
    {
        // first element
        if (i == 0)
        {
            if (nums[i] != nums[i + 1])
            {
                return nums[i];
            }
        }
        // last element
        else if (i == (n - 1))
        {
            if (nums[i] != nums[i - 1])
            {
                return nums[i];
            }
        }
        // any other element
        else
        {
            if (nums[i] != nums[i - 1] && nums[i] != nums[i + 1])
            {
                // neithe on side is same
                return nums[i];
            }
        }
    }
}

// BINARY SEARCH: TIME-O(logn)
int singleNonDuplicate(vector<int> &nums)
{
    int n = nums.size();
    // if only 1 element present in array:
    if (n == 1)
    {
        return nums[0];
    }
    // check for first element
    if (nums[0] != nums[1])
    {
        return nums[0];
    }
    // check for last element
    if (nums[n-1] != nums[n - 2])
    {
        return nums[n-1];
    }
    int low = 1;        //from second elemnt
    int high = n - 2;   //from second last element
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
            // if mid is at odd index & its prev elem is same
            // if mid is at even index & its next elem is same
            if((mid%2!=0 && nums[mid]==nums[mid-1]) || (mid%2==0 && nums[mid]==nums[mid+1])){
                // presnt at prev index
                // eliminate left half
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
    }
    return -1;
}

int main()
{
    vector<int> nums = {3, 3, 7, 7, 10, 11, 11};
    // cout << "\nBRUTE FORCE: The no that occurs exactly once in array is: " << brute_force(nums);
    cout << "\nThe no that occurs exactly once in array is: " << singleNonDuplicate(nums);

    return 0;
}