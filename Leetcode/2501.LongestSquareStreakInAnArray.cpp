#include <bits/stdc++.h>
using namespace std;

// square streak:
// 1. length of the subsequence is at least 2  (2 or more: length)
// 2. after sorting the subsequence, each element (except the first element) is the square of the previous number
// Return the length of the longest square streak

int longestSquareStreak(vector<int> &nums)
{
    // first sort nums
    sort(nums.begin(), nums.end());

    unordered_set<long long> numSet(nums.begin(), nums.end());

    int longestStreak = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        long long current = nums[i];
        int streak = 0;

        // Check if we can form a square streak with 'current'
        while (numSet.find(current) != numSet.end())
        {
            streak++;
            current *= current; // Square the number
        }

        // Update longest streak found when length is atleast 2
        if (streak >= 2)
        {
            longestStreak = max(longestStreak, streak);
        }
    }

    // when length is atleast 2
    if (longestStreak >= 2)
    {
        return longestStreak;
    }
    // if there is no square streak so return -1
    return -1;
}

int main()
{
    // given integer array:
    vector<int> nums = {4, 3, 6, 16, 8, 2};
    cout << "\nLength of longest square streak in nums is: " << longestSquareStreak(nums);

    return 0;
}