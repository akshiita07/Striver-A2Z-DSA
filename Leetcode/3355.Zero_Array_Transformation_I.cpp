#include <bits/stdc++.h>
using namespace std;

bool checkIfAllZero(vector<int> &nums)
{
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        if (nums[i] != 0)
        {
            return false;
        }
    }
    return true;
}

// Time: O(n*m)
bool brute_force(vector<int> &nums, vector<vector<int>> &queries)
{
    int n = nums.size();
    // queries[i] = [li, ri]
    // select subset of indices in range [li, ri] and decrement value by 1
    // Return true if possible to transform nums into a Zero Array
    int m = queries.size();
    for (int i = 0; i < m; i++)
    {
        int start = queries[i][0];
        int end = queries[i][1];
        // loop thru all these indices:
        for (int j = start; j <= end; j++)
        {
            if (nums[j] == 0)
            {
                continue;
            }
            else
            {
                nums[j]--;
            }
        }
        // check if all elements are zero:
        if (checkIfAllZero(nums) == true)
        {
            return true;
        }
    }
    return false;
}

bool isZeroArray(vector<int> &nums, vector<vector<int>> &queries)
{
    int n = nums.size();
    // queries[i] = [li, ri]
    // select subset of indices in range [li, ri] and decrement value by 1
    // Return true if possible to transform nums into a Zero Array

    // Take a DIFFERENCE ARRAY:
    vector<int> differenceArray(n + 1, 0);
    for (auto it : queries)
    {
        int start = it[0];
        int end = it[1];
        // mark start of range by +1
        differenceArray[start] += 1;
        // mark end of range by -1
        differenceArray[end + 1] -= 1;
        // to get prefix sum indices of numbers in range [start, end] to be decremented by 1
    }
    vector<int> prefixSum(n, 0);
    prefixSum[0] = differenceArray[0];
    for (int i = 1; i < n; i++)
    {
        prefixSum[i] = prefixSum[i - 1] + differenceArray[i];
    }
    // check if all 0 after subtraction:
    for (int i = 0; i < n; i++)
    {
        if (nums[i] > prefixSum[i])
        {
            // Not enough decrement operations
            return false;
        }
    }
    return true;
}

int main()
{
    vector<int> nums = {1, 0, 1};
    vector<vector<int>> queries = {{0, 2}};
    cout << "\nbrute_force possible to transform nums into a Zero Array= " << brute_force(nums, queries);
    cout << "\npossible to transform nums into a Zero Array= " << isZeroArray(nums, queries);

    return 0;
}