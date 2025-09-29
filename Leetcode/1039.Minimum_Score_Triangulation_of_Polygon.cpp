#include <bits/stdc++.h>
using namespace std;

int minScoreTriangulation(vector<int> &values)
{
    int n = values.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));

    // gap = length of interval
    for (int gap = 2; gap < n; gap++)
    {
        for (int i = 0; i + gap < n; i++)
        {
            int j = i + gap;
            dp[i][j] = INT_MAX;
            for (int k = i + 1; k < j; k++)
            {
                int cost = dp[i][k] + dp[k][j] + values[i] * values[k] * values[j];
                dp[i][j] = min(dp[i][j], cost);
            }
        }
    }
    return dp[0][n - 1];
}

int main()
{
    vector<int> values = {};

    return 0;
}