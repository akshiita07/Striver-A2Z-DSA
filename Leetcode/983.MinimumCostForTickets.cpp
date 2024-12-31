#include <bits/stdc++.h>
using namespace std;

int mincostTickets(vector<int> &days, vector<int> &costs)
{
    // 1-day pass : costs[0] dollars,
    // 7-day pass : costs[1] dollars,
    // 30-day pass: costs[2] dollars
    unordered_set<int> travelDays(days.begin(), days.end());
    int lastDay = days.back();
    // DP array to store minimum cost up to each day
    vector<int> dp(lastDay + 1, 0);

    for (int i = 1; i <= lastDay; i++)
    {
        if (travelDays.find(i) == travelDays.end())
        {
            // If not traveling on this day, cost remains the same as the previous day
            dp[i] = dp[i - 1];
        }
        else
        {
            // Otherwise, calculate the minimum cost for this day
            dp[i] = min({
                dp[i - 1] + costs[0],         // 1-day pass
                dp[max(0, i - 7)] + costs[1], // 7-day pass
                dp[max(0, i - 30)] + costs[2] // 30-day pass
            });
        }
    }

    return dp[lastDay];
}

int main()
{
    vector<int> days = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 30, 31};
    vector<int> costs = {2, 7, 15};
    // 17
    cout << "\nMin money reqd: " << mincostTickets(days, costs);
    return 0;
}