#include <bits/stdc++.h>
using namespace std;

int minCost(string colors, vector<int> &neededTime)
{
    // colors[i] = color of the ith balloon
    // does not want two consecutive balloons to be of the same color
    // neededTime[i] = time (in seconds) that Bob needs to remove the ith balloon from the rope
    // Return the minimum time Bob needs to make the rope colorful
    int n = neededTime.size();
    // n no of balloons
    int ans = 0;
    int maxTime = neededTime[0];
    char color = colors[0];
    for (int i = 1; i < n; i++)
    {
        if (colors[i] == color)
        {
            // color repeated so remove this:
            ans += min(maxTime, neededTime[i]);
            maxTime = max(maxTime, neededTime[i]);
        }
        else
        {
            maxTime = neededTime[i];
        }
        // update color
        color = colors[i];
    }
    return ans;
}

int main()
{

    return 0;
}