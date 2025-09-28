#include<cmath>
class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        int n=nums.size();
        // sort lengths of triangle in a decreasing order:
        sort(nums.begin(),nums.end(),greater<int>());
        // sum of any 2 sides must be greater than third side
        for(int i=0;i<n-2;i++){
            int len1=nums[i];
            int len2=nums[i+1];
            int len3=nums[i+2];
            if(len1<len2+len3){
                // valid condition so return triangle perimeter
                return (len1+len2+len3);
            }
        }
        // else:
        return 0;
    }
};
