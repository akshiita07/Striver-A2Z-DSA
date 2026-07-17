class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        vector<int> gcdPairs;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                gcdPairs.push_back(gcd(nums[i], nums[j]));
            }
        }
        sort(gcdPairs.begin(), gcdPairs.end());
        n = queries.size();
        vector<int> ans(n, 0);
        for (int i = 0; i < n; i++) {
            ans[i] = gcdPairs[queries[i]];
        }
        return ans;
    }
};
