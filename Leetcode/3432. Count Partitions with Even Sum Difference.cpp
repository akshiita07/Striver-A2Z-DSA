class Solution {
public:
    int findSum(vector<int>& nums, int start, int end) {
        int sum = 0;
        for (int i = start; i <= end; i++) {
            sum += nums[i];
        }
        return sum;
    }
    
    int countPartitions(vector<int>& nums) {
        // partition index i st left subarray [0,i] and right [i+1,n-1]
        // diff bw sum of left & right subarr=even
        // Return the number of partitions
        int n = nums.size();
        int noOfPartitions = 0;
        // range of partition: 0 <= i < n - 1
        for (int i = 0; i < n-1; i++) {
            int partitionIndex = i;
            int leftSum = findSum(nums, 0, i);
            int rightSum = findSum(nums, i+1, n-1);
            if ((abs(leftSum - rightSum)) % 2 == 0) {
                // even diff:
                noOfPartitions++;
            }
        }
        return noOfPartitions;
    }
};
