#include <bits/stdc++.h>
using namespace std;
// given time in "HH:MM" format
// HH-> 00 to 24
// MM-> 00 to 59
// return the minimum minutes difference between any two time-points in the list

int brute_force(vector<string> &timePoints)
{
    // find all time differences & then return min one
    // first convert hours to mins
    // extract hours from timePoints
    vector<int> allMinTime;
    for (int i = 0; i < timePoints.size(); i++)
    {
        // add all min time to allMinTime vector:
        int hrs = stoi(timePoints[i].substr(0, 2));  // start from 0 index with length=2
        int mins = stoi(timePoints[i].substr(3, 2)); // start from 3 index with length=2
        int newTime = hrs * 60 + mins;
        allMinTime.push_back(newTime);
    }
    // sort this array
    sort(allMinTime.begin(), allMinTime.end());
    // find min diff betweeen consecutive time stamps
    int minDiff = INT_MAX;
    for (int i = 1; i < allMinTime.size(); i++)
    {
        int diff = allMinTime[i] - allMinTime[i - 1];
        minDiff = min(minDiff, diff);
    }
    // also check for last & first diff:
    int totalTime = 24 * 60;
    int lastFirstDiff = totalTime - (allMinTime.back() - allMinTime[0]);
    minDiff = min(minDiff, lastFirstDiff);
    return minDiff;
}

int findMinDifference(vector<string> &timePoints)
{
    // find 2 closest time points & then find diff
    // using bucket sort approach where we take an array of sixe 24*60 a these r total fixed amount of minutes
}

int main()
{
    vector<string> timePoints1 = {"23:59", "00:00"};
    cout << "\nBRUTE FORCE:: 1: Min diff bw any 2 time points is: " << findMinDifference(timePoints1);
    cout << "\n1: Min diff bw any 2 time points is: " << findMinDifference(timePoints1);
    vector<string> timePoints2 = {"00:00", "23:59", "00:00"};
    cout << "\nBRUTE FORCE:: 2: Min diff bw any 2 time points is: " << findMinDifference(timePoints2);
    cout << "\n2: Min diff bw any 2 time points is: " << findMinDifference(timePoints2);

    return 0;
}