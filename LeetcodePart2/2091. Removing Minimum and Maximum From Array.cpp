class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n=nums.size();
        // find indices of max & min:
        int maxEle=INT_MIN;
        int maxIdx=0;
        int minEle=INT_MAX;
        int minIdx=0;
        for(int i=0;i<n;i++){
            if(nums[i]>maxEle){
                maxEle=nums[i];
                maxIdx=i;
            }
            if(nums[i]<minEle){
                minEle=nums[i];
                minIdx=i;
            }
        }
        // now check 3 cases:
        //both in front
        int case1=max(maxIdx+1,minIdx+1);
        //both in back
        int case2=n-min(maxIdx,minIdx);
        //one in front other in back
        int case3=min((minIdx+1+n-maxIdx),(maxIdx+1+n-minIdx));
        return min(case1,min(case2,case3));
    }
};
