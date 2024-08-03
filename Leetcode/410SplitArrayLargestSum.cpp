#include <bits/stdc++.h>
using namespace std;
// SAME AS ALLOCATE BOOKS QUESTION

// fnc-O(n)
int countNoOfSubarrays(vector<int> &nums, int k, int maxAlloc)
{
    int noSubarrays = 1;
    int sum = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if ((sum + nums[i]) <= maxAlloc)
        {
            sum += nums[i];
        }
        else
        {
            noSubarrays++;
            sum = nums[i];
        }
    }
    return noSubarrays;
}

// bin search:O(log2(sum-max+1))*O(n)-->fnc
int splitArray(vector<int> &nums, int k)
{
    int low = *max_element(nums.begin(), nums.end());
    int high = accumulate(nums.begin(), nums.end(), 0);

    while (low <= high)
    {
        int mid = (low + high) / 2;
        int noOfSubarrays = countNoOfSubarrays(nums, k, mid);
        if (noOfSubarrays > k)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return low;
}

int main()
{
    vector<int> nums = {7, 2, 5, 10, 8};
    int k = 2;
    cout << "\nThe min sum out of all max sums is: " << splitArray(nums, k);

    return 0;
}