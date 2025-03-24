#include <bits/stdc++.h>
using namespace std;

int brute_Force(int days, vector<vector<int>> &meetings)
{
    // meetings[i] = [start_i, end_i]
    int n = meetings.size();
    // Return count of days when the employee is available for work but no meetings are scheduled
    vector<int> dp(days + 1, 0);
    for (int i = 0; i < n; i++)
    {
        for (int j = meetings[i][0]; j <= meetings[i][1]; j++)
        {
            dp[j] = 1;
        }
    }
    int ans = 0;
    for (int i = 1; i <= days; i++)
    {
        if (dp[i] == 0)
        {
            ans++;
        }
    }
    return ans;
}

// Sorting + Merging Intervals
int countDays(int days, vector<vector<int>> &meetings)
{
    // meetings[i] = [start_i, end_i]
    int n = meetings.size();
    // Return count of days when the employee is available for work but no meetings are scheduled
    sort(meetings.begin(), meetings.end());
    int mergedStart = -1;
    int mergedEnd = -1;
    int busyDays = 0;
    for (auto &it : meetings)
    {
        int start = it[0];
        int end = it[1];
        if (start > mergedEnd)
        {
            // does not overlap:
            if (mergedStart != -1)
            {
                busyDays += (mergedEnd - mergedStart + 1);
            }
            mergedStart = start;
            mergedEnd = end;
        }
        else
        {
            // overlaps so merge:
            mergedEnd = max(mergedEnd, end);
        }
    }
    // add last one:
    busyDays += (mergedEnd - mergedStart + 1);
    return days - busyDays;
}

int main()
{
    int days = 10;
    vector<vector<int>> meetings = {{5, 7}, {1, 3}, {9, 10}};
    cout << "\nbrute_Force: count of days when the employee is available for work but no meetings are scheduled= " << brute_Force(days, meetings);
    cout << "\ncount of days when the employee is available for work but no meetings are scheduled= " << countDays(days, meetings);

    return 0;
}