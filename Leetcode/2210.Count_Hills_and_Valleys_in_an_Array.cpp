#include <bits/stdc++.h>
using namespace std;

int countHillValley(vector<int> &nums)
{
    // hill at index i if all its non equal neighbours are LESS than nums[i]
    // valley at index i if all its non equal neighbours are GREATER than nums[i]
    // adjacent indices part of same hill/valley if nums[i] == nums[j]
    // Return the number of hills and valleys in nums
    // Step 1: Remove consecutive duplicates
    int n = nums.size();
    vector<int> removeDuplicates;
    removeDuplicates.push_back(nums[0]);
    for (int i = 1; i < n; i++)
    {
        if (nums[i] != nums[i - 1])
        {
            removeDuplicates.push_back(nums[i]);
        }
    }
    int count = 0;
    for (int i = 1; i < removeDuplicates.size() - 1; i++)
    {
        // if greater than both: hill
        // if smaller than both: valley
        if ((removeDuplicates[i] > removeDuplicates[i - 1] && removeDuplicates[i] > removeDuplicates[i + 1]) ||
            (removeDuplicates[i] < removeDuplicates[i - 1] && removeDuplicates[i] < removeDuplicates[i + 1]))
        {
            count++;
        }
    }

    return count;
}

int main()
{
    vector<int> nums = {2, 4, 1, 1, 6, 5};
    cout << "\nNumber of hills and valleys: " << countHillValley(nums);

    return 0;
}