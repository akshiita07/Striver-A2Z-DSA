class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        // distinct count subarray= no of distinct elems in
        // sum of sq of distinct count of all subarrays
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            // for particular subarr:
            set<int> st;
            for (int j = i; j < n; j++) {
                st.insert(nums[j]);
                int distCount = st.size();
                ans.push_back(distCount);
            }
        }

        int sqDistCount = 0;
        for (auto it : ans) {
            sqDistCount += it * it;
        }
        return sqDistCount;
    }
};
