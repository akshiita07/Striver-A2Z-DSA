#include <bits/stdc++.h>
using namespace std;

long long maximumSubarraySum(vector<int> &nums, int k)
{
    //  Find the maximum subarray sum of all the subarrays of nums such that:
    // The length of the subarray is k, and
    // All the elements of the subarray are distinct.
    unordered_set<int> window_elements;
    long long max_sum = 0;
    long long current_sum = 0;
    int left = 0;
    int n = nums.size();

    for (int right = 0; right < n; right++)
    {   
        // if duplicates present then shrink window
        while (window_elements.count(nums[right])!=0)
        {
            // Remove element at 'left' from current window
            current_sum -= nums[left];
            window_elements.erase(nums[left]);
            left++;
        }

        // Add the current element to the window
        current_sum += nums[right];
        window_elements.insert(nums[right]);

        // Check if window length is exactly k
        if (right - left + 1 == k)
        {
            max_sum = max(max_sum, current_sum);

            // Slide the window by removing the leftmost element
            current_sum -= nums[left];
            window_elements.erase(nums[left]);
            ++left;
        }
    }

    return max_sum;
}

int main()
{
    vector<int> nums = {1, 5, 4, 2, 9, 9, 9};
    int k = 3;
    cout << "\nMaxm subarray sum that meets cnds: " << maximumSubarraySum(nums, k);

    return 0;
}