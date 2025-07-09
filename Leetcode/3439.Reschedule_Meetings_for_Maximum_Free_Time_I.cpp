#include <bits/stdc++.h>
using namespace std;

int maxFreeTime(int eventTime, int k, vector<int> &startTime, vector<int> &endTime)
{
    // event occurs from time t to eventTime
    int n = startTime.size(); //== endTime.size();
    // ith meeting occurs during the time [startTime[i], endTime[i]]
    // reschedule at most k meetings by moving their start time while maintaining the same duration, to maximize the longest continuous period of free time
    // Return the maximum amount of free time possible after rearranging the meetings
    vector<int> gaps;
    // gap before the first meeting:
    gaps.push_back(startTime[0] - 0);
    // gap between meetings:
    for (int i = 1; i < n; i++)
    {
        // start of next & end of prev:
        gaps.push_back(startTime[i] - endTime[i - 1]);
    }
    // gap after the last meeting:
    gaps.push_back(eventTime - endTime[n - 1]);
    int m = gaps.size();
    // sliding window:
    int windowSize = k + 1;
    int maxFreeTime = 0;
    int sum = 0;
    for (int i = 0; i < m; i++)
    {
        sum += gaps[i];
        if (i >= windowSize)
        {
            sum -= gaps[i - windowSize];
        }
        if (i >= windowSize - 1)
        {
            maxFreeTime = max(maxFreeTime, sum);
        }
    }
    return maxFreeTime;
}

int main()
{
    int eventTime = 10;
    int k = 1;
    vector<int> startTime = {0, 2, 9};
    vector<int> endTime = {1, 4, 10};
    cout << "\nMaximum amount of free time possible= " << maxFreeTime(eventTime, k, startTime, endTime);

    return 0;
}