class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        // good array: frew<=k
        int i = 0;
        unordered_map<int, int> hashMap;
        int ans = 0;
        for (int j = 0; j < n; j++) {
            // freq calc:
            hashMap[nums[j]]++;
            while (hashMap[nums[j]] > k) {
                // remove left elements
                hashMap[nums[i]]--;
                i++;
            }
            ans = max(ans, j - i + 1);
        }
        return ans;
    }
};
