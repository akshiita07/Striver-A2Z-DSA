class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        // no of distinct even nos= no of distinct odd nos
        int l = 0;
        int maxLen = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            set<int> evenSet, oddSet;
            for (int j = i; j < n; j++) {
                if (nums[j] % 2 == 0) {
                    // even:
                    evenSet.insert(nums[j]);
                } else {
                    // odd:
                    oddSet.insert(nums[j]);
                }
                if (evenSet.size() == oddSet.size()) {
                    maxLen = max(maxLen, j - i + 1);
                }
            }
        }
        return maxLen;
    }
};
