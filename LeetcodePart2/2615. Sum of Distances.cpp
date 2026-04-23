TLE:
class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n=nums.size();
        vector<long long> ans(n,0);
        for(int i=0;i<n;i++){
            long long sum=0;
            for(int j=0;j<n;j++){
                if(nums[i]==nums[j] && i!=j){
                    sum+=abs(i-j);
                }
            }
            ans[i]=sum;
        }
        return ans;
    }
};
