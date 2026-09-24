class Solution {
public:
    int sumDigits(int n) {
        int sum = 0;
        while (n > 0) {
            int remain = n % 10;
            sum += remain;
            n = n / 10;
        }
        return sum;
    }
    int smallestIndex(vector<int>& nums) {
        // smallest i
        // sum of digits of nums[i]==i
        // else -1
        for (int i = 0; i < nums.size(); i++) {
            if (sumDigits(nums[i]) == i) {
                return i;
            }
        }
        return -1;
    }
};
