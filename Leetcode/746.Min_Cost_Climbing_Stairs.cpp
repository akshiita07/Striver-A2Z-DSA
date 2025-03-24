class Solution
{
public:
    int minCostClimbingStairs(vector<int> &cost)
    {
        // climb 1/2 steps
        // can start either at 0 or 1
        int n = cost.size();
        vector<int> dp(n + 2, 0);
        // cost at nth top floor=0
        for (int i = n - 1; i >= 0; i--)
        {
            dp[i] = cost[i] + min(dp[i + 1], dp[i + 2]);
        }
        return min(dp[0], dp[1]);
    }
};