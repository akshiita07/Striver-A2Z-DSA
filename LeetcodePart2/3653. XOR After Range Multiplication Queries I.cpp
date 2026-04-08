class Solution {
public:
    const int MOD=1e9+7;
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int q = queries.size();
        // for each query:
        for (int i = 0; i < q; i++) {
            int idx = queries[i][0];
            while(idx<=queries[i][1]){
                nums[idx]=(1LL*nums[idx]*queries[i][3])%MOD;
                idx+=queries[i][2];
            }
        }
        //XOR of all nums:
        int ans=0;
        for(int i=0;i<nums.size();i++){
            ans^=nums[i];
        }
        return ans;
    }
};
