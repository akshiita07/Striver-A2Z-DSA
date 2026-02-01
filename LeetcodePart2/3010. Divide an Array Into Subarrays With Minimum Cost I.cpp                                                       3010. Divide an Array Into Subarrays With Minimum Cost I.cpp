class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int n=nums.size();
        //cost of array=value of 1st element
        //divide array into 3 cts subarrays such that sum of cost is min
        int ans=INT_MAX;
        for(int i=1;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                ans=min(nums[0]+nums[i]+nums[j],ans);
            }
        }
        return ans;
    }
};
