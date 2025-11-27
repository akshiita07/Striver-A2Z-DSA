class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        // maximum sum of subarray nums st (size of subarray)%k==0
        int n = nums.size();
        vector<long long> minPrefix(k, LLONG_MAX);

        long long prefix = 0;
        long long ans = LLONG_MIN;

        minPrefix[0] = 0;

        for (int i = 0; i < n; i++) {
            prefix += nums[i];
            int r = (i + 1) % k; 
            if (minPrefix[r] != LLONG_MAX) {
                ans = max(ans, prefix - minPrefix[r]);
            }
            minPrefix[r] = min(minPrefix[r], prefix);
        }

        return ans;
    }
};
