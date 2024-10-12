#include <bits/stdc++.h>
using namespace std;

int minGroups(vector<vector<int>> &intervals)
{
    vector<pair<int, int>> events;

    // Step 1: Record the start and end of each interval
    for (const auto &interval : intervals)
    {
        events.push_back({interval[0], 1});      // Start of interval:1
        events.push_back({interval[1] + 1, -1}); // End of interval (+1 to handle inclusiveness):-1
    }

    // Step 2: Sort events by time
    sort(events.begin(), events.end());

    int maxGroups = 0;
    int currentGroups = 0;

    // Step 3: Process events to find max overlapping intervals
    for (auto it : events)
    {
        currentGroups +=it.second; // Add 1 for start, subtract 1 for end
        maxGroups = max(maxGroups, currentGroups);
    }

    return maxGroups;
}

int main()
{
    vector<vector<int>> intervals = {{5, 10}, {6, 8}, {1, 5}, {2, 3}, {1, 10}};
    cout << "\nMin no of group reqd: " << minGroups(intervals);

    return 0;
}