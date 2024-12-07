#include <bits/stdc++.h>
using namespace std;

bool canDivide(const vector<int> &nums, int maxOperations, int penalty)
{
    int operations = 0;
    for (auto it : nums)
    {
        if (it > penalty)
        {
            operations += (it - 1) / penalty; // Compute splits needed
        }
        if (operations > maxOperations)
        {
            return false; // Exceeds max operations
        }
    }
    return true;
}

int minimumSize(vector<int> &nums, int maxOperations)
{
    // ith bag contains nums[i] balls
    // perform the following operation at most maxOperations times:
    // Take any bag of balls and divide it into two new bags with a positive number of balls.
    // penalty=maximum number of balls in a bag->minimize your penalty after the operations.

    // Return the minimum possible penalty after performing the operations.
    int left = 1;
    int right = *max_element(nums.begin(), nums.end());
    int result = right;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (canDivide(nums, maxOperations, mid))
        {
            result = mid; // Try for a smaller penalty
            right = mid - 1;
        }
        else
        {
            left = mid + 1; // Try for a larger penalty
        }
    }

    return result;
}

int main()
{

    return 0;
}