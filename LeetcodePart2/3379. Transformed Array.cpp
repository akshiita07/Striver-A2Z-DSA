class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n=nums.size();
        vector<int> result(n,0);
        for(int i=0;i<n;i++){
            if(nums[i]>0){
                //move nums[i] steps to right:
                int newIndex=(i+nums[i])%n;
                result[i]=nums[newIndex];
            }else if(nums[i]<0){
                //move abs(nums[i]) steps to left:
                int newIndex=(i-abs(nums[i]))%n;
                if(newIndex<0){
                    newIndex+=n;
                }
                result[i]=nums[newIndex];
            }else{
                result[i]=nums[i];
            }
        }
        return result;
    }
};
