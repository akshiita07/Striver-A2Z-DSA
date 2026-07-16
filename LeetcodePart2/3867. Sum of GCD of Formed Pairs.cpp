class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n=nums.size();
        vector<int> prefixGcd(n,0);
        int mxi=0;
        for(int i=0;i<n;i++){
            mxi=max(nums[i],mxi);
            prefixGcd[i]=gcd(nums[i],mxi);
        }
        sort(prefixGcd.begin(),prefixGcd.end());
        long long ans=0;
        n=prefixGcd.size();
        for(int i=0;i<n/2;i++){
            ans+=gcd(prefixGcd[i],prefixGcd[n-i-1]);
        }
        return ans;
    }
};
