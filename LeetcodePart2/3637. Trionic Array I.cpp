class Solution {
public:
    bool isInc(vector<int>& nums, int start, int end) {
        for (int i = start; i < end; i++) {
            if (nums[i + 1] <= nums[i]) {
                return false;
            }
        }
        return true;
    }

    bool isDec(vector<int>& nums, int start, int end) {
        for (int i = start; i < end; i++) {
            if (nums[i + 1] >= nums[i]) {
                return false;
            }
        }
        return true;
    }

    bool isTrionic(vector<int>& nums) {
        int n = nums.size();
        int p, q;
        for (int p = 1; p <= n - 3; p++) {
            for (int q = p + 1; q <= n - 2; q++) {
                if (isInc(nums, 0, p) && isDec(nums, p, q) &&
                    isInc(nums, q, n - 1)) {
                    return true;
                }
            }
        }
        return false;
    }
};
