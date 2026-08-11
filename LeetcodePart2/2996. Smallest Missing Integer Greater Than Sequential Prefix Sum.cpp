class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n = nums.size();
        int sum = nums[0];
        for (int i = 1; i < n; i++) {
            if (nums[i] == nums[i - 1] + 1) {
                // if sequence follows then keep on adding
                sum += nums[i];
            } else {
                break;
            }
        }
        // elem missing & >=sum of longest prefix
        while (find(nums.begin(),nums.end(), sum)!=nums.end()) {
            sum++;
        }
        return sum;
    }
};
