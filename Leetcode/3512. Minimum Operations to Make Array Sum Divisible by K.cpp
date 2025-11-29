class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        //goal: (sum of array)%k==0
        int n=nums.size();
        int arrSum=0;
        for(auto it:nums){
            arrSum+=it;
        }
        if(arrSum%k==0){
            return 0;
        }
        return arrSum%k;
    }
};
