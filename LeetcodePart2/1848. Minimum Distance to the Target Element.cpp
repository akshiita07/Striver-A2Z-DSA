class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int n=nums.size();
        int minVal=INT_MAX;
        for(int i=0;i<n;i++){
            if(nums[i]==target){
                //check if min:
                minVal=min(minVal,abs(i-start));
            }
        }
        return minVal;
    }
};
