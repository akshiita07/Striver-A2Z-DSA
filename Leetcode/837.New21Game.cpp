#include <bits/stdc++.h>
using namespace std;

double new21Game(int n, int k, int maxPts)
{
    // initially 0 points
    // draw integer between [1,maxPts] until points<k..when points>=k then stop drawing
    // Return the probability that Alice has n or fewer points
    // dp[i] = probability of reaching exactly i points
    // start: dp[0]=1
    if (k == 0 || n >= k + maxPts)
    {
        return 1.0;
    }
    vector<double> dp(n + 1, 0.0);
    dp[0] = 1.0;
    double windowSum = 1.0;
    double ans = 0.0;
    for (int i = 1; i <= n; i++)
    {
        dp[i] = windowSum / maxPts;
        if (i < k)
        {
            windowSum += dp[i];
        }
        else
        {
            ans += dp[i];
        }
        if (i - maxPts >= 0)
        {
            windowSum -= dp[i - maxPts];
        }
    }
    return ans;
}

int main()
{
    int n = 6;
    int k = 1;
    int maxPts = 10;
    cout << "\nprobability that Alice has n or fewer points= " << new21Game(n, k, maxPts);

    return 0;
}