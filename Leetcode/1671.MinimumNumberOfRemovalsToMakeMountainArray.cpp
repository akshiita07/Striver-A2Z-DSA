#include <bits/stdc++.h>
using namespace std;

int minimumMountainRemovals(vector<int> &nums)
{
    // conditions for mountain array:
    // arr.length >= 3
    // arr[0] < arr[1] < ... < arr[i - 1] < arr[i]
    // arr[i] > arr[i + 1] > ... > arr[arr.length - 1]
    // return the minimum number of elements to remove to make nums​​​ a mountain array
    int size = nums.size();
    vector<int> left(size, 1), right(size, 1); // Initialize LIS vectors for left and right

    // Compute the length of longest increasing subsequence (LIS) from the left
    for (int i = 1; i < size; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (nums[i] > nums[j])
            {
                left[i] = max(left[i], left[j] + 1); // Update the LIS at i based on j
            }
        }
    }

    // Compute the length of LIS from the right
    for (int i = size - 2; i >= 0; i--)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (nums[i] > nums[j])
            {
                right[i] = max(right[i], right[j] + 1); // Update the LIS at i based on j
            }
        }
    }

    int maxMountainLength = 0; // Variable to keep track of the longest mountain length

    // Find the maximum length of a bitonic subsequence (peak of the mountain)
    for (int i = 0; i < size; i++)
    {
        // Ensure we have an increasing and decreasing subsequence, i.e., a peak
        if (left[i] > 1 && right[i] > 1)
        {
            // Update the maxMountainLength if left[i] + right[i] - 1 is greater
            maxMountainLength = max(maxMountainLength, left[i] + right[i] - 1);
        }
    }

    // The minimum removals will be the total number of elements minus the longest mountain length
    return size - maxMountainLength;
}

int main()
{
    vector<int> nums = {2, 1, 1, 5, 6, 2, 3, 1};
    cout << "\nMin no of removals to make a mountain array are: " << minimumMountainRemovals(nums);

    return 0;
}