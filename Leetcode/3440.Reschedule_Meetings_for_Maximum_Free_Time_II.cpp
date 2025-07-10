#include <bits/stdc++.h>
using namespace std;

int maxFreeTime(int eventTime, vector<int> &startTime, vector<int> &endTime)
{
    // eventTime: duration of event
    int n = startTime.size(); //==endTime.size();
    // reschedule at most one meeting by moving its start time
    // maximize the longest continuous period of free time during the event
    vector<bool> canBeMoved(n); // T if meeting i can be moved without overlap

    // Check from left to right
    int leftGap = 0;
    for (int i = 0; i < n; i++)
    {
        int duration = endTime[i] - startTime[i];
        if (duration <= leftGap)
        {
            canBeMoved[i] = true;
        }
        if (i == 0)
        {
            leftGap = startTime[i];
        }
        else
        {
            leftGap = max(leftGap, startTime[i] - endTime[i - 1]);
        }
    }

    // Check from right to left
    int rightGap = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        int duration = endTime[i] - startTime[i];
        if (duration <= rightGap)
        {
            canBeMoved[i] = true;
        }
        if (i == n - 1)
        {
            rightGap = eventTime - endTime[i];
        }
        else
        {
            rightGap = max(rightGap, startTime[i + 1] - endTime[i]);
        }
    }

    // Now calculate the maximum free time
    int maxFree = 0;
    for (int i = 0; i < n; i++)
    {
        int left = (i == 0) ? 0 : endTime[i - 1];
        int right = (i == n - 1) ? eventTime : startTime[i + 1];
        int gap = right - left;

        if (canBeMoved[i])
        {
            maxFree = max(maxFree, gap);
        }
        else
        {
            int duration = endTime[i] - startTime[i];
            maxFree = max(maxFree, gap - duration);
        }
    }

    return maxFree;
}

int main()
{
    int eventTime = 10;
    vector<int> startTime = {0, 7, 9};
    vector<int> endTime = {1, 8, 10};
    cout << "\nmaximum amount of free time possible after rearranging the meetings= " << maxFreeTime(eventTime, startTime, endTime);

    return 0;
}