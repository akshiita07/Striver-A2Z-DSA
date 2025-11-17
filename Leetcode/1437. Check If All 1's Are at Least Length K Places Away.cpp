class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        // vector with all indices where 1 is present:
        vector<int> ans;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] == 1) {
                ans.push_back(i);
            }
        }
        if (ans.size() <= 1) {
            return true;
        }
        // now check if diff between ans indices is atleast k ie >=k
        for (int i = 0; i < ans.size() - 1; i++) {
            if ((ans[i + 1] - ans[i] - 1) < k) {
                return false;
            }
        }
        return true;
    }
};
