#include <bits/stdc++.h>
using namespace std;
// BINARY SEARCH
// TIME: O(logn)->HEIGHT OF TREE

int search_iterative(vector<int> &nums, int target)
{
    int low = 0;
    int n = nums.size();
    int high = n - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (nums[mid] == target)
        {
            return mid; // ans is returned
        }
        else if (nums[mid] > target)
        {
            // move to left
            high = mid - 1;
        }
        else if (nums[mid] < target)
        {
            // move to right
            low = mid + 1;
        }
    }
    return -1; // when low>high
}

int search_recursive(vector<int> &nums, int target, int low, int high)
{
    if (low > high) //base case when search space is exhausted
    {
        return -1;
    }
    // else
    int mid = (low + high) / 2;
    if (nums[mid] == target)
    {
        return mid; // ans is returned
    }
    else if (nums[mid] > target)
    {
        // move to left
        // high = mid - 1;
        search_recursive(nums, target, low, mid - 1);
    }
    else if (nums[mid] < target)
    {
        // move to right
        // low = mid + 1;
        search_recursive(nums, target, mid + 1, high);
    }
}

int main()
{
    vector<int> nums = {-1, 0, 3, 5, 9, 12};
    int n = nums.size();
    int target = 9;
    cout << "ITERATIVE: The index where target is present is: " << search_iterative(nums, target)<<endl;
    cout << "RECURSIVE: The index where target is present is: " << search_recursive(nums, target, 0, n - 1)<<endl;

    return 0;
}