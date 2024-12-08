#include <bits/stdc++.h>
using namespace std;

// comparator lambda fnc to sort events based on thier end times:
bool compareEndTimes(const vector<int> &a, const vector<int> &b)
{
    if (a[1] < b[1])
    {
        return true;
    }
    return false;
}

int maxTwoEvents(vector<vector<int>> &events)
{
    // events[i] = [startTimei, endTimei, valuei]
    // if you attend an event with end time t, the next event must start at or after t + 1
    // choose 2 or less non-overlapping events to attend st sum of their values is maximized.
    // return max sum
    int n = events.size();
    // sort events based on thier end times using a comparator lambda fnc:
    sort(events.begin(), events.end(), compareEndTimes);
    // all max values to be stored
    vector<int> maxValues(n, 0);
    // add values at [0,1,2] ie 2nd index is value
    maxValues[0] = events[0][2];
    for (int i = 1; i < n; i++)
    {
        // fill max values for all elements:
        maxValues[i] = max(events[i][2], maxValues[i - 1]);
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        // take this event
        ans = max(ans, events[i][2]);
        // choose next possible non overlapping event that maximises ans
        //  binary search:
        int best = -1;
        // for (int j = 0; j < i; j++)
        // {
        //     // end time of prev event<start time of next event
        //     if (events[j][1] < events[i][0])
        //     {
        //         best = j;
        //     }
        // }
        int left = 0;
        int right = i - 1;
        while (left <= right)
        {
            int mid = (left + right) / 2;
            if (events[mid][1] < events[i][0])
            {
                best = mid;
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }

        if (best != -1)
        {
            ans = max(ans, events[i][2] + maxValues[best]);
        }
    }
    return ans;
}

int main()
{
    vector<vector<int>> events = {{1, 3, 2}, {4, 5, 2}, {2, 4, 3}};
    cout << "\nMax possible value: " << maxTwoEvents(events);

    return 0;
}