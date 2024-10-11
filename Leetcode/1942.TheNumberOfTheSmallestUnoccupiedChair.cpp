#include <bits/stdc++.h>
using namespace std;

int smallestChair(vector<vector<int>> &times, int targetFriend)
{
    // get arrival times & leaving times
    // person has to sit on smallest number of unoccupied chair
    // give chair no of target friend
    int n = times.size();

    // {time, {friendId, isArriving=true/isleaving:false}}
    vector<pair<int, pair<int, bool>>> events;
    for (int i = 0; i < n; i++)
    {
        events.push_back({times[i][0], {i, true}});  // arrival
        events.push_back({times[i][1], {i, false}}); // leaving
    }

    // Sort events based on time, with leaving events being prioritized if they occur at the same time
    sort(events.begin(), events.end(), [](const pair<int, pair<int, bool>> &a, const pair<int, pair<int, bool>> &b)
         {
            if (a.first == b.first) {
                return a.second.second < b.second.second;  // prioritize leaving (false) over arrival (true)
            }
            return a.first < b.first; });

    // Min-heap to track available chairs
    priority_queue<int, vector<int>, greater<int>> availableChairs;
    for (int i = 0; i < n; i++)
    {
        availableChairs.push(i); // Initially all chairs are available
    }

    // To track which chair each friend is sitting on
    vector<int> friendToChair(n, -1);

    // Process events
    for (const auto &event : events)
    {
        int friendId = event.second.first;
        bool isArriving = event.second.second;

        if (isArriving)
        {
            // Friend arrives -> allocate the smallest available chair
            int chair = availableChairs.top();
            availableChairs.pop();
            friendToChair[friendId] = chair;

            // If this is the target friend, return the chair number
            if (friendId == targetFriend)
            {
                return chair;
            }
        }
        else
        {
            // Friend leaves -> free their chair
            availableChairs.push(friendToChair[friendId]);
        }
    }

    return -1; // Should not reach here
}

int main()
{
    vector<vector<int>> times = {{1, 4}, {2, 3}, {4, 6}};
    int targetFriend = 1;
    cout << "\nThe chair number of person= " << targetFriend << " is: " << smallestChair(times, targetFriend);

    return 0;
}