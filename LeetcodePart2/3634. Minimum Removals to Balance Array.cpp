class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        int n = nums.size();
        // balanced array: max elem<=k(min elem)
        // return min no of elems to remove to make arr balanced
        if (n == 1) {
            // arr of size 1 is always balanced
            return 0;
        }
        // sliding window approach:
        sort(nums.begin(), nums.end());
        int maxLen = 1;
        int l = 0;
        for (int r = 0; r < n; r++) {
            while (nums[r] > (1LL * k * nums[l])) {
                l++;
            }
            maxLen = max(maxLen, r - l + 1);
        }
        return n - maxLen;
    }
};
