class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MIN;
        for (int i = 0; i < n; i++) {
            int num1 = nums[i];
            for (int j = i + 1; j < n; j++) {
                int num2 = nums[j];
                ans = max(ans, (num1 - 1) * (num2 - 1));
            }
        }
        return ans;
    }
};
