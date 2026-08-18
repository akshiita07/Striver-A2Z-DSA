class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> cnt;
        for (int i = 0; i < n; i++) {
            cnt[nums[i]]++;
        }
        if (k == 1) {
            // largest elem with count=1
            int maxi = -1;
            for (auto it : cnt) {
                if (it.second == 1) {
                    maxi = max(maxi, it.first);
                }
            }
            return maxi;
        } else if (k == n) {
            // largest elem of entire array
            return *max_element(nums.begin(), nums.end());
        } else {
            // either nums[0] or nums[n-1]
            if (cnt[nums[0]] == 1 && cnt[nums[n - 1]] == 1){
                return max(nums[0],nums[n - 1]);
            }else if (cnt[nums[0]] == 1) {
                return nums[0];
            } else if (cnt[nums[n - 1]] == 1) {
                return nums[n - 1];
            } else {
                return -1;
            }
        }
        return -1;
    }
};
