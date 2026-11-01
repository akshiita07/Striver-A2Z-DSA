class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();
        int mini = *min_element(nums.begin(), nums.end());
        int ans = 0;
        for (auto it : nums) {
            ans += it - mini;
        }

        return ans;
    }
};
