class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> sumList;
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            sumList.push_back(sum);
        }
        return sumList;
    }
};