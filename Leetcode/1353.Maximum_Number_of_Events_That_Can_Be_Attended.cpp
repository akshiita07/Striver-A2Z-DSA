#include <bits/stdc++.h>
using namespace std;

int maxEvents(vector<vector<int>> &events)
{
    // events[i] = [startDayi, endDayi]
    // attend an event i at any day d where startTimei <= d <= endTimei
    // Return the maximum number of events you can attend
    sort(events.begin(), events.end());
    int n = events.size();
    int i = 0;
    int day = 0;
    int ans = 0;

    // Min-heap:
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int lastDay = 0;
    for (auto it : events)
    {
        lastDay = max(lastDay, it[1]);
    }

    for (day = 1; day <= lastDay; day++)
    {
        // Add all events that start today
        while (i < n && events[i][0] == day)
        {
            minHeap.push(events[i][1]);
            i++;
        }

        while (!minHeap.empty() && minHeap.top() < day)
        {
            minHeap.pop();
        }

        if (!minHeap.empty())
        {
            minHeap.pop();
            ans++;
        }
    }

    return ans;
}

int main()
{
    vector<vector<int>> events = {{1, 2}, {2, 3}, {3, 4}, {1, 2}};
    cout << "\nMaximum number of events that can be attended: " << maxEvents(events);

    return 0;
}