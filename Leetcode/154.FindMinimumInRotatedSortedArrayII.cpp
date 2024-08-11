class Solution {
public:
    int findMin(vector<int>& nums) {
        int minEle = nums[0];
        int ele;
        int n = nums.size();
        int low = 0;
        int high = n - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if(nums[low]==nums[mid] && nums[mid]==nums[high] && low!=mid && mid!=high){
                low++;
                high--;
                continue;
            }
            // check if lhs is sorted
            if (nums[low] <= nums[mid]) {
                // left half is sorted
                // right half is NOT sorted

                // take min elem from left half
                ele = nums[low]; // because sorted
                minEle = min(ele, minEle);
                low = mid + 1;
            }
            // check if rhs is sorted
            else {
                // right is sorted
                // find min from sorted half
                ele = nums[mid];
                minEle = min(ele, minEle);

                high = mid - 1;
            }
        }
        return minEle;
    }
};