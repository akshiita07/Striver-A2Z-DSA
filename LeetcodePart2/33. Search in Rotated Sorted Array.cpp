class Solution {
public:
    int search(vector<int>& nums, int target) {
        // array is rotated ie 1 half is not sorted
    // step1. identify sorted half->left or right?
    int low = 0;
    int n = nums.size();
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
};
