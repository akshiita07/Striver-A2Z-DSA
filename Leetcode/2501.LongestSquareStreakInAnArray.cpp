#include <bits/stdc++.h>
using namespace std;

int longestSquareStreak(vector<int> &nums)
{
    sort(nums.begin(), nums.end());

    unordered_set<long long> numSet(nums.begin(), nums.end());

    int longestStreak = 0;

    for (auto it : nums)
    {
        long long current = it;
        int streak = 0;

        // Check if we can form a square streak with 'current'
        while (numSet.find(current) != numSet.end())
        {
            streak++;
            current *= current; // Square the number
            // Stop if current exceeds our bounds to avoid overflow or invalid values
            if (current > 1e5){
                break;

            }
        }

        // Update longest streak found
        if (streak >= 2)
        {
            longestStreak = max(longestStreak, streak);
        }
    }

    if (longestStreak >= 2)
    {
        return longestStreak;
    }
    else
    {
        return -1;
    }
    return -1;
}

int main()
{

    return 0;
}