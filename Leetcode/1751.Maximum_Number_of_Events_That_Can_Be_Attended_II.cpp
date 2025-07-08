#include <bits/stdc++.h>
using namespace std;

int maxValue(vector<vector<int>> &events, int k)
{
    // events[i] = [startDayi, endDayi, valuei]
    //  if you attend this event, you will receive a value of valuei
    // k : represents the maximum number of events you can attend
    // Return the maximum sum of values that you can receive by attending events
    int n = events.size();
    // Sort events by end day
    sort(events.begin(), events.end(), [](auto &a, auto &b)
         { return a[1] < b[1]; });

    // Extract end times for binary search
    vector<int> endTimes;
    for (auto it : events)
    {
        endTimes.push_back(it[1]);
    }

    // dp[i][j] = max value by considering first i events and picking j events
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));

    for (int i = 1; i <= n; i++)
    {
        int curStart = events[i - 1][0];
        int curVal = events[i - 1][2];

        // Find the last event that ends before curStart (non-overlapping)
        int prev = upper_bound(endTimes.begin(), endTimes.end(), curStart - 1) - endTimes.begin();

        for (int j = 1; j <= k; j++)
        {
            // Skip event
            dp[i][j] = max(dp[i][j], dp[i - 1][j]);

            // Take event: dp[prev][j-1] + curVal
            dp[i][j] = max(dp[i][j], dp[prev][j - 1] + curVal);
        }
    }

    return dp[n][k];
}

int main()
{
    vector<vector<int>> events = {{1, 2, 4}, {3, 4, 3}, {2, 3, 10}};
    int k = 2;
    cout << "\nmaximum sum of values= " << maxValue(events, k);

    return 0;
}