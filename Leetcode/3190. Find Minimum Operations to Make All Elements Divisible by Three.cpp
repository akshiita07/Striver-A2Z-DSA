class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        // can add/subtract 1
        // min no of operations to make all elements divisible by 3
        int n=nums.size();
        int noOfOperations=0;
        for(int i=0;i<n;i++){
            if(nums[i]%3!=0){
                //check how many operations
                noOfOperations+=min(nums[i]%3,3-(nums[i]%3));  // remainder no of +/-s
            }
            //else divisible so okay
        }
        return noOfOperations;
    }
};
