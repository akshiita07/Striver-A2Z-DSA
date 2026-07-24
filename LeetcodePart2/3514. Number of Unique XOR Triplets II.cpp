class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        vector<bool> pairXor(2048, false);
        vector<bool> ans(2048, false);

        int n = nums.size();

        // All possible XORs of two elements (repetition allowed)
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                pairXor[nums[i] ^ nums[j]] = true;
            }
        }

        // XOR each pair result with every element
        for (int x = 0; x < 2048; x++) {
            if (!pairXor[x]) {
                continue;
            }
            for (int v : nums) {
                ans[x ^ v] = true;
            }
        }

        return count(ans.begin(), ans.end(), true);
    }
};
