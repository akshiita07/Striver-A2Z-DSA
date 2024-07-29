#include <bits/stdc++.h>
using namespace std;

// BRUTE FORCE- LINEAR SEARCH- O(n)
// OPTIMAL SOLN- BINARY SEARCH- O(logn)->eliminate array
int search(vector<int> &nums, int target)
{
    // array is rotated ie 1 half is not sorted
    // step1. identify sorted half->left or right?
    int low = 0;
    int n = nums.size() - 1;
    int high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (nums[mid] == target)
        {
            return mid;
        }
        // is left half sorted?
        if (nums[low] <= nums[mid])
        {
            // left is sorted
            if(nums[low]<=target  && target<=nums[mid]){
                // eliminate right half
                high=mid-1;
            }else{
                // eliminate left half
                low=mid+1;
            }
        }
        else
        {
            //  right half is sorted
            if( nums[mid]<=target && target<=nums[high] ){//lies on right half
                // eliminate left half
                low=mid+1;
            }else{
                // eliminate right half
                high=mid-1;
            }
        }
    }   
    return -1;  //else
}

int main()
{
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    int target = 0;
    
    cout << "The index " << target << " is present in array at index: " << search(nums, target) << endl;

    return 0;
}