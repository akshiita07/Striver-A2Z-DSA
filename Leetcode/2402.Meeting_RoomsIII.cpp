#include <bits/stdc++.h>
using namespace std;

int mostBooked(int n, vector<vector<int>> &meetings)
{
    // meetings[i] = [starti, endi)
    // meeting in unused room with lowest number
    // Return the number of the room that held the most meetings
    vector<long long> roomAvailabilityTime(n, 0);
    vector<int> meetingCount(n, 0);
    sort(meetings.begin(), meetings.end());

    for (auto &meeting : meetings)
    {
        int start = meeting[0];
        int end = meeting[1];
        long long minRoomAvailabilityTime = LLONG_MAX;
        int minAvailableTimeRoom = 0;
        bool foundUnusedRoom = false;

        for (int i = 0; i < n; i++)
        {
            if (roomAvailabilityTime[i] <= start)
            {
                foundUnusedRoom = true;
                meetingCount[i]++;
                roomAvailabilityTime[i] = end;
                break;
            }

            if (minRoomAvailabilityTime > roomAvailabilityTime[i])
            {
                minRoomAvailabilityTime = roomAvailabilityTime[i];
                minAvailableTimeRoom = i;
            }
        }

        if (!foundUnusedRoom)
        {
            roomAvailabilityTime[minAvailableTimeRoom] += end - start;
            meetingCount[minAvailableTimeRoom]++;
        }
    }
    int maxMeetingCount = 0, maxMeetingCountRoom = 0;
    for (int i = 0; i < n; i++)
    {
        if (meetingCount[i] > maxMeetingCount)
        {
            maxMeetingCount = meetingCount[i];
            maxMeetingCountRoom = i;
        }
    }
    return maxMeetingCountRoom;
}

int main()
{
    int n = 2;
    vector<vector<int>> meetings = {{0, 10}, {1, 5}, {2, 7}, {3, 4}};
    cout << "\nroom that held the most meetings: " << mostBooked(n, meetings);

    return 0;
}