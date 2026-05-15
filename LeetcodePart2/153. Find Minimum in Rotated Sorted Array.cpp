class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int low=0;
        int high=n-1;
        int minEle=INT_MAX;
        int elem;
        while(low<=high){
            int mid=(low+high)/2;
            if(nums[low]<=nums[high]){
                // left sorted
                elem=nums[low];
                minEle=min(minEle,elem);
                break;
            }
            if(nums[low]<=nums[mid]){
                // left sorted
                elem=nums[low];
                minEle=min(minEle,elem);
                low=mid+1;
            }else{
                // right sorted
                elem=nums[mid];
                minEle=min(minEle,elem);
                high=mid-1;
            }
        }
        return minEle;
    }
};
