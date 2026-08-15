class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        // XOR: diff bits: 1 same bits:0
        int arrXor = 0;
        bool isNonZero = false;
        for (int i = 0; i < n; i++) {
            arrXor ^= nums[i];
            if (nums[i] != 0) {
                isNonZero = true;
            }
        }
        if (arrXor!= 0) {
            // entire non zero xor
            return n;
        }
        if (isNonZero) {
            // entire xor=0 but remove element to make non zero
            return n - 1;
        }
        return 0;
    }
};
