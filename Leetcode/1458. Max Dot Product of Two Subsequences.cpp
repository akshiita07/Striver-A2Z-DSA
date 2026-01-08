class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        const int NEG_INF = -1e9;
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, NEG_INF));

        for(int i=n1-1;i>=0;i--){
            for(int j=n2-1;j>=0;j--){
                int choose=nums1[i]*nums2[j]+max(0,dp[i+1][j+1]);
                int s1=dp[i+1][j];
                int s2=dp[i][j+1];
                dp[i][j]=max({choose,s1,s2});
            }
        }
        return dp[0][0];
    }
};
