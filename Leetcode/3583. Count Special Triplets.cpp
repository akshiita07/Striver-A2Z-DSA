class Solution {
public:
    const int mod = 1e9 + 7;
    int brute_force(vector<int>& nums) {
        int noofSpecialTriplets = 0;
        int n = nums.size();
        for (int i = 0; i < n - 2; i++) {
            for (int j = i + 1; j < n - 1; j++) {
                for (int k = j + 1; k < n; k++) {
                    if (nums[i] == nums[j] * 2 && nums[k] == nums[j] * 2) {
                        noofSpecialTriplets++;
                    }
                }
            }
        }
        return noofSpecialTriplets % mod;
    }
    int specialTriplets(vector<int>& nums) {
        int n = nums.size();
        unordered_map<long long, long long> right, left;

        // Count all elements initially in right map
        for (auto it : nums){
            right[it]++;}

        long long noofSpecialTriplets = 0;

        for (int j = 0; j < n; j++) {
            long long mid = nums[j];
            right[mid]--;

            long long need = mid * 2;

            long long leftCount = left[need];
            long long rightCount = right[need];

            noofSpecialTriplets =
                (noofSpecialTriplets + (leftCount * rightCount) % mod) % mod;

            left[mid]++; 
        }
        return noofSpecialTriplets;
    }
};
