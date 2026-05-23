class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();

        // count no of rotation points where arr[n]>arr[n+1]
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] > nums[(i + 1)%n]) {    //check comparison bw last & first element
                count++;
            }
            // if no of rotation points>1 then array CANNOT BE SORTED
            if (count > 1) {
                return false;
            }
        }
        return true;
    }
};
